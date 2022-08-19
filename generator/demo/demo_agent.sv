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
** Filename     : demo_agent.sv
** Phone Number :                                                           **
** Discription  :                                                           **
*****************************************************************************/
`ifndef __DEMO_AGENT_SV__
`define __DEMO_AGENT_SV__

`include "demo_dec.sv"
`include "demo_interface.sv"
`include "demo_driver.sv"
`include "demo_monitor.sv"
`include "demo_sequencer.sv"

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
class demo_agent extends uvm_agent;
    int        inst_id;
    demo_driver    drv;
    demo_monitor   mon;
    demo_sequencer sqr;

    `uvm_component_utils_begin(demo_agent)
    `uvm_component_utils_end

    extern function new(string name="demo_agent", uvm_component parent=null);
    extern function void build_phase(uvm_phase phase);
    extern function void connect_phase(uvm_phase phase);
endclass

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function demo_agent::new(string name="demo_agent", uvm_component parent=null);
    super.new(name, parent);
endfunction

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function void demo_agent::build_phase(uvm_phase phase);
    if (is_active == UVM_ACTIVE) begin
	drv = demo_driver::type_id::create($sformatf("demo_driver_%0d", inst_id), this);
	sqr = demo_sequencer::type_id::create($sformatf("demo_sequencer_%0d", inst_id), this);
        drv.inst_id = inst_id;
    end
    mon = demo_monitor::type_id::create($sformatf("demo_monitor_%0d", inst_id), this);
    mon.inst_id = inst_id;
endfunction

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
function void demo_agent::connect_phase(uvm_phase phase);
    super.connect_phase(phase);

    if (is_active == UVM_ACTIVE) begin
	drv.seq_item_port.connect(sqr.seq_item_export);
    end
endfunction

`endif
