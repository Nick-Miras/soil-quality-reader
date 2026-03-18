#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <stdio.h>
#include <unity.h>
#include "model.h"
#include "scaler.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_model_with_scaler(void) {
    // Simulated input values based on typical crop parameters
    // Format: [moisture, Temperature, Humidity] or similar 4 features
    // Output: [0.0, 1.0] for class 1, [1.0, 0.0] for class 0, etc.
    // double raw_input[4] = {1.0, 42.0, 13.0, 91.0}; // Example input values - class 0
    // double raw_input[4] = {3.0, 31.0, 24.0, 58.0}; // Example input values - class 0
    // double raw_input[4] = {2.0, 21.0, 33.0, 64.0}; // Example input values - class 1
    double raw_input[4] = {1.0, 56.0, 28.0, 71.0}; // Example input values - class 1
    double model_output[2];

    // Run the model scoring
    score(raw_input, model_output);

    // Check if outputs are populated and find the predicted class
    double max_val = -1000000.0;
    int predicted_class = -1; // error case
    for (int i = 0; i < 2; i++) {
        if (model_output[i] > max_val) {
            max_val = model_output[i];
            predicted_class = i;
        }
    }

    // Log the predicted class
    char message[32];
    snprintf(message, sizeof(message), "Predicted class: %d", predicted_class);
    TEST_MESSAGE(message);
    
    // The prediction should be bounded between 0 and 1.
    TEST_ASSERT_TRUE(predicted_class >= 0 && predicted_class < 2);
}

#if defined(ARDUINO)
void setup() {
    delay(2000);
    UNITY_BEGIN();
    RUN_TEST(test_model_with_scaler);
    UNITY_END();
}

void loop() {
    // nothing to be done here.
}
#endif

#if !defined(ARDUINO)
int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_model_with_scaler);
    UNITY_END();
    return 0;
}
#endif
