#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_start", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_done", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_idle", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_ready", 1, hls_out, -1, "", "", 1),
	Port_Property("input_V_address0", 14, hls_out, 0, "ap_memory", "mem_address", 1),
	Port_Property("input_V_ce0", 1, hls_out, 0, "ap_memory", "mem_ce", 1),
	Port_Property("input_V_q0", 16, hls_in, 0, "ap_memory", "mem_dout", 1),
	Port_Property("output_V_address0", 12, hls_out, 1, "ap_memory", "mem_address", 1),
	Port_Property("output_V_ce0", 1, hls_out, 1, "ap_memory", "mem_ce", 1),
	Port_Property("output_V_we0", 1, hls_out, 1, "ap_memory", "mem_we", 1),
	Port_Property("output_V_d0", 16, hls_out, 1, "ap_memory", "mem_din", 1),
	Port_Property("output_V_q0", 16, hls_in, 1, "ap_memory", "mem_dout", 1),
	Port_Property("weights_V_address0", 26, hls_out, 2, "ap_memory", "mem_address", 1),
	Port_Property("weights_V_ce0", 1, hls_out, 2, "ap_memory", "mem_ce", 1),
	Port_Property("weights_V_q0", 16, hls_in, 2, "ap_memory", "mem_dout", 1),
	Port_Property("bias_V_address0", 12, hls_out, 3, "ap_memory", "mem_address", 1),
	Port_Property("bias_V_ce0", 1, hls_out, 3, "ap_memory", "mem_ce", 1),
	Port_Property("bias_V_q0", 16, hls_in, 3, "ap_memory", "mem_dout", 1),
};
const char* HLS_Design_Meta::dut_name = "fullyConnected";
