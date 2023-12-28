#ifndef __LED_H__
#define __LED_H__

#include "GPIO.hpp"

class CBlink_Led : public CGpio_Output {
protected:
    uint32_t s_led_state;

public:
    CBlink_Led(gpio_num_t gpio_num, uint32_t s_led_state = 1)
        : CGpio_Output(gpio_num)
        , s_led_state(s_led_state)
    {
    }

    template <typename R, typename P>
    uint32_t blink(std::chrono::duration<R, P> delay)
    {
        set_level(s_led_state);
        std::this_thread::sleep_for(delay);

        s_led_state = !s_led_state;
        return !s_led_state;
    }

    uint32_t get_state() const
    {
        return s_led_state;
    }
};

#endif
