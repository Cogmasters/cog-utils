# COG-UTILS

General purpose utility functions aimed at portability, used by [Concord](https://github.com/Cogmasters/concord).

## API

### File operation

* `cog_load_whole_file_fp()` - Load file contents into a string (provide a `FILE*`)
* `cog_load_whole_file()` - Load file contents into a string

### Time

* `cog_timezone()` - Get your local timezone (difference between UTC and local time in seconds)
* `cog_sleep_ms()` - Sleep for milliseconds amount
* `cog_sleep_us()` - Sleep for microseconds amount
* `cog_timestamp_ms()` - Get the current timestamp in milliseconds
* `cog_timestamp_us()` - Get the current timestamp in microseconds

### Conversion

* `cog_iso8601_to_unix_ms()` - Convert a iso8601 string to unix timestamp (milliseconds)
* `cog_unix_ms_to_iso8601()` - Convert a unix timestamp (milliseconds) to a iso8601 string
* `cog_strtou64()` - Convert a numerical string to `uint64_t`
* `cog_u64tostr()` - Convert `uint64_t` to a numerical string

### Wrappers

* `cog_strndup()` - analogous to strndup()
* `cog_asprintf()` - analogous to asprintf()

## Other info

This software is distributed under [MIT license](www.opensource.org/licenses/mit-license.php),
so feel free to integrate it in your commercial products.
