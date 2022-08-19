target := simv
.PHONY : all clean run

all : ${target}

SRC_CONTEXT

${target} : ${SRCS}
	vcs -full64 -sverilog -${UVM_HOME}/src/dpi/uvm_dpi.cc \
	    -CFLAGS -DVCS -ntb_opts uvm +incdir+${UVM_HOME}/src \
	    ${UVM_HOME}/src/uvm_pkg.sv ${SRCS} ${FILELIST}

clean :
	\rm -rf simv* csrc vc_hdrs.h ucli.key

run :
	./simv
