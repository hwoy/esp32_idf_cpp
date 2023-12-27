#ifndef __LED_H__
#define __LED_H__

#include <driver/gpio.h>

#include <chrono>
#include <thread>

class CLed {
protected:
    const gpio_num_t gpio_num;

public:
    constexpr CLed(gpio_num_t gpio_num);

    constexpr gpio_num_t get_gpio_num() const;
};

constexpr CLed::CLed(gpio_num_t gpio_num)
    : gpio_num(gpio_num)
{
}

constexpr gpio_num_t CLed::get_gpio_num() const
{
    return gpio_num;
}

class CBlink_Led {
protected:
    const CLed led;
    uint8_t s_led_state;

    void blink_action_state_led(void);

public:
    CBlink_Led(CLed led);
    CBlink_Led(gpio_num_t gpio_num);

    template <typename R, typename P>
    void blink(std::chrono::duration<R, P> delay);

    const CLed& get_led() const;
};

CBlink_Led::CBlink_Led(CLed led)
    : led(led)
    , s_led_state(0)
{
    gpio_reset_pin(led.get_gpio_num());
    gpio_set_direction(led.get_gpio_num(), GPIO_MODE_OUTPUT);
}

CBlink_Led::CBlink_Led(gpio_num_t gpio_num)
    : CBlink_Led(CLed(gpio_num))
{
}

void CBlink_Led::blink_action_state_led(void)
{
    gpio_set_level(led.get_gpio_num(), s_led_state);
    s_led_state = !s_led_state;
}

template <typename R, typename P>
void CBlink_Led::blink(std::chrono::duration<R, P> delay)
{
    blink_action_state_led();
    std::this_thread::sleep_for(delay);
	blink_action_state_led();
}

const CLed& CBlink_Led::get_led() const
{
    return led;
}

#endif
