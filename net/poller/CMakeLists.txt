set(poller_SRCS
    DefaultPoller.cc
    PollPoller.cc
    EPollPoller.cc
)

set(HEADERS
    ../include/net/poller/EPollPoller.h
    ../include/net/poller/PollPoller.h
)

add_library(mymuduo_net_poller ${poller_SRCS})
target_link_libraries(mymuduo_net_poller mymuduo_net)

install(TARGETS mymuduo_net_poller DESTINATION lib)

install(FILES ${HEADERS} DESTINATION include/mymuduo/net/poller) 