/**
 * @file lv_sw.h
 *
 */

#ifndef LV_SW_H
#define LV_SW_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../lv_conf_internal.h"

#if LV_USE_SW != 0

/*Testing of dependencies*/
#if LV_USE_SLIDER == 0
#error "lv_sw: lv_slider is required. Enable it in lv_conf.h (LV_USE_SLIDER  1)"
#endif

#include "../lv_core/lv_obj.h"
#include "lv_slider.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
/*Data of switch*/
typedef struct
{
    lv_slider_ext_t slider; /*Ext. of ancestor*/
    /*New data for this type */
    uint8_t state   :1; /*The current state*/
} lv_sw_ext_t;

/**
 * Switch parts.
 */
enum {
    LV_SW_PART_BG, /**< Switch background. */
    LV_SW_PART_INDIC, /**< Switch fill area. */
    LV_SW_PART_KNOB, /**< Switch knob (when off). */
};

typedef uint8_t lv_sw_part_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a switch objects
 * @param par pointer to an object, it will be the parent of the new switch
 * @param copy pointer to a switch object, if not NULL then the new object will be copied from it
 * @return pointer to the created switch
 */
lv_obj_t * lv_sw_create(lv_obj_t * par, const lv_obj_t * copy);

/*=====================
 * Setter functions
 *====================*/

/**
 * Turn ON the switch
 * @param sw pointer to a switch object
 * @param anim LV_ANIM_ON: set the value with an animation; LV_ANIM_OFF: change the value immediately
 */
void lv_sw_on(lv_obj_t * sw, lv_anim_enable_t anim);

/**
 * Turn OFF the switch
 * @param sw pointer to a switch object
 * @param anim LV_ANIM_ON: set the value with an animation; LV_ANIM_OFF: change the value immediately
 */
void lv_sw_off(lv_obj_t * sw, lv_anim_enable_t anim);

/**
 * Toggle the position of the switch
 * @param sw pointer to a switch object
 * @param anim LV_ANIM_ON: set the value with an animation; LV_ANIM_OFF: change the value immediately
 * @return resulting state of the switch.
 */
bool lv_sw_toggle(lv_obj_t * sw, lv_anim_enable_t anim);

/**
 * Set an image to display on the knob of the switch.
 * @param sw pointer to a switch object
 * @param img_src pointer to an `lv_img_dsc_t` variable or a path to an image
 *        (not an `lv_img` object)
 */
void lv_sw_set_knob_img(lv_obj_t * sw, const void * img_src);

/**
 * Set an image to display on the knob of the switch when it's in ON state
 * @param sw pointer to a switch object
 * @param img_src pointer to an `lv_img_dsc_t` variable or a path to an image
 *        (not an `lv_img` object)
 */
void lv_sw_set_knob_on_img(lv_obj_t * sw, const void * img_src);

/**
 * Set the animation time of the switch
 * @param sw pointer to a  switch object
 * @param anim_time animation time
 * @return style pointer to a style
 */
static inline void lv_sw_set_anim_time(lv_obj_t * sw, uint16_t anim_time)
{
    lv_bar_set_anim_time(sw, anim_time);
}

/*=====================
 * Getter functions
 *====================*/

/**
 * Get the state of a switch
 * @param sw pointer to a switch object
 * @return false: OFF; true: ON
 */
static inline bool lv_sw_get_state(const lv_obj_t * sw)
{
    lv_sw_ext_t * ext = (lv_sw_ext_t *)lv_obj_get_ext_attr(sw);
    return ext->state ? true : false;
}
/**
 * Get an image to display on the knob of the switch when it's in OFF state
 * @param sw pointer to a switch object
 * @return the image source: pointer to an `lv_img_dsc_t` variable or a path to an image
 *         (not an `lv_img` object)
 */
const void * lv_slider_get_knob_off_img(lv_obj_t * sw, const void * img_src);

/**
 * Get an image to display on the knob of the switch when it's in ON state
 * @param sw pointer to a switch object
 * @return the image source: pointer to an `lv_img_dsc_t` variable or a path to an image
 *         (not an `lv_img` object)
 */
const void * lv_slider_get_knob_on_img(lv_obj_t * sw, const void * img_src);
/**
 * Get the animation time of the switch
 * @param sw pointer to a  switch object
 * @return style pointer to a style
 */
static inline uint16_t lv_sw_get_anim_time(const lv_obj_t * sw)
{
    return lv_bar_get_anim_time(sw);
}

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_SW*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_SW_H*/
