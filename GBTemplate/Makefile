# If you move this project you can change the directory 
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

# Compiler
LCC = $(mkfile_dir)deps/gbdk/bin/lcc.exe

#The Target Binary Program
TARGET := $(notdir $(CURDIR))

# Read debug flag
ifeq ($(DEBUG),1)
	DIST=debug
else
	DIST=release
endif

# The Directories, Source, Includes, Objects and Resources
SRCDIR := src
TARGETDIR := bin/$(DIST)
BUILDDIR := $(TARGETDIR)/obj
SRCEXT := c
OBJEXT := o


# DO NOT EDIT BELOW

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Default Make
all: directories $(TARGET)

#Remake
remake: cleaner all

#Make the Directories
directories:
	mkdir -p $(TARGETDIR)
	mkdir -p $(BUILDDIR)

#Clean only Objecst
clean:
	$(RM) -rf $(BUILDDIR)

#Full Clean, Objects and Binaries
cleaner: clean
	@$(RM) -rf $(TARGETDIR)

#Pull in dependency info for *existing* .o files
#-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Link
$(TARGET): $(OBJECTS)
	$(LCC) $(LCCFLAGS) -o $(TARGETDIR)/$(TARGET).gb $(OBJECTS)

#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(LCC) $(LCCFLAGS) -c -o $@ $<
#	@$(LCC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
#	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
#	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
#	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
#	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

#Non-File Targets
.PHONY: all remake clean cleaner resources