/*************************************************************
**                         _ooOoo_                          **
**                        o8888888o                         **
**                        88" . "88                         **
**                        (| -_- |)                         **
**                         O\ = /O                          **
**                     ____/`---'\____                      **
**                   .   ' \\| |// `.                       **
**                    / \\||| : |||// \                     **
**                  / _||||| -:- |||||- \                   **
**                    | | \\\ - /// | |                     **
**                  | \_| ''\---/'' | |                     **
**                   \ .-\__ `-` ___/-. /                   **
**                ___`. .' /--.--\ `. . __                  **
**             ."" '< `.____<|>_/___.' >'"".                **
**            | | : `- \`.;` _ /`;.`/ - ` : | |             **
**              \ \ `-. \_ __\ /__ _/ .-` / /               **
**      ======`-.____`-.___\_____/___.-`____.-'======       **
**                         `=---='                          **
**                                                          **
**      .............................................       **
**             Buddha bless me, No bug forever              **
**                                                          **
**************************************************************
** Author       : generator                                 **
** Email        : zhuhw@ihep.ac.cn/zhwren0211@whu.edu.cn    **
** Last modified: TIME_CONTEXT                       **
** Filename     : demo_sequencer.sv
** Discription  :                                           **
*************************************************************/
`ifndef __DEMO_SEQUENCER_SV__
`define __DEMO_SEQUENCER_SV__

`include "demo_xaction.sv"

class demo_sequencer extends uvm_sequencer#(demo_xaction);
    `uvm_component_utils_begin(demo_sequencer)
    `uvm_component_utils_end

    extern function new(string name="demo_sequencer", uvm_component parent=null);
endclass

/*************************************************************
** Time        : TIME_CONTEXT                        **
** Author      : generator                                  **
** Description : Create                                     **
*************************************************************/
function demo_sequencer::new(string name="demo_sequencer", uvm_component parent=null);
    super.new(name, parent);
endfunction

`endif
