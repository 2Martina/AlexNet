// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.3
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="main,hls_ip_2018_3,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xczu9eg-ffvb1156-2-i,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=2.911750,HLS_SYN_LAT=3719907,HLS_SYN_TPT=none,HLS_SYN_MEM=334,HLS_SYN_DSP=0,HLS_SYN_FF=424,HLS_SYN_LUT=965,HLS_VERSION=2018_3}" *)

module main (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        ap_return
);

parameter    ap_ST_fsm_state1 = 2'd1;
parameter    ap_ST_fsm_state2 = 2'd2;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [31:0] ap_return;

reg ap_done;
reg ap_idle;
reg ap_ready;

(* fsm_encoding = "none" *) reg   [1:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [15:0] convolutionOutput_V_q0;
wire    grp_maxPooling_fu_20_ap_start;
wire    grp_maxPooling_fu_20_ap_done;
wire    grp_maxPooling_fu_20_ap_idle;
wire    grp_maxPooling_fu_20_ap_ready;
wire   [18:0] grp_maxPooling_fu_20_input_V_address0;
wire    grp_maxPooling_fu_20_input_V_ce0;
wire   [16:0] grp_maxPooling_fu_20_output_V_address0;
wire    grp_maxPooling_fu_20_output_V_ce0;
wire    grp_maxPooling_fu_20_output_V_we0;
wire   [15:0] grp_maxPooling_fu_20_output_V_d0;
reg    grp_maxPooling_fu_20_ap_start_reg;
wire    ap_CS_fsm_state2;
reg   [1:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 2'd1;
#0 grp_maxPooling_fu_20_ap_start_reg = 1'b0;
end

main_convolutionOcud #(
    .DataWidth( 16 ),
    .AddressRange( 290400 ),
    .AddressWidth( 19 ))
convolutionOutput_V_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(grp_maxPooling_fu_20_input_V_address0),
    .ce0(grp_maxPooling_fu_20_input_V_ce0),
    .q0(convolutionOutput_V_q0)
);

main_poolingResuldEe #(
    .DataWidth( 16 ),
    .AddressRange( 69984 ),
    .AddressWidth( 17 ))
poolingResult_V_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(grp_maxPooling_fu_20_output_V_address0),
    .ce0(grp_maxPooling_fu_20_output_V_ce0),
    .we0(grp_maxPooling_fu_20_output_V_we0),
    .d0(grp_maxPooling_fu_20_output_V_d0)
);

maxPooling grp_maxPooling_fu_20(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_maxPooling_fu_20_ap_start),
    .ap_done(grp_maxPooling_fu_20_ap_done),
    .ap_idle(grp_maxPooling_fu_20_ap_idle),
    .ap_ready(grp_maxPooling_fu_20_ap_ready),
    .input_V_address0(grp_maxPooling_fu_20_input_V_address0),
    .input_V_ce0(grp_maxPooling_fu_20_input_V_ce0),
    .input_V_q0(convolutionOutput_V_q0),
    .output_V_address0(grp_maxPooling_fu_20_output_V_address0),
    .output_V_ce0(grp_maxPooling_fu_20_output_V_ce0),
    .output_V_we0(grp_maxPooling_fu_20_output_V_we0),
    .output_V_d0(grp_maxPooling_fu_20_output_V_d0)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_maxPooling_fu_20_ap_start_reg <= 1'b0;
    end else begin
        if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
            grp_maxPooling_fu_20_ap_start_reg <= 1'b1;
        end else if ((grp_maxPooling_fu_20_ap_ready == 1'b1)) begin
            grp_maxPooling_fu_20_ap_start_reg <= 1'b0;
        end
    end
end

always @ (*) begin
    if (((grp_maxPooling_fu_20_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((grp_maxPooling_fu_20_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((grp_maxPooling_fu_20_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_return = 32'd0;

assign grp_maxPooling_fu_20_ap_start = grp_maxPooling_fu_20_ap_start_reg;

endmodule //main