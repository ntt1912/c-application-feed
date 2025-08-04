# Include the main rules for building OpenWrt packages
include $(TOPDIR)/rules.mk

# Define package metadata
PKG_NAME:=python_checking         # Name of the package
PKG_VERSION:=1.0                  # Version of the package
PKG_RELEASE:=1                    # Release number

# Include package helper macros
include $(INCLUDE_DIR)/package.mk

# Define the package and its properties
# SECTION: Section in menuconfig
# CATEGORY: Category in menuconfig
# TITLE: Short description/title
# DEPENDS: Dependency on python3
define Package/python_checking
  SECTION:=utils                  
  CATEGORY:=Utilities             
  TITLE:=Python Version Checker   
  DEPENDS:=+python3               
endef

# Provide a longer description for the package
define Package/python_checking/description
  A simple tool to check Python 3 version and log it to /tmp/python_ver.log
endef

# Prepare build: copy all source files from ./src to the build directory
define Build/Prepare
    $(CP) ./src/* $(PKG_BUILD_DIR)/
endef

# Compile the source code in the build directory using the target compiler and flags
define Build/Compile
    $(MAKE) -C $(PKG_BUILD_DIR) \
        CC="$(TARGET_CC)" \
        CFLAGS="$(TARGET_CFLAGS)"
endef

# Install the compiled binary to the target filesystem under /usr/bin
define Package/python_checking/install
    $(INSTALL_DIR) $(1)/usr/bin
    $(INSTALL_BIN) $(PKG_BUILD_DIR)/check_python $(1)/usr/bin/
endef

# Evaluate and build the package using the defined rules above
$(eval $(call BuildPackage,python_checking))