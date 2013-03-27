LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := sqlite3.c bbfs.c exif.c
LOCAL_C_INCLUDES := system/extras/fuse/include system/extras/libexif
LOCAL_C_FLAGS := -D _FILE_OFFSET_BITS=64
LOCAL_SHARED_LIBRARIES := libc libdl libexif_local libfuse
LOCAL_MODULE := imgfs
include $(BUILD_EXECUTABLE)
