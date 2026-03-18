#if defined(ARDUINO)
#include <Arduino.h>
#endif
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
    FLOAT_T raw_input[3] = {25.0, 70.0, 6.5}; 
    FLOAT_T output[3];
    
    // Scale the inputs
    scaler(output, raw_input);

    // Convert to double for the model
    double scaled_input[3];
    for (int i = 0; i < 3; i++) {
        scaled_input[i] = (double)output[i];
    }

    double model_output[2];
    
    // Run the model scoring
    score(scaled_input, model_output);

    // Check if outputs are populated and find the predicted class
    double max_val = -1000000.0;
    int predicted_class = -1;
    for (int i = 0; i < 2; i++) {
        if (model_output[i] > max_val) {
            max_val = model_output[i];
            predicted_class = i;
        }
    }
    
    // The prediction should be bounded between 0 and 2
    TEST_ASSERT_TRUE(predicted_class >= 0 && predicted_class <= 2);
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
