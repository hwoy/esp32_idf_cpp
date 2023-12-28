# esp32_idf_cpp

esp32_idf_cpp is C++ for esp32 idf.

## Sample

```cpp

#include <chrono>

#include "esp32.hpp"

extern "C" [[noreturn]] void app_main(void)
{
    using namespace std::chrono_literals;

    auto led = esp32::CBlink_Led(GPIO_NUM_2);

    while (true) {
        led.state_blink(1s);
    }
}


```


## Contact me

- Web: <https://github.com/hwoy>
- Email: <mailto:bosskillerz@gmail.com>
- Facebook: <https://www.facebook.com/watt.duean>
