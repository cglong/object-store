/**
 * @file media.h
 * @brief Main interface to an image and video store
 */

#ifndef __MEDIA_H__
#define __MEDIA_H__

/**
 * @brief A GPS coordinate.
 * @var   latitude The latitude of the location
 * @var   longitude The longitude of the location
 */
typedef struct
{
	double *latitude;
	double *longitude;
} coordinate;

/**
 * @brief A media file
 * @var   name The filename
 */
typedef struct
{
	coordinate *location;
	const char *name;
} media;

/**
 * @brief An image file
 */
typedef media image;

/**
 * @brief A video file
 */
typedef media video;

/**
 * @brief     Add an item to the store
 * @param[in] item The item to add to the store
 * @return    Zero if successful, nonzero otherwise
 */
int addMedia(media *item);

/**
 * @brief     Remove an item from the store
 * @param[in] item The item to remove from the store
 * @return    Zero if successful, nonzero otherwise
 */
int removeMedia(media *item);

/**
 * @brief      Retrieve a set of items taken at a particular location
 * @param[in]  location The location to query. If one or both values are null, it is treated as a wildcard.
 * @param[out] result A set of pointers to the found media
 * @return     The number of items found
 */
int mediaAt(coordinate location, media[] result);

/**
 * @brief      Retrieve a set of items with a particular name
 * @param[in]  name The name for which to query
 * @param[out] result A set of pointers to the found media
 * @return     The number of items found
 */
int mediaNamed(const char *name, media[] result);

#endif
