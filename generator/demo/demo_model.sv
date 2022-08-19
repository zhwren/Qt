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
** Filename     : demo_model.sv
** Phone Number :                                                           **
** Discription  :                                                           **
*****************************************************************************/
`ifndef __DEMO_MODEL_SV__
`define __DEMO_MODEL_SV__

class demo_model extends uvm_component;
    `uvm_component_utils_begin(demo_model)
    `uvm_component_utils_end

    extern function new(string name="demo_model", uvm_component parent=null);
    extern virtual task main_phase(uvm_phase phase);
endclass

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function demo_model::new(string name="demo_model", uvm_component parent=null);
    super.new(name, parent);
endfunction

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
task demo_model::main_phase(uvm_phase phase);
    phase.raise_objection(this);
    repeat(100) begin
        #1;
        `uvm_info(get_name(), "Hello World!", UVM_LOW);
    end
    phase.drop_objection(this);
endtask

`endif
