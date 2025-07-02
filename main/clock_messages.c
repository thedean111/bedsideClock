#include "clock_messages.h"

static char **messages = NULL;
static int count = 0;
static int *idx = NULL;
static int cursor = 0;

void SetupFS() {
    esp_vfs_littlefs_conf_t conf = {
        .base_path = "/littlefs",
        .partition_label = "littlefs",
        .format_if_mount_failed = true,
        .dont_mount = false,
    };

    // Use settings defined above to initialize and mount LittleFS filesystem.
    // Note: esp_vfs_littlefs_register is an all-in-one convenience function.
    esp_err_t ret = esp_vfs_littlefs_register(&conf);

    if (ret != ESP_OK)
    {
            if (ret == ESP_FAIL)
            {
                    ESP_LOGE(TAG, "Failed to mount or format filesystem");
            }
            else if (ret == ESP_ERR_NOT_FOUND)
            {
                    ESP_LOGE(TAG, "Failed to find LittleFS partition");
            }
            else
            {
                    ESP_LOGE(TAG, "Failed to initialize LittleFS (%s)", esp_err_to_name(ret));
            }
            return;
    }

    size_t total = 0, used = 0;
    ret = esp_littlefs_info(conf.partition_label, &total, &used);
    if (ret != ESP_OK)
    {
            ESP_LOGE(TAG, "Failed to get LittleFS partition information (%s)", esp_err_to_name(ret));
    }
    else
    {
            ESP_LOGI(TAG, "Partition size: total: %d, used: %d", total, used);
    }
}

esp_err_t InitMessages() {
    // Open the file
    FILE *f = fopen(MSG_PATH, "r");
    if (!f)
        return ESP_FAIL;

    // Read each line in the file
    char line[LINE_BUF_SIZE];
    while (fgets(line, sizeof(line), f)) {
        count++;
    }

    if (count == 0) {
        return ESP_ERR_NOT_FOUND;
    }

    // Allocate memory for all the messages
    messages = malloc(sizeof(char*) * count);
    idx = malloc(sizeof(int) * count);
    if (!messages || !idx) {
        fclose(f);
        return ESP_ERR_NO_MEM;
    }

    // Now, reread the file and store the messages
    rewind(f);
    int i = 0;
    while (i < count && fgets(line, sizeof(line), f)) {
        size_t len = strlen(line);
        if (len && line[len-1] == '\n') {
            line[--len] = '\0';
        }
        messages[i] = malloc(len+1);
        strcpy(messages[i], line);
        idx[i] = i;
        i++;
    }
    fclose(f);

    // Shuffle all the messages
    for (int j = count - 1; j > 0; j--) {
        int k = esp_random() % (j + 1);
        int tmp = idx[j];
        idx[j] = idx[k];
        idx[k] = tmp;
    }
    cursor = 0;

    return ESP_OK;
}

const char *GetMessage() {
    if (!messages) {
        return NULL;
    }

    // When all messages are exhausted, reshuffle the indexes
    if (cursor >= count) {
        for (int j = count - 1; j > 0; j--) {
            int k = esp_random() % (j + 1);
            int tmp = idx[j];
            idx[j] = idx[k];
            idx[k] = tmp;
        }
        cursor = 0;
    }

    return messages[idx[cursor++]];
}