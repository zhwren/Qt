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
** Filename     : demo_sequence.sv
** Discription  :                                           **
*************************************************************/
`ifndef __DEMO_SEQUENCE_SV__
`define __DEMO_SEQUENCE_SV__

`include "demo_xaction.sv"

class demo_sequence extends uvm_sequence #(demo_xaction);
    `uvm_object_utils_begin(demo_sequence)
    `uvm_object_utils_end

    extern function new(string name="demo_sequence");
endclass

/*************************************************************
** Time        : TIME_CONTEXT                        **
** Author      : generator                                  **
** Description : Create                                     **
*************************************************************/
function demo_sequence::new(string name="demo_sequence");
    super.new(name);
endfunction

`endif
