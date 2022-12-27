#ifndef LIBXDF_MMTYPES_H
#define LIBXDF_MMTYPES_H

#include <cstdint>

namespace dd::libxdf::types::enums {
    enum class HeaderFlags {
        UNKNOWN = 0x1
    };

    enum class ConstantFlags {
        //TODO Constant flags
        FIRST = 0xc,
        SECOND = 0xd
    };

    enum class OutputType: uint8_t {
        NONE = 0x0,
        FLOATING_POINT = 0x1,
        INTEGER = 0x2,
        HEX_DIGITS = 0x3,
        ASCII_STRING = 0x4
    };

    enum class DataType: uint8_t {
        EXTERNALLY_DEFINED = 0x0,
        NONE,
        UNDEFINED,
        UNKNOWN,
        ACCELERATION,
        ACTUAL_AIR_FUEL_RATIO,
        ACTUAL_LAMBDA,
        AIR_FUEL_RATIO,
        AIR_FLOW,
        AVERAGE_FUEL_ECONOMY,
        BAROMETRIC_PRESSURE,
        BATTERY_VOLTAGE,
        BOOST,
        CALIBRATION_VERSION,
        COOLANT_TEMP,
        ENGINE_SPEED,
        EXHAUST_TEMP,
        EXHAUST_TEMP_LEFT_BANK,
        EXHAUST_TEMP_RIGHT_BANK,
        FUEL_ECONOMY,
        FUEL_PRESSURE,
        FUEL_PUMP_VOLTAGE,
        FUEL_TRIM,
        FUEL_TRIM_COURSE,
        FUEL_TRIM_FINE,
        FUEL_TRIM_LONG,
        FUEL_TRIM_SHORT,
        IDLE_AIR_CONTROL_POSITION,
        IDLE_SPEED,
        INJECTOR_BASE_PULSE_WIDTH,
        INJECTOR_FINAL_PULSE_WIDTH,
        INJECTOR_PULSE_WIDTH,
        INSTANT_FUEL_ECONOMY,
        INTAKE_AIR_TEMP,
        KNOCK_COUNT,
        KNOCK_RETARD,
        LAMBDA,
        LOAD,
        MANIFOLD_AIR_PRESSURE,
        MANIFOLD_AIR_TEMP,
        MASS_AIR_FLOW,
        MULTIPLIER,
        NV_RATIO,
        OIL_PRESSURE,
        OIL_TEMP,
        OXYGEN_SENSOR,
        OXYGEN_SENSOR_LEFT,
        OXYGEN_SENSOR_RIGHT,
        OXYGEN_SENSOR_WIDEBAND,
        OXYGEN_SENSOR_WIDEBAND_LEFT,
        OXYGEN_SENSOR_WIDEBAND_RIGHT,
        POWER_STEERING_PRESSURE,
        POWER_STEERING_TEMP,
        SPARK_ANGLE,
        SPARK_ANGLE_REFERENCE,
        SPARK_ANGLE_TDC,
        SPARK_TRIM,
        SPARK_TRIM_COURSE,
        SPARK_TRIM_FINE,
        SPARK_TRIM_LONG,
        SPARK_TRIM_SHORT,
        STARTUP_COOLANT_TEMP,
        TARGET_AIR_FUEL_RATIO,
        TARGET_LAMBDA,
        THROTTLE_POSITION,
        TRANSMISSION_GEAR,
        VACUUM,
        VEHICLE_SPEED,
        WHEEL_SPEED,
        WHEEL_SPEED_FRONT_LEFT,
        WHEEL_SPEED_FRONT_RIGHT,
        WHEEL_SPEED_REAR_LEFT,
        WHEEL_SPEED_REAR_RIGHT
    };

    enum class UnitType: uint8_t {
        EXTERNALLY_DEFINED = 0x0,
        NONE,
        UNDEFINED,
        UNKNOWN,
        AIR_FUEL_RATIO,
        AMPS,
        BAR,
        CENTIMETERS,
        CENTIPOSE,
        COUNT,
        CUBIC_CENTIMETERS,
        CUBIC_FEET,
        CUBIC_INCHES,
        CUBIC_METERS,
        CUBIC_MILLIMETERS,
        CUBIC_YARDS,
        DAYS,
        DECIBELS,
        DEGREES_CELCIUS,
        DEGREES_FAHRENHEIT,
        DEGREES_KELVIN,
        DUTY_CYCLE,
        FEET_PER_SECOND,
        FLUID_OUNCES,
        FOOT_POUNDS,
        GALLONS,
        GRAMS,
        GRAMS_PER_SECOND,
        HERTZ,
        HORSE_POWER,
        HOURS,
        INCHES_OF_MERCURY,
        INCHES_OF_WATER,
        INCH_POUNDS,
        JOULES,
        KILOGRAMS,
        KILOGRAMS_PER_HOUR,
        KILO_HERTZ,
        KILOMETERS,
        KILOMETERS_PER_HOUR,
        KILOMETERS_PER_LITRE,
        KILO_PASCAL,
        KILO_WATTS,
        KNOTS,
        LAMBDA,
        LITERS,
        LITERS_PER_100_KM,
        LOAD_VALUE_LVL16,
        LOAD_VALUE_LVL8,
        MEGA_HERTZ,
        MEGA_WATTS,
        METERS,
        METERS_PER_SECOND,
        METERS_PER_SECOND_PER_SECOND,
        MICROSECONDS,
        MILES,
        MILES_PER_GALLON,
        MILES_PER_HOUR,
        MILLIAMPS,
        MILLIBAR,
        MILLIGRAMS,
        MILLIMETERS,
        MILLIOHMS,
        MILLISECONDS,
        MILLIVOLTS,
        MILLIWATTS,
        MINUTES,
        MM_OF_MERCURY,
        MM_OF_WATER,
        MULTIPLIER,
        NAUTICAL_MILE,
        NEWTON_CENTIMETERS,
        NEWTON_METERS,
        NEWTONS,
        OHMS,
        OUNCES,
        PASCAL_SECOND,
        PERCENT,
        PINTS,
        POISE,
        POUNDS,
        POUNDS_PER_HOUR,
        POUNDS_PER_SQUARE_INCH,
        PULSE_WIDTH,
        QUARTS,
        REVOLUTIONS_PER_MINUTE,
        ROTATIONAL_DEGREES,
        SECONDS,
        SQUARE_CENTIMETERS,
        SQUARE_FEET,
        SQUARE_INCHES,
        SQUARE_KILOMETERS,
        SQUARE_METERS,
        SQUARE_MILES,
        SQUARE_MILLIMETERS,
        SQUARE_YARDS,
        STEPS,
        TONNE,
        TONS,
        VOLTS,
        WATTS,
        YEARS
    };

    enum class CalculationMethod {
        SUM = 0,
        TWOS_COMPLIANT = 1,
        ONES_COMPLIANT = 2,
        UNKNOWN = 0xff
    };

    enum class RegionType: uint64_t {
        //TODO: All the region types
        DEFAULT = 0xFFFFFFFF
    };

    enum class RegionFlag: uint32_t {
        //TODO: All the region flags
        DEFAULT = 0x0
    };
} // types

#endif //LIBXDF_MMTYPES_H
