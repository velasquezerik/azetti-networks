set(SOURCES
	contact.cpp
)
add_library(contact SHARED ${SOURCES})

set(SOURCES
	user.cpp
)
add_library(user SHARED ${SOURCES})

set(SOURCES
	group.cpp
)
add_library(group SHARED ${SOURCES})


