# python_checking – OpenWrt Feed

Simple OpenWrt package to check and log Python 3 version using a C app.

## Features

- Uses `system()` or `popen()` to call `python3 --version`
- Outputs to terminal and logs to `/tmp/python_ver.log`
- Handles missing Python gracefully

## Structure

```
c-application-feed/
├── Makefile                      # Feed declaration
└── python_checking/
    ├── Makefile                  # OpenWrt package Makefile
    └── src/
        ├── Makefile              # C build
        └── check_python.c        # Source
```

## Usage in OpenWrt Build

1. Add to `feeds.conf.default`:
   ```text
   src-git python_checking_feed https://github.com/ntt1912/c-application-feed.git;feature/python-version-check
   ```

2. Update feeds:
   ```bash
   ./scripts/feeds update -a && ./scripts/feeds install -a
   ```

3. Enable in `.config`:
   ```text
   CONFIG_PACKAGE_python_checking=y
   CONFIG_PACKAGE_python3=y
   ```

4. Build:
   ```bash
   make defconfig && make -j$(nproc)
   ```

## Runtime Example

```sh
check_python
cat /tmp/python_ver.log
```

---

**Maintainer**: [@ntt1912](https://github.com/ntt1912)  
**Tag**: `v1.0-python-check`
