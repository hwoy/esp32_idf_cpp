#ifndef __LED_H__
#define __LED_H__

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

public:
    CBlink_Led(CLed led, uint8_t s_led_state = 1);
    CBlink_Led(gpio_num_t gpio_num, uint8_t s_led_state = 1);

    template <typename R, typename P>
    uint8_t state_blink(std::chrono::duration<R, P> delay);

    const CLed& get_led() const;
    uint8_t get_led_state() const;
};

CBlink_Led::CBlink_Led(CLed led, uint8_t s_led_state)
    : led(led)
    , s_led_state(s_led_state)
{
    gpio_reset_pin(led.get_gpio_num());
    gpio_set_direction(led.get_gpio_num(), GPIO_MODE_OUTPUT);
}

CBlink_Led::CBlink_Led(gpio_num_t gpio_num, uint8_t s_led_state)
    : CBlink_Led(CLed(gpio_num), s_led_state)
{
}

template <typename R, typename P>
uint8_t CBlink_Led::state_blink(std::chrono::duration<R, P> delay)
{
    gpio_set_level(led.get_gpio_num(), s_led_state);
    std::this_thread::sleep_for(delay);

    s_led_state = !s_led_state;
    return !s_led_state;
}

const CLed& CBlink_Led::get_led() const
{
    return led;
}

uint8_t CBlink_Led::get_led_state() const
{
    return s_led_state;
}

#endif
