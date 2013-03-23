LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := bbfs.c exif.c
LOCAL_C_INCLUDES := system/extras/fuse/include
LOCAL_C_FLAGS := -D _FILE_OFFSET_BITS=64
LOCAL_SHARED_LIBRARIES := libc libexif libfuse
LOCAL_MODULE := imgfs
include $(BUILD_EXECUTABLE)
