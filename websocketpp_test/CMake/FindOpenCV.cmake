cmake_minimum_required(VERSION 3.20) #FetchContent

find_package(OpenCV CONFIG QUIET) # Search for installed build

include(CPM)
# Fetch OpenCV using CPM
if (NOT OpenCV_FOUND)
  CPMAddPackage(
    NAME OpenCV
    GITHUB_REPOSITORY opencv/opencv
    GIT_TAG "4.10.0"
    OPTIONS
    "BUILD_LIST core,imgcodecs,highgui,imgproc,features2d"  # List only needed modules
    "BUILD_OpenCV_python3 OFF"  # Disable Python support
    )
    # Make sure OpenCV was successfully added

  if(NOT OpenCV_ADDED)
    message(FATAL_ERROR "HERE: Failed to fetch OpenCV. OpenCV is required for this project.")
  endif()
endif()
