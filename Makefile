### Environment constants 

ARCH ?=
CROSS_COMPILE ?=
export

### general build targets

all:
	$(MAKE) all -e -C data_structure
	$(MAKE) all -e -C algorithm

clean:
	$(MAKE) clean -e -C data_structure
	$(MAKE) clean -e -C algorithm

### EOF
