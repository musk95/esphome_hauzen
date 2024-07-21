#include "esphome.h"

class HauzenClimate public : Component, public Climate {
    public: void setup() override {
        climate::ClimateTraits traits() {
            auto traits = climate::ClimateTraits();
            traits.set_supports_current_temperature(false);
            traits.set_supports_two_point_target_temperature(false);

            traits.set_supported_modes({
                climate::CLIMATE_MODE_OFF,
                climate::CLIMATE_MODE_HEAT,
                climate::CLIMATE_MODE_DRY,
                climate::CLIMATE_MODE_COOL,
                climate::CLIMATE_MODE_FAN_ONLY,
                //Adding this leads to esphome data not showing on Home Assistant somehow, hence skipping. Others please try and let me know
            });

            traits.set_supported_fan_modes({
            climate::CLIMATE_FAN_AUTO,
            climate::CLIMATE_FAN_LOW,
            climate::CLIMATE_FAN_MEDIUM,
            climate::CLIMATE_FAN_HIGH,
            });

            traits.set_supported_swing_modes({
            climate::CLIMATE_SWING_OFF,
            climate::CLIMATE_SWING_VERTICAL,
            });

            traits.set_visual_min_temperature(16);
            traits.set_visual_max_temperature(30);
            traits.set_visual_temperature_step(1);
            return traits;
        }
    }
}