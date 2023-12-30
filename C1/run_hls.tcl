
##############################################
# Project settings

# Create project
open_project	-reset matrix_mult_prj

# Add source files and test bench
add_files			C1.cpp
add_files			C1.h
add_files -tb	C1_tb.cpp
# Specify the top-level function for synthesis
set_top		convolution3D		

###########################
# Solution settings

# Create solution1
open_solution -reset solution1

# Specify a Xilinx device and clock period
# - Do not specify a clock uncertainty (margin)
# - Let the  margin to default to 12.5% of clock period
set_part  {xczu9eg-ffvb1156-2-i}
create_clock -period 5
#set_clock_uncertainty 1.25

# Simulate the C code 
csim_design

# Do not perform any other steps
# - The basic project will be opened in the GUI 
exit

