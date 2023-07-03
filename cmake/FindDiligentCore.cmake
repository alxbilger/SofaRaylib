include_guard()

set(SOFA_DILIGENTCORE_SOURCE_DIR CACHE PATH "DiligentCore source directory")

if (EXISTS ${SOFA_DILIGENTCORE_SOURCE_DIR})
    if (NOT EXISTS ${SOFA_DILIGENTCORE_SOURCE_DIR}/Graphics/GraphicsEngine/interface/APIInfo.h)
        message(SEND_ERROR "Cannot find Graphics/GraphicsEngine/interface/APIInfo.h in ${SOFA_DILIGENTCORE_SOURCE_DIR}")
    else()
        set(Diligent_FOUND TRUE)
    endif()
else()
    message(FATAL_ERROR "DiligentCore source directory is mandatory. Please provide the variable SOFA_DILIGENTCORE_SOURCE_DIR.")
endif()
