-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2018.3
-- Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity fullyConnected is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    input_V_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
    input_V_ce0 : OUT STD_LOGIC;
    input_V_q0 : IN STD_LOGIC_VECTOR (15 downto 0);
    output_V_address0 : OUT STD_LOGIC_VECTOR (11 downto 0);
    output_V_ce0 : OUT STD_LOGIC;
    output_V_we0 : OUT STD_LOGIC;
    output_V_d0 : OUT STD_LOGIC_VECTOR (15 downto 0);
    output_V_q0 : IN STD_LOGIC_VECTOR (15 downto 0);
    weights_V_address0 : OUT STD_LOGIC_VECTOR (25 downto 0);
    weights_V_ce0 : OUT STD_LOGIC;
    weights_V_q0 : IN STD_LOGIC_VECTOR (15 downto 0);
    bias_V_address0 : OUT STD_LOGIC_VECTOR (11 downto 0);
    bias_V_ce0 : OUT STD_LOGIC;
    bias_V_q0 : IN STD_LOGIC_VECTOR (15 downto 0) );
end;


architecture behav of fullyConnected is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "fullyConnected,hls_ip_2018_3,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=1,HLS_INPUT_PART=xc7z020clg484-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.513500,HLS_SYN_LAT=226512898,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=1,HLS_SYN_FF=205,HLS_SYN_LUT=369,HLS_VERSION=2018_3}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (10 downto 0) := "00000000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (10 downto 0) := "00000000010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (10 downto 0) := "00000000100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (10 downto 0) := "00000001000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (10 downto 0) := "00000010000";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (10 downto 0) := "00000100000";
    constant ap_ST_fsm_state7 : STD_LOGIC_VECTOR (10 downto 0) := "00001000000";
    constant ap_ST_fsm_state8 : STD_LOGIC_VECTOR (10 downto 0) := "00010000000";
    constant ap_ST_fsm_state9 : STD_LOGIC_VECTOR (10 downto 0) := "00100000000";
    constant ap_ST_fsm_state10 : STD_LOGIC_VECTOR (10 downto 0) := "01000000000";
    constant ap_ST_fsm_state11 : STD_LOGIC_VECTOR (10 downto 0) := "10000000000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv32_9 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001001";
    constant ap_const_lv13_0 : STD_LOGIC_VECTOR (12 downto 0) := "0000000000000";
    constant ap_const_lv32_A : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001010";
    constant ap_const_lv32_8 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001000";
    constant ap_const_lv14_0 : STD_LOGIC_VECTOR (13 downto 0) := "00000000000000";
    constant ap_const_lv16_0 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000000";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv13_1000 : STD_LOGIC_VECTOR (12 downto 0) := "1000000000000";
    constant ap_const_lv13_1 : STD_LOGIC_VECTOR (12 downto 0) := "0000000000001";
    constant ap_const_lv14_2400 : STD_LOGIC_VECTOR (13 downto 0) := "10010000000000";
    constant ap_const_lv14_1 : STD_LOGIC_VECTOR (13 downto 0) := "00000000000001";
    constant ap_const_lv12_0 : STD_LOGIC_VECTOR (11 downto 0) := "000000000000";
    constant ap_const_lv9_0 : STD_LOGIC_VECTOR (8 downto 0) := "000000000";
    constant ap_const_lv32_18 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000011000";
    constant ap_const_lv15_0 : STD_LOGIC_VECTOR (14 downto 0) := "000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (10 downto 0) := "00000000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal i_1_fu_156_p2 : STD_LOGIC_VECTOR (12 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal i_2_fu_173_p2 : STD_LOGIC_VECTOR (12 downto 0);
    signal i_2_reg_332 : STD_LOGIC_VECTOR (12 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal tmp_2_fu_179_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_2_reg_337 : STD_LOGIC_VECTOR (63 downto 0);
    signal exitcond2_fu_167_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_2_cast_fu_184_p1 : STD_LOGIC_VECTOR (26 downto 0);
    signal tmp_2_cast_reg_342 : STD_LOGIC_VECTOR (26 downto 0);
    signal output_V_addr_1_reg_347 : STD_LOGIC_VECTOR (11 downto 0);
    signal j_1_fu_194_p2 : STD_LOGIC_VECTOR (13 downto 0);
    signal j_1_reg_355 : STD_LOGIC_VECTOR (13 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal exitcond_fu_188_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_state6 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state6 : signal is "none";
    signal input_V_load_reg_375 : STD_LOGIC_VECTOR (15 downto 0);
    signal ap_CS_fsm_state7 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state7 : signal is "none";
    signal weights_V_load_reg_380 : STD_LOGIC_VECTOR (15 downto 0);
    signal p_Val2_2_reg_385 : STD_LOGIC_VECTOR (15 downto 0);
    signal ap_CS_fsm_state8 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state8 : signal is "none";
    signal tmp_5_fu_233_p1 : STD_LOGIC_VECTOR (24 downto 0);
    signal tmp_5_reg_390 : STD_LOGIC_VECTOR (24 downto 0);
    signal tmp_10_reg_395 : STD_LOGIC_VECTOR (0 downto 0);
    signal ret_V_2_s_fu_301_p3 : STD_LOGIC_VECTOR (14 downto 0);
    signal ret_V_2_s_reg_400 : STD_LOGIC_VECTOR (14 downto 0);
    signal ap_CS_fsm_state10 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state10 : signal is "none";
    signal i_reg_116 : STD_LOGIC_VECTOR (12 downto 0);
    signal exitcond1_fu_150_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal i1_reg_127 : STD_LOGIC_VECTOR (12 downto 0);
    signal ap_CS_fsm_state11 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state11 : signal is "none";
    signal j_reg_138 : STD_LOGIC_VECTOR (13 downto 0);
    signal ap_CS_fsm_state9 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state9 : signal is "none";
    signal tmp_fu_162_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_9_cast1_fu_217_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_7_fu_222_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal p_Val2_6_fu_268_p2 : STD_LOGIC_VECTOR (15 downto 0);
    signal ret_V_2_cast_6_fu_309_p1 : STD_LOGIC_VECTOR (15 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal tmp_3_fu_200_p3 : STD_LOGIC_VECTOR (25 downto 0);
    signal tmp_5_cast_fu_208_p1 : STD_LOGIC_VECTOR (26 downto 0);
    signal tmp_9_fu_212_p2 : STD_LOGIC_VECTOR (26 downto 0);
    signal r_V_2_fu_313_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal lhs_V_fu_243_p3 : STD_LOGIC_VECTOR (24 downto 0);
    signal ret_V_fu_250_p2 : STD_LOGIC_VECTOR (24 downto 0);
    signal p_Val2_5_fu_255_p4 : STD_LOGIC_VECTOR (15 downto 0);
    signal tmp_9_cast_fu_265_p1 : STD_LOGIC_VECTOR (15 downto 0);
    signal tmp_4_fu_279_p1 : STD_LOGIC_VECTOR (14 downto 0);
    signal tmp_1_fu_275_p1 : STD_LOGIC_VECTOR (14 downto 0);
    signal ret_V_2_fu_283_p2 : STD_LOGIC_VECTOR (15 downto 0);
    signal tmp_6_fu_295_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ret_V_2_cast_fu_289_p2 : STD_LOGIC_VECTOR (14 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (10 downto 0);

    component fullyConnected_mubkb IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        din0 : IN STD_LOGIC_VECTOR (15 downto 0);
        din1 : IN STD_LOGIC_VECTOR (15 downto 0);
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;



begin
    fullyConnected_mubkb_U1 : component fullyConnected_mubkb
    generic map (
        ID => 1,
        NUM_STAGE => 1,
        din0_WIDTH => 16,
        din1_WIDTH => 16,
        dout_WIDTH => 32)
    port map (
        din0 => input_V_load_reg_375,
        din1 => weights_V_load_reg_380,
        dout => r_V_2_fu_313_p2);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    i1_reg_127_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond1_fu_150_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                i1_reg_127 <= ap_const_lv13_0;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state11)) then 
                i1_reg_127 <= i_2_reg_332;
            end if; 
        end if;
    end process;

    i_reg_116_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond1_fu_150_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                i_reg_116 <= i_1_fu_156_p2;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                i_reg_116 <= ap_const_lv13_0;
            end if; 
        end if;
    end process;

    j_reg_138_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond2_fu_167_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                j_reg_138 <= ap_const_lv14_0;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state9)) then 
                j_reg_138 <= j_1_reg_355;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                i_2_reg_332 <= i_2_fu_173_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state7)) then
                input_V_load_reg_375 <= input_V_q0;
                weights_V_load_reg_380 <= weights_V_q0;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state4)) then
                j_1_reg_355 <= j_1_fu_194_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond2_fu_167_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                output_V_addr_1_reg_347 <= tmp_2_fu_179_p1(12 - 1 downto 0);
                    tmp_2_cast_reg_342(12 downto 0) <= tmp_2_cast_fu_184_p1(12 downto 0);
                    tmp_2_reg_337(12 downto 0) <= tmp_2_fu_179_p1(12 downto 0);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state8)) then
                p_Val2_2_reg_385 <= output_V_q0;
                tmp_10_reg_395 <= r_V_2_fu_313_p2(8 downto 8);
                tmp_5_reg_390 <= tmp_5_fu_233_p1;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state10)) then
                ret_V_2_s_reg_400 <= ret_V_2_s_fu_301_p3;
            end if;
        end if;
    end process;
    tmp_2_reg_337(63 downto 13) <= "000000000000000000000000000000000000000000000000000";
    tmp_2_cast_reg_342(26 downto 13) <= "00000000000000";

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, ap_CS_fsm_state3, exitcond2_fu_167_p2, ap_CS_fsm_state4, exitcond_fu_188_p2, exitcond1_fu_150_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((exitcond1_fu_150_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state3;
                else
                    ap_NS_fsm <= ap_ST_fsm_state2;
                end if;
            when ap_ST_fsm_state3 => 
                if (((exitcond2_fu_167_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state4;
                end if;
            when ap_ST_fsm_state4 => 
                if (((exitcond_fu_188_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then
                    ap_NS_fsm <= ap_ST_fsm_state10;
                else
                    ap_NS_fsm <= ap_ST_fsm_state5;
                end if;
            when ap_ST_fsm_state5 => 
                ap_NS_fsm <= ap_ST_fsm_state6;
            when ap_ST_fsm_state6 => 
                ap_NS_fsm <= ap_ST_fsm_state7;
            when ap_ST_fsm_state7 => 
                ap_NS_fsm <= ap_ST_fsm_state8;
            when ap_ST_fsm_state8 => 
                ap_NS_fsm <= ap_ST_fsm_state9;
            when ap_ST_fsm_state9 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state10 => 
                ap_NS_fsm <= ap_ST_fsm_state11;
            when ap_ST_fsm_state11 => 
                ap_NS_fsm <= ap_ST_fsm_state3;
            when others =>  
                ap_NS_fsm <= "XXXXXXXXXXX";
        end case;
    end process;
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state10 <= ap_CS_fsm(9);
    ap_CS_fsm_state11 <= ap_CS_fsm(10);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);
    ap_CS_fsm_state6 <= ap_CS_fsm(5);
    ap_CS_fsm_state7 <= ap_CS_fsm(6);
    ap_CS_fsm_state8 <= ap_CS_fsm(7);
    ap_CS_fsm_state9 <= ap_CS_fsm(8);

    ap_done_assign_proc : process(ap_CS_fsm_state3, exitcond2_fu_167_p2)
    begin
        if (((exitcond2_fu_167_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state3, exitcond2_fu_167_p2)
    begin
        if (((exitcond2_fu_167_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    bias_V_address0 <= tmp_2_reg_337(12 - 1 downto 0);

    bias_V_ce0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            bias_V_ce0 <= ap_const_logic_1;
        else 
            bias_V_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    exitcond1_fu_150_p2 <= "1" when (i_reg_116 = ap_const_lv13_1000) else "0";
    exitcond2_fu_167_p2 <= "1" when (i1_reg_127 = ap_const_lv13_1000) else "0";
    exitcond_fu_188_p2 <= "1" when (j_reg_138 = ap_const_lv14_2400) else "0";
    i_1_fu_156_p2 <= std_logic_vector(unsigned(i_reg_116) + unsigned(ap_const_lv13_1));
    i_2_fu_173_p2 <= std_logic_vector(unsigned(i1_reg_127) + unsigned(ap_const_lv13_1));
    input_V_address0 <= tmp_7_fu_222_p1(14 - 1 downto 0);

    input_V_ce0_assign_proc : process(ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            input_V_ce0 <= ap_const_logic_1;
        else 
            input_V_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    j_1_fu_194_p2 <= std_logic_vector(unsigned(j_reg_138) + unsigned(ap_const_lv14_1));
    lhs_V_fu_243_p3 <= (p_Val2_2_reg_385 & ap_const_lv9_0);

    output_V_address0_assign_proc : process(ap_CS_fsm_state2, output_V_addr_1_reg_347, ap_CS_fsm_state4, ap_CS_fsm_state7, ap_CS_fsm_state11, ap_CS_fsm_state9, tmp_fu_162_p1)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state9) or (ap_const_logic_1 = ap_CS_fsm_state11) or (ap_const_logic_1 = ap_CS_fsm_state7))) then 
            output_V_address0 <= output_V_addr_1_reg_347;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            output_V_address0 <= tmp_fu_162_p1(12 - 1 downto 0);
        else 
            output_V_address0 <= "XXXXXXXXXXXX";
        end if; 
    end process;


    output_V_ce0_assign_proc : process(ap_CS_fsm_state2, ap_CS_fsm_state4, ap_CS_fsm_state7, ap_CS_fsm_state11, ap_CS_fsm_state9)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state2) or (ap_const_logic_1 = ap_CS_fsm_state9) or (ap_const_logic_1 = ap_CS_fsm_state11) or (ap_const_logic_1 = ap_CS_fsm_state7))) then 
            output_V_ce0 <= ap_const_logic_1;
        else 
            output_V_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    output_V_d0_assign_proc : process(ap_CS_fsm_state2, ap_CS_fsm_state11, ap_CS_fsm_state9, p_Val2_6_fu_268_p2, ret_V_2_cast_6_fu_309_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state11)) then 
            output_V_d0 <= ret_V_2_cast_6_fu_309_p1;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state9)) then 
            output_V_d0 <= p_Val2_6_fu_268_p2;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            output_V_d0 <= ap_const_lv16_0;
        else 
            output_V_d0 <= "XXXXXXXXXXXXXXXX";
        end if; 
    end process;


    output_V_we0_assign_proc : process(ap_CS_fsm_state2, exitcond1_fu_150_p2, ap_CS_fsm_state11, ap_CS_fsm_state9)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state9) or (ap_const_logic_1 = ap_CS_fsm_state11) or ((exitcond1_fu_150_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            output_V_we0 <= ap_const_logic_1;
        else 
            output_V_we0 <= ap_const_logic_0;
        end if; 
    end process;

    p_Val2_5_fu_255_p4 <= ret_V_fu_250_p2(24 downto 9);
    p_Val2_6_fu_268_p2 <= std_logic_vector(unsigned(p_Val2_5_fu_255_p4) + unsigned(tmp_9_cast_fu_265_p1));
    ret_V_2_cast_6_fu_309_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(ret_V_2_s_reg_400),16));
    ret_V_2_cast_fu_289_p2 <= std_logic_vector(unsigned(tmp_4_fu_279_p1) + unsigned(tmp_1_fu_275_p1));
    ret_V_2_fu_283_p2 <= std_logic_vector(unsigned(output_V_q0) + unsigned(bias_V_q0));
    ret_V_2_s_fu_301_p3 <= 
        ret_V_2_cast_fu_289_p2 when (tmp_6_fu_295_p2(0) = '1') else 
        ap_const_lv15_0;
    ret_V_fu_250_p2 <= std_logic_vector(unsigned(tmp_5_reg_390) + unsigned(lhs_V_fu_243_p3));
    tmp_1_fu_275_p1 <= output_V_q0(15 - 1 downto 0);
    tmp_2_cast_fu_184_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i1_reg_127),27));
    tmp_2_fu_179_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i1_reg_127),64));
    tmp_3_fu_200_p3 <= (j_reg_138 & ap_const_lv12_0);
    tmp_4_fu_279_p1 <= bias_V_q0(15 - 1 downto 0);
    tmp_5_cast_fu_208_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_3_fu_200_p3),27));
    tmp_5_fu_233_p1 <= r_V_2_fu_313_p2(25 - 1 downto 0);
    tmp_6_fu_295_p2 <= "1" when (signed(ret_V_2_fu_283_p2) > signed(ap_const_lv16_0)) else "0";
    tmp_7_fu_222_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(j_reg_138),64));
    tmp_9_cast1_fu_217_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_9_fu_212_p2),64));
    tmp_9_cast_fu_265_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_10_reg_395),16));
    tmp_9_fu_212_p2 <= std_logic_vector(unsigned(tmp_5_cast_fu_208_p1) + unsigned(tmp_2_cast_reg_342));
    tmp_fu_162_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_reg_116),64));
    weights_V_address0 <= tmp_9_cast1_fu_217_p1(26 - 1 downto 0);

    weights_V_ce0_assign_proc : process(ap_CS_fsm_state4, ap_CS_fsm_state6, ap_CS_fsm_state7, ap_CS_fsm_state5)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state5) or (ap_const_logic_1 = ap_CS_fsm_state7) or (ap_const_logic_1 = ap_CS_fsm_state6))) then 
            weights_V_ce0 <= ap_const_logic_1;
        else 
            weights_V_ce0 <= ap_const_logic_0;
        end if; 
    end process;

end behav;
