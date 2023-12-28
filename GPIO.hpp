#ifndef __GPIO_H__
#define __GPIO_H__

class CGpio_Base {
protected:
    const gpio_num_t gpio_num;

public:
    constexpr CGpio_Base(gpio_num_t gpio_num)
        : gpio_num(gpio_num)
    {
    }

    constexpr gpio_num_t get_gpio_num() const
    {
        return gpio_num;
    }
};

class CGpio_Input_Base : public CGpio_Base {
public:
    constexpr CGpio_Input_Base(gpio_num_t gpio_num)
        : CGpio_Base(gpio_num)
    {
    }

    uint32_t get_level()
    {
        return gpio_get_level(gpio_num);
    }
};

class CGpio_Output_Base : public CGpio_Base {
public:
    constexpr CGpio_Output_Base(gpio_num_t gpio_num)
        : CGpio_Base(gpio_num)
    {
    }
    void set_level(uint32_t level)
    {
        gpio_set_level(gpio_num, level);
    }
};

class CGpio_Input : public CGpio_Input_Base {
public:
    CGpio_Input(gpio_num_t gpio_num)
        : CGpio_Input_Base(gpio_num)
    {
        gpio_reset_pin(gpio_num);
        gpio_set_direction(gpio_num, GPIO_MODE_INPUT);
    }
};

class CGpio_Output : public CGpio_Output_Base {
public:
    CGpio_Output(gpio_num_t gpio_num)
        : CGpio_Output_Base(gpio_num)
    {
        gpio_reset_pin(gpio_num);
        gpio_set_direction(gpio_num, GPIO_MODE_OUTPUT);
    }
};

class CGpio_InPutOutput : public CGpio_Input_Base,
                          public CGpio_Output_Base {
public:
    CGpio_InPutOutput(gpio_num_t gpio_num)
        : CGpio_Input_Base(gpio_num)
        , CGpio_Output_Base(gpio_num)
    {
        gpio_reset_pin(gpio_num);
        gpio_set_direction(gpio_num, GPIO_MODE_INPUT_OUTPUT);
    }
};

#endif
