#ifndef STATISTICS_H
#define STATISTICS_H

/// @brief Finds maximum value in array
/// @param data Array of measurements
/// @param size Number of elements
/// @return Maximum value
extern float getMaximum(const float data[], int size);

/// @brief Finds minimum value in array
/// @param data Array of measurements
/// @param size Number of elements
/// @return Minimum value
extern float getMinimum(const float data[], int size);

/// @brief Calculates mean (average) of values
/// @param data Array of measurements
/// @param size Number of elements
/// @return Mean value
extern float getMean(const float data[], int size);

/// @brief Calculates variance of values
/// @param data Array of measurements
/// @param size Number of elements
/// @return Variance
extern float getVariance(const float data[], int size);

/// @brief Calculates median of values
/// @param data Array of measurements
/// @param size Number of elements
/// @return Median value
extern float getMedian(float data[], int size);

#endif