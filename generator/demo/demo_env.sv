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
** Filename     : demo_env.sv
** Phone Number :                                                           **
** Discription  :                                                           **
*****************************************************************************/
`ifndef __DEMO_ENV_SV__
`define __DEMO_ENV_SV__
ENV_INCLUDE_CONTEXT
`include "demo_model.sv"
`include "demo_env_dec.sv"
import demo_env_dec::*;

class demo_env extends uvm_env;
    ENV_DECLARE_CONTEXT
    demo_model model;
    `uvm_component_utils_begin(demo_env)
    `uvm_component_utils_end

    extern function new(string name="demo_env", uvm_component parent=null);
    extern virtual function void build_phase(uvm_phase phase);
    extern virtual function void connect_phase(uvm_phase phase);
    extern virtual task reset_phase(uvm_phase phase);
    extern virtual task main_phase(uvm_phase phase);
    extern virtual task shutdown_phase(uvm_phase phase);
endclass

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function demo_env::new(string name="demo_env", uvm_component parent=null);
    super.new(name, parent);
endfunction

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function void demo_env::build_phase(uvm_phase phase);
    super.build_phase(phase);
    model = demo_model::type_id::create("model", this);
    ENV_BUILD_CONTEXT
endfunction

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function void demo_env::connect_phase(uvm_phase phase);
    super.connect_phase(phase);
    //ENV_CONNECT_CONTEXT
endfunction

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
task demo_env::reset_phase(uvm_phase phase);
    super.reset_phase(phase);
    //ENV_RESET_CONTEXT
endtask

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
task demo_env::main_phase(uvm_phase phase);
    super.main_phase(phase);
endtask

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
task demo_env::shutdown_phase(uvm_phase phase);
    super.shutdown_phase(phase);
endtask

`endif
