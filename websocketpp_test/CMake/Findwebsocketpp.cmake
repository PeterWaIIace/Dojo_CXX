# Add websocketpp
CPMAddPackage(
    NAME websocketpp
    GITHUB_REPOSITORY zaphoyd/websocketpp
    GIT_TAG master  # Specify the correct version
    OPTIONS "WEBSOCKETPP_NO_CPP11_LOG=OFF"
)

# Include directories
include_directories(${websocketpp_SOURCE_DIR})