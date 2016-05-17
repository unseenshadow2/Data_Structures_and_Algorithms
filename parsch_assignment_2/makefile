ODIR := obj
CDIR := src
HDIR := inc

SRCS := $(wildcard $(CDIR)/*.cpp)
OBJS := $(SRCS:$(CDIR)/%.cpp=$(ODIR)/%.o)
DEPS := $(OBJS:%.o=%.d)

CPPFLAGS := -I$(HDIR) -MMD -MP
CXXFLAGS := -std=c++11 -Wall -Wno-write-strings -Wno-sign-compare -O2
LDFLAGS  :=
LDLIBS   :=
RUNCMD	 :=

NAME := linked_list

.PHONY: debug release clean run

debug: CPPFLAGS+=-DDEBUG
debug: CXXFLAGS+=-g

release: CPPFLAGS+=-DRELEASE

debug release: $(NAME) run

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJS): $(ODIR)/%.o: $(CDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(OUTPUT_OPTION) $<

clean: ; $(RM) $(NAME) $(OBJS) $(DEPS)

run:
	 $(RUNCMD) ./$(NAME)

-include $(DEPS)
