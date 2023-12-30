// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.3
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _maxPooling_HH_
#define _maxPooling_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "maxPooling_pool_vbkb.h"

namespace ap_rtl {

struct maxPooling : public sc_module {
    // Port declarations 13
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<19> > input_V_address0;
    sc_out< sc_logic > input_V_ce0;
    sc_in< sc_lv<16> > input_V_q0;
    sc_out< sc_lv<17> > output_V_address0;
    sc_out< sc_logic > output_V_ce0;
    sc_out< sc_logic > output_V_we0;
    sc_out< sc_lv<16> > output_V_d0;


    // Module declarations
    maxPooling(sc_module_name name);
    SC_HAS_PROCESS(maxPooling);

    ~maxPooling();

    sc_trace_file* mVcdFile;

    maxPooling_pool_vbkb* pool_values_V_U;
    sc_signal< sc_lv<14> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<12> > next_mul_fu_325_p2;
    sc_signal< sc_lv<12> > next_mul_reg_779;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<7> > c_1_fu_337_p2;
    sc_signal< sc_lv<7> > c_1_reg_787;
    sc_signal< sc_lv<5> > i_1_fu_349_p2;
    sc_signal< sc_lv<5> > i_1_reg_795;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<64> > tmp_3_fu_389_p2;
    sc_signal< sc_lv<64> > tmp_3_reg_800;
    sc_signal< sc_lv<1> > exitcond3_fu_343_p2;
    sc_signal< sc_lv<5> > j_1_fu_401_p2;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<12> > next_mul1_fu_434_p2;
    sc_signal< sc_lv<12> > next_mul1_reg_814;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<13> > next_mul9_fu_440_p2;
    sc_signal< sc_lv<13> > next_mul9_reg_819;
    sc_signal< sc_lv<7> > c_2_fu_452_p2;
    sc_signal< sc_lv<7> > c_2_reg_827;
    sc_signal< sc_lv<5> > i_2_fu_464_p2;
    sc_signal< sc_lv<5> > i_2_reg_835;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<6> > tmp_5_fu_470_p3;
    sc_signal< sc_lv<6> > tmp_5_reg_840;
    sc_signal< sc_lv<1> > exitcond4_fu_458_p2;
    sc_signal< sc_lv<64> > tmp_9_fu_512_p2;
    sc_signal< sc_lv<64> > tmp_9_reg_845;
    sc_signal< sc_lv<5> > j_2_fu_524_p2;
    sc_signal< sc_lv<5> > j_2_reg_854;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<6> > tmp_s_fu_530_p3;
    sc_signal< sc_lv<6> > tmp_s_reg_859;
    sc_signal< sc_lv<1> > exitcond6_fu_518_p2;
    sc_signal< sc_lv<2> > pi_1_fu_548_p2;
    sc_signal< sc_lv<2> > pi_1_reg_867;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_lv<5> > tmp_16_fu_570_p2;
    sc_signal< sc_lv<5> > tmp_16_reg_872;
    sc_signal< sc_lv<1> > exitcond7_fu_542_p2;
    sc_signal< sc_lv<20> > tmp_19_fu_611_p2;
    sc_signal< sc_lv<20> > tmp_19_reg_877;
    sc_signal< sc_lv<2> > pj_1_fu_627_p2;
    sc_signal< sc_lv<2> > pj_1_reg_885;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<5> > tmp_26_fu_637_p2;
    sc_signal< sc_lv<5> > tmp_26_reg_890;
    sc_signal< sc_lv<1> > exitcond_fu_621_p2;
    sc_signal< sc_lv<16> > pool_values_V_q0;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_lv<2> > i_3_fu_671_p2;
    sc_signal< sc_lv<2> > i_3_reg_909;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_lv<5> > tmp_25_fu_693_p2;
    sc_signal< sc_lv<5> > tmp_25_reg_914;
    sc_signal< sc_lv<1> > exitcond3_i_fu_665_p2;
    sc_signal< sc_lv<2> > j_3_fu_732_p2;
    sc_signal< sc_lv<2> > j_3_reg_922;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_lv<1> > exitcond_i_fu_726_p2;
    sc_signal< sc_lv<16> > max_value_V_1_agg_re_fu_758_p3;
    sc_signal< sc_logic > ap_CS_fsm_state14;
    sc_signal< sc_lv<16> > max_value_V_1_agg_re_1_fu_766_p3;
    sc_signal< sc_lv<4> > pool_values_V_address0;
    sc_signal< sc_logic > pool_values_V_ce0;
    sc_signal< sc_logic > pool_values_V_we0;
    sc_signal< sc_lv<7> > c_reg_133;
    sc_signal< sc_lv<12> > phi_mul_reg_144;
    sc_signal< sc_lv<5> > i_reg_156;
    sc_signal< sc_lv<1> > exitcond5_fu_395_p2;
    sc_signal< sc_lv<1> > exitcond1_fu_331_p2;
    sc_signal< sc_lv<5> > j_reg_167;
    sc_signal< sc_lv<7> > c4_reg_178;
    sc_signal< sc_lv<13> > phi_mul8_reg_189;
    sc_signal< sc_lv<12> > phi_mul1_reg_201;
    sc_signal< sc_lv<5> > i5_reg_213;
    sc_signal< sc_lv<1> > exitcond2_fu_446_p2;
    sc_signal< sc_lv<5> > j6_reg_224;
    sc_signal< sc_lv<2> > pi_reg_236;
    sc_signal< sc_lv<2> > pj_reg_247;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<16> > max_value_V_1_reg_258;
    sc_signal< sc_lv<16> > agg_result_V_load4_i_reg_269;
    sc_signal< sc_lv<2> > i_i_reg_279;
    sc_signal< sc_lv<16> > agg_result_V_1_i_reg_290;
    sc_signal< sc_lv<16> > agg_result_V_load_i_reg_302;
    sc_signal< sc_lv<2> > j_i_reg_314;
    sc_signal< sc_lv<64> > tmp_14_fu_425_p3;
    sc_signal< sc_lv<64> > tmp_39_cast_fu_656_p1;
    sc_signal< sc_lv<64> > tmp_38_cast_fu_661_p1;
    sc_signal< sc_lv<64> > tmp_23_fu_717_p3;
    sc_signal< sc_lv<64> > tmp_40_cast_fu_747_p1;
    sc_signal< sc_lv<12> > tmp_3_cast_fu_355_p1;
    sc_signal< sc_lv<12> > tmp_1_fu_359_p2;
    sc_signal< sc_lv<19> > tmp_fu_365_p3;
    sc_signal< sc_lv<17> > tmp_2_fu_377_p3;
    sc_signal< sc_lv<64> > p_shl_fu_373_p1;
    sc_signal< sc_lv<64> > p_shl1_fu_385_p1;
    sc_signal< sc_lv<5> > tmp_10_fu_407_p1;
    sc_signal< sc_lv<59> > tmp_13_fu_416_p4;
    sc_signal< sc_lv<5> > tmp_12_fu_410_p2;
    sc_signal< sc_lv<12> > tmp_6_cast_fu_478_p1;
    sc_signal< sc_lv<12> > tmp_4_fu_482_p2;
    sc_signal< sc_lv<19> > tmp_6_fu_488_p3;
    sc_signal< sc_lv<17> > tmp_8_fu_500_p3;
    sc_signal< sc_lv<64> > p_shl2_fu_496_p1;
    sc_signal< sc_lv<64> > p_shl3_fu_508_p1;
    sc_signal< sc_lv<4> > tmp_15_fu_558_p3;
    sc_signal< sc_lv<5> > p_shl6_cast_fu_566_p1;
    sc_signal< sc_lv<5> > tmp_4_cast_fu_554_p1;
    sc_signal< sc_lv<6> > pi_cast6_fu_538_p1;
    sc_signal< sc_lv<6> > tmp_7_fu_576_p2;
    sc_signal< sc_lv<13> > tmp_9_cast_fu_581_p1;
    sc_signal< sc_lv<13> > tmp_17_fu_585_p2;
    sc_signal< sc_lv<18> > tmp_18_fu_599_p3;
    sc_signal< sc_lv<20> > p_shl4_cast_fu_591_p3;
    sc_signal< sc_lv<20> > p_shl5_cast_fu_607_p1;
    sc_signal< sc_lv<5> > tmp_10_cast_fu_633_p1;
    sc_signal< sc_lv<6> > pj_cast4_fu_617_p1;
    sc_signal< sc_lv<6> > tmp_11_fu_642_p2;
    sc_signal< sc_lv<20> > tmp_12_cast_fu_647_p1;
    sc_signal< sc_lv<20> > tmp_27_fu_651_p2;
    sc_signal< sc_lv<4> > tmp_24_fu_681_p3;
    sc_signal< sc_lv<5> > p_shl7_cast_fu_689_p1;
    sc_signal< sc_lv<5> > tmp_i_cast_fu_677_p1;
    sc_signal< sc_lv<5> > tmp_20_fu_699_p1;
    sc_signal< sc_lv<59> > tmp_22_fu_708_p4;
    sc_signal< sc_lv<5> > tmp_21_fu_702_p2;
    sc_signal< sc_lv<5> > tmp_i_cast_14_fu_738_p1;
    sc_signal< sc_lv<5> > tmp_28_fu_742_p2;
    sc_signal< sc_lv<1> > tmp_13_i_fu_752_p2;
    sc_signal< sc_lv<14> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<14> ap_ST_fsm_state1;
    static const sc_lv<14> ap_ST_fsm_state2;
    static const sc_lv<14> ap_ST_fsm_state3;
    static const sc_lv<14> ap_ST_fsm_state4;
    static const sc_lv<14> ap_ST_fsm_state5;
    static const sc_lv<14> ap_ST_fsm_state6;
    static const sc_lv<14> ap_ST_fsm_state7;
    static const sc_lv<14> ap_ST_fsm_state8;
    static const sc_lv<14> ap_ST_fsm_state9;
    static const sc_lv<14> ap_ST_fsm_state10;
    static const sc_lv<14> ap_ST_fsm_state11;
    static const sc_lv<14> ap_ST_fsm_state12;
    static const sc_lv<14> ap_ST_fsm_state13;
    static const sc_lv<14> ap_ST_fsm_state14;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<7> ap_const_lv7_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<12> ap_const_lv12_0;
    static const sc_lv<5> ap_const_lv5_0;
    static const sc_lv<13> ap_const_lv13_0;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<16> ap_const_lv16_0;
    static const sc_lv<12> ap_const_lv12_1B;
    static const sc_lv<7> ap_const_lv7_60;
    static const sc_lv<7> ap_const_lv7_1;
    static const sc_lv<5> ap_const_lv5_1B;
    static const sc_lv<5> ap_const_lv5_1;
    static const sc_lv<32> ap_const_lv32_3F;
    static const sc_lv<13> ap_const_lv13_37;
    static const sc_lv<2> ap_const_lv2_3;
    static const sc_lv<2> ap_const_lv2_1;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state14();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_CS_fsm_state7();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state9();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_c_1_fu_337_p2();
    void thread_c_2_fu_452_p2();
    void thread_exitcond1_fu_331_p2();
    void thread_exitcond2_fu_446_p2();
    void thread_exitcond3_fu_343_p2();
    void thread_exitcond3_i_fu_665_p2();
    void thread_exitcond4_fu_458_p2();
    void thread_exitcond5_fu_395_p2();
    void thread_exitcond6_fu_518_p2();
    void thread_exitcond7_fu_542_p2();
    void thread_exitcond_fu_621_p2();
    void thread_exitcond_i_fu_726_p2();
    void thread_i_1_fu_349_p2();
    void thread_i_2_fu_464_p2();
    void thread_i_3_fu_671_p2();
    void thread_input_V_address0();
    void thread_input_V_ce0();
    void thread_j_1_fu_401_p2();
    void thread_j_2_fu_524_p2();
    void thread_j_3_fu_732_p2();
    void thread_max_value_V_1_agg_re_1_fu_766_p3();
    void thread_max_value_V_1_agg_re_fu_758_p3();
    void thread_next_mul1_fu_434_p2();
    void thread_next_mul9_fu_440_p2();
    void thread_next_mul_fu_325_p2();
    void thread_output_V_address0();
    void thread_output_V_ce0();
    void thread_output_V_d0();
    void thread_output_V_we0();
    void thread_p_shl1_fu_385_p1();
    void thread_p_shl2_fu_496_p1();
    void thread_p_shl3_fu_508_p1();
    void thread_p_shl4_cast_fu_591_p3();
    void thread_p_shl5_cast_fu_607_p1();
    void thread_p_shl6_cast_fu_566_p1();
    void thread_p_shl7_cast_fu_689_p1();
    void thread_p_shl_fu_373_p1();
    void thread_pi_1_fu_548_p2();
    void thread_pi_cast6_fu_538_p1();
    void thread_pj_1_fu_627_p2();
    void thread_pj_cast4_fu_617_p1();
    void thread_pool_values_V_address0();
    void thread_pool_values_V_ce0();
    void thread_pool_values_V_we0();
    void thread_tmp_10_cast_fu_633_p1();
    void thread_tmp_10_fu_407_p1();
    void thread_tmp_11_fu_642_p2();
    void thread_tmp_12_cast_fu_647_p1();
    void thread_tmp_12_fu_410_p2();
    void thread_tmp_13_fu_416_p4();
    void thread_tmp_13_i_fu_752_p2();
    void thread_tmp_14_fu_425_p3();
    void thread_tmp_15_fu_558_p3();
    void thread_tmp_16_fu_570_p2();
    void thread_tmp_17_fu_585_p2();
    void thread_tmp_18_fu_599_p3();
    void thread_tmp_19_fu_611_p2();
    void thread_tmp_1_fu_359_p2();
    void thread_tmp_20_fu_699_p1();
    void thread_tmp_21_fu_702_p2();
    void thread_tmp_22_fu_708_p4();
    void thread_tmp_23_fu_717_p3();
    void thread_tmp_24_fu_681_p3();
    void thread_tmp_25_fu_693_p2();
    void thread_tmp_26_fu_637_p2();
    void thread_tmp_27_fu_651_p2();
    void thread_tmp_28_fu_742_p2();
    void thread_tmp_2_fu_377_p3();
    void thread_tmp_38_cast_fu_661_p1();
    void thread_tmp_39_cast_fu_656_p1();
    void thread_tmp_3_cast_fu_355_p1();
    void thread_tmp_3_fu_389_p2();
    void thread_tmp_40_cast_fu_747_p1();
    void thread_tmp_4_cast_fu_554_p1();
    void thread_tmp_4_fu_482_p2();
    void thread_tmp_5_fu_470_p3();
    void thread_tmp_6_cast_fu_478_p1();
    void thread_tmp_6_fu_488_p3();
    void thread_tmp_7_fu_576_p2();
    void thread_tmp_8_fu_500_p3();
    void thread_tmp_9_cast_fu_581_p1();
    void thread_tmp_9_fu_512_p2();
    void thread_tmp_fu_365_p3();
    void thread_tmp_i_cast_14_fu_738_p1();
    void thread_tmp_i_cast_fu_677_p1();
    void thread_tmp_s_fu_530_p3();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
