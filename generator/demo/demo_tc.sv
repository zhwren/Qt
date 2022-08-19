/*****************************************************************************
**                                 _ooOoo_                                  **
**                                o8888888o                                 **
**                                88" . "88                                 **
**                                (| -_- |)                                 **
**                                 O\ = /O                                  **
**                             ____/`---'\____                              **
**                           .   ' \\| |// `.                               **
**                            / \\||| : |||// \                             **
**                          / _||||| -:- |||||- \                           **
**                            | | \\\ - /// | |                             **
**                          | \_| ''\---/'' | |                             **
**                           \ .-\__ `-` ___/-. /                           **
**                        ___`. .' /--.--\ `. . __                          **
**                     ."" '< `.____<|>_/___.' >'"".                        **
**                    | | : `- \`.;` _ /`;.`/ - ` : | |                     **
**                      \ \ `-. \_ __\ /__ _/ .-` / /                       **
**              ======`-.____`-.___\_____/___.-`____.-'======               **
**                                 `=---='                                  **
**                                                                          **
**              .............................................               **
**                     Buddha bless me, No bug forever                      **
**                                                                          **
******************************************************************************
** Author       : generator                                                 **
** Email        : zhuhw@ihep.ac.cn/zhwren0211@whu.edu.cn                    **
** Last modified: TIME_CONTEXT                                              **
** Filename     : demo_tc.sv
** Phone Number :                                                           **
** Discription  :                                                           **
*****************************************************************************/
`ifndef __DEMO_TC_SV__
`define __DEMO_TC_SV__

`include "demo_env.sv"

class demo_tc extends uvm_test;
    demo_env  env;

    `uvm_component_utils_begin(demo_tc)
    `uvm_component_utils_end

    extern function new(string name="demo_tc", uvm_component parent=null);
    extern virtual function void build_phase(uvm_phase phase);
endclass

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function demo_tc::new(string name="demo_tc", uvm_component parent=null);
    super.new(name, parent);
endfunction

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function void demo_tc::build_phase(uvm_phase phase);
    super.build_phase(phase);

    env = demo_env::type_id::create("env", this);
endfunction

`endif
