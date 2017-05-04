﻿namespace PH_App
{
    partial class Form_Main_PH_Application
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form_Main_PH_Application));
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea6 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend6 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series6 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle16 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle17 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle18 = new System.Windows.Forms.DataGridViewCellStyle();
            this.phChart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.lb_db_name = new System.Windows.Forms.Label();
            this.lb_buildingselectedShow = new System.Windows.Forms.Label();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.id = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.name = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.groupBox4ttt = new System.Windows.Forms.GroupBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.labelline1 = new System.Windows.Forms.Label();
            this.lb_DP = new System.Windows.Forms.Label();
            this.label25 = new System.Windows.Forms.Label();
            this.lb_RH = new System.Windows.Forms.Label();
            this.label24 = new System.Windows.Forms.Label();
            this.lb_humidity_ratio = new System.Windows.Forms.Label();
            this.label23 = new System.Windows.Forms.Label();
            this.lb_dbt = new System.Windows.Forms.Label();
            this.label21 = new System.Windows.Forms.Label();
            this.gb_showstatus = new System.Windows.Forms.GroupBox();
            this.lb_realtimeshow = new System.Windows.Forms.Label();
            this.lb_modeshow = new System.Windows.Forms.Label();
            this.lb_vertical_line2 = new System.Windows.Forms.Label();
            this.lb_for_line_vertical1 = new System.Windows.Forms.Label();
            this.lb_numberOfHandler = new System.Windows.Forms.Label();
            this.lb_number_of_chart_label = new System.Windows.Forms.Label();
            this.lb_device_status = new System.Windows.Forms.Label();
            this.lb_devicestatusshow = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.printToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveConfigurationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadConfigurationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.optionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.simulationMode = new System.Windows.Forms.ToolStripMenuItem();
            this.exportDataToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.historyPlotToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.trashBoxToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.gridViewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.excelExportToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpPsychometricChartToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.CMSinsertNode = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.quickNodeInsertToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.disconnectLineToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clearChartToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editNodeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteNodeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.disconnectLineFromAToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.nodeAToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.nodeBToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lb_unit_chosen_display = new System.Windows.Forms.Label();
            this.pb_lock_unlock = new System.Windows.Forms.PictureBox();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            ((System.ComponentModel.ISupportInitialize)(this.phChart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.groupBox4ttt.SuspendLayout();
            this.gb_showstatus.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.CMSinsertNode.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb_lock_unlock)).BeginInit();
            this.SuspendLayout();
            // 
            // phChart
            // 
            resources.ApplyResources(this.phChart, "phChart");
            chartArea6.AxisX.Title = "Enthalpy h[KJ/kg]";
            chartArea6.AxisY.Title = "Pressure P[MPa]";
            chartArea6.Name = "ChartArea1";
            this.phChart.ChartAreas.Add(chartArea6);
            legend6.Enabled = false;
            legend6.Name = "Legend1";
            this.phChart.Legends.Add(legend6);
            this.phChart.Name = "phChart";
            series6.ChartArea = "ChartArea1";
            series6.Legend = "Legend1";
            series6.Name = "Series1";
            this.phChart.Series.Add(series6);
            this.phChart.MouseDown += new System.Windows.Forms.MouseEventHandler(this.phChart_MouseDown);
            // 
            // lb_db_name
            // 
            resources.ApplyResources(this.lb_db_name, "lb_db_name");
            this.lb_db_name.Name = "lb_db_name";
            // 
            // lb_buildingselectedShow
            // 
            resources.ApplyResources(this.lb_buildingselectedShow, "lb_buildingselectedShow");
            this.lb_buildingselectedShow.Name = "lb_buildingselectedShow";
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.BackgroundColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle16.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle16.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle16.Font = new System.Drawing.Font("Arial", 8.25F);
            dataGridViewCellStyle16.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle16.SelectionBackColor = System.Drawing.SystemColors.ControlDark;
            dataGridViewCellStyle16.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle16.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridView1.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle16;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.id,
            this.name});
            resources.ApplyResources(this.dataGridView1, "dataGridView1");
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersVisible = false;
            this.dataGridView1.TabStop = false;
            this.dataGridView1.CellBeginEdit += new System.Windows.Forms.DataGridViewCellCancelEventHandler(this.dataGridView1_CellBeginEdit);
            this.dataGridView1.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellClick);
            this.dataGridView1.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellDoubleClick);
            this.dataGridView1.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellEndEdit);
            this.dataGridView1.CellEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellEnter);
            this.dataGridView1.CellMouseClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dataGridView1_CellMouseClick);
            this.dataGridView1.SelectionChanged += new System.EventHandler(this.dataGridView1_SelectionChanged);
            // 
            // id
            // 
            dataGridViewCellStyle17.BackColor = System.Drawing.Color.White;
            dataGridViewCellStyle17.SelectionBackColor = System.Drawing.Color.SteelBlue;
            dataGridViewCellStyle17.SelectionForeColor = System.Drawing.Color.WhiteSmoke;
            this.id.DefaultCellStyle = dataGridViewCellStyle17;
            resources.ApplyResources(this.id, "id");
            this.id.Name = "id";
            this.id.ReadOnly = true;
            this.id.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.NotSortable;
            // 
            // name
            // 
            dataGridViewCellStyle18.SelectionBackColor = System.Drawing.Color.SteelBlue;
            dataGridViewCellStyle18.SelectionForeColor = System.Drawing.Color.White;
            this.name.DefaultCellStyle = dataGridViewCellStyle18;
            resources.ApplyResources(this.name, "name");
            this.name.Name = "name";
            this.name.ReadOnly = true;
            this.name.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.NotSortable;
            // 
            // groupBox4ttt
            // 
            resources.ApplyResources(this.groupBox4ttt, "groupBox4ttt");
            this.groupBox4ttt.Controls.Add(this.label5);
            this.groupBox4ttt.Controls.Add(this.label4);
            this.groupBox4ttt.Controls.Add(this.label3);
            this.groupBox4ttt.Controls.Add(this.labelline1);
            this.groupBox4ttt.Controls.Add(this.lb_DP);
            this.groupBox4ttt.Controls.Add(this.label25);
            this.groupBox4ttt.Controls.Add(this.lb_RH);
            this.groupBox4ttt.Controls.Add(this.label24);
            this.groupBox4ttt.Controls.Add(this.lb_humidity_ratio);
            this.groupBox4ttt.Controls.Add(this.label23);
            this.groupBox4ttt.Controls.Add(this.lb_dbt);
            this.groupBox4ttt.Controls.Add(this.label21);
            this.groupBox4ttt.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.groupBox4ttt.Name = "groupBox4ttt";
            this.groupBox4ttt.TabStop = false;
            // 
            // label5
            // 
            this.label5.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.label5, "label5");
            this.label5.Name = "label5";
            // 
            // label4
            // 
            this.label4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.label4, "label4");
            this.label4.Name = "label4";
            // 
            // label3
            // 
            this.label3.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.label3, "label3");
            this.label3.Name = "label3";
            // 
            // labelline1
            // 
            this.labelline1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.labelline1, "labelline1");
            this.labelline1.Name = "labelline1";
            // 
            // lb_DP
            // 
            resources.ApplyResources(this.lb_DP, "lb_DP");
            this.lb_DP.Name = "lb_DP";
            // 
            // label25
            // 
            resources.ApplyResources(this.label25, "label25");
            this.label25.Name = "label25";
            // 
            // lb_RH
            // 
            resources.ApplyResources(this.lb_RH, "lb_RH");
            this.lb_RH.Name = "lb_RH";
            // 
            // label24
            // 
            resources.ApplyResources(this.label24, "label24");
            this.label24.Name = "label24";
            // 
            // lb_humidity_ratio
            // 
            resources.ApplyResources(this.lb_humidity_ratio, "lb_humidity_ratio");
            this.lb_humidity_ratio.Name = "lb_humidity_ratio";
            // 
            // label23
            // 
            resources.ApplyResources(this.label23, "label23");
            this.label23.Name = "label23";
            // 
            // lb_dbt
            // 
            resources.ApplyResources(this.lb_dbt, "lb_dbt");
            this.lb_dbt.Name = "lb_dbt";
            // 
            // label21
            // 
            resources.ApplyResources(this.label21, "label21");
            this.label21.Name = "label21";
            // 
            // gb_showstatus
            // 
            resources.ApplyResources(this.gb_showstatus, "gb_showstatus");
            this.gb_showstatus.Controls.Add(this.lb_realtimeshow);
            this.gb_showstatus.Controls.Add(this.lb_modeshow);
            this.gb_showstatus.Controls.Add(this.lb_vertical_line2);
            this.gb_showstatus.Controls.Add(this.lb_for_line_vertical1);
            this.gb_showstatus.Controls.Add(this.lb_numberOfHandler);
            this.gb_showstatus.Controls.Add(this.lb_number_of_chart_label);
            this.gb_showstatus.Controls.Add(this.lb_device_status);
            this.gb_showstatus.Controls.Add(this.lb_devicestatusshow);
            this.gb_showstatus.Name = "gb_showstatus";
            this.gb_showstatus.TabStop = false;
            // 
            // lb_realtimeshow
            // 
            resources.ApplyResources(this.lb_realtimeshow, "lb_realtimeshow");
            this.lb_realtimeshow.Name = "lb_realtimeshow";
            // 
            // lb_modeshow
            // 
            resources.ApplyResources(this.lb_modeshow, "lb_modeshow");
            this.lb_modeshow.Name = "lb_modeshow";
            // 
            // lb_vertical_line2
            // 
            this.lb_vertical_line2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.lb_vertical_line2, "lb_vertical_line2");
            this.lb_vertical_line2.Name = "lb_vertical_line2";
            // 
            // lb_for_line_vertical1
            // 
            this.lb_for_line_vertical1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.lb_for_line_vertical1, "lb_for_line_vertical1");
            this.lb_for_line_vertical1.Name = "lb_for_line_vertical1";
            // 
            // lb_numberOfHandler
            // 
            resources.ApplyResources(this.lb_numberOfHandler, "lb_numberOfHandler");
            this.lb_numberOfHandler.Name = "lb_numberOfHandler";
            // 
            // lb_number_of_chart_label
            // 
            resources.ApplyResources(this.lb_number_of_chart_label, "lb_number_of_chart_label");
            this.lb_number_of_chart_label.Name = "lb_number_of_chart_label";
            // 
            // lb_device_status
            // 
            resources.ApplyResources(this.lb_device_status, "lb_device_status");
            this.lb_device_status.Name = "lb_device_status";
            // 
            // lb_devicestatusshow
            // 
            resources.ApplyResources(this.lb_devicestatusshow, "lb_devicestatusshow");
            this.lb_devicestatusshow.Name = "lb_devicestatusshow";
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.SystemColors.InactiveCaption;
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.optionToolStripMenuItem,
            this.helpToolStripMenuItem});
            resources.ApplyResources(this.menuStrip1, "menuStrip1");
            this.menuStrip1.Name = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.printToolStripMenuItem,
            this.saveAsToolStripMenuItem,
            this.saveConfigurationToolStripMenuItem,
            this.loadConfigurationToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            resources.ApplyResources(this.fileToolStripMenuItem, "fileToolStripMenuItem");
            // 
            // printToolStripMenuItem
            // 
            this.printToolStripMenuItem.Name = "printToolStripMenuItem";
            resources.ApplyResources(this.printToolStripMenuItem, "printToolStripMenuItem");
            // 
            // saveAsToolStripMenuItem
            // 
            this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
            resources.ApplyResources(this.saveAsToolStripMenuItem, "saveAsToolStripMenuItem");
            // 
            // saveConfigurationToolStripMenuItem
            // 
            this.saveConfigurationToolStripMenuItem.Name = "saveConfigurationToolStripMenuItem";
            resources.ApplyResources(this.saveConfigurationToolStripMenuItem, "saveConfigurationToolStripMenuItem");
            // 
            // loadConfigurationToolStripMenuItem
            // 
            this.loadConfigurationToolStripMenuItem.Name = "loadConfigurationToolStripMenuItem";
            resources.ApplyResources(this.loadConfigurationToolStripMenuItem, "loadConfigurationToolStripMenuItem");
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            resources.ApplyResources(this.exitToolStripMenuItem, "exitToolStripMenuItem");
            // 
            // optionToolStripMenuItem
            // 
            this.optionToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.simulationMode,
            this.exportDataToolStripMenuItem,
            this.historyPlotToolStripMenuItem1,
            this.trashBoxToolStripMenuItem,
            this.gridViewToolStripMenuItem,
            this.excelExportToolStripMenuItem});
            this.optionToolStripMenuItem.Name = "optionToolStripMenuItem";
            resources.ApplyResources(this.optionToolStripMenuItem, "optionToolStripMenuItem");
            // 
            // simulationMode
            // 
            this.simulationMode.Name = "simulationMode";
            resources.ApplyResources(this.simulationMode, "simulationMode");
            // 
            // exportDataToolStripMenuItem
            // 
            this.exportDataToolStripMenuItem.Name = "exportDataToolStripMenuItem";
            resources.ApplyResources(this.exportDataToolStripMenuItem, "exportDataToolStripMenuItem");
            // 
            // historyPlotToolStripMenuItem1
            // 
            this.historyPlotToolStripMenuItem1.Name = "historyPlotToolStripMenuItem1";
            resources.ApplyResources(this.historyPlotToolStripMenuItem1, "historyPlotToolStripMenuItem1");
            // 
            // trashBoxToolStripMenuItem
            // 
            this.trashBoxToolStripMenuItem.Name = "trashBoxToolStripMenuItem";
            resources.ApplyResources(this.trashBoxToolStripMenuItem, "trashBoxToolStripMenuItem");
            // 
            // gridViewToolStripMenuItem
            // 
            this.gridViewToolStripMenuItem.Name = "gridViewToolStripMenuItem";
            resources.ApplyResources(this.gridViewToolStripMenuItem, "gridViewToolStripMenuItem");
            // 
            // excelExportToolStripMenuItem
            // 
            this.excelExportToolStripMenuItem.Name = "excelExportToolStripMenuItem";
            resources.ApplyResources(this.excelExportToolStripMenuItem, "excelExportToolStripMenuItem");
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.helpPsychometricChartToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            resources.ApplyResources(this.helpToolStripMenuItem, "helpToolStripMenuItem");
            // 
            // helpPsychometricChartToolStripMenuItem
            // 
            this.helpPsychometricChartToolStripMenuItem.Name = "helpPsychometricChartToolStripMenuItem";
            resources.ApplyResources(this.helpPsychometricChartToolStripMenuItem, "helpPsychometricChartToolStripMenuItem");
            // 
            // CMSinsertNode
            // 
            this.CMSinsertNode.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.quickNodeInsertToolStripMenuItem,
            this.disconnectLineToolStripMenuItem,
            this.clearChartToolStripMenuItem,
            this.editNodeToolStripMenuItem,
            this.deleteNodeToolStripMenuItem,
            this.disconnectLineFromAToolStripMenuItem});
            this.CMSinsertNode.Name = "contextMenuStrip2";
            resources.ApplyResources(this.CMSinsertNode, "CMSinsertNode");
            // 
            // quickNodeInsertToolStripMenuItem
            // 
            this.quickNodeInsertToolStripMenuItem.Name = "quickNodeInsertToolStripMenuItem";
            resources.ApplyResources(this.quickNodeInsertToolStripMenuItem, "quickNodeInsertToolStripMenuItem");
            this.quickNodeInsertToolStripMenuItem.Click += new System.EventHandler(this.quickNodeInsertToolStripMenuItem_Click);
            // 
            // disconnectLineToolStripMenuItem
            // 
            resources.ApplyResources(this.disconnectLineToolStripMenuItem, "disconnectLineToolStripMenuItem");
            this.disconnectLineToolStripMenuItem.Name = "disconnectLineToolStripMenuItem";
            // 
            // clearChartToolStripMenuItem
            // 
            this.clearChartToolStripMenuItem.Name = "clearChartToolStripMenuItem";
            resources.ApplyResources(this.clearChartToolStripMenuItem, "clearChartToolStripMenuItem");
            // 
            // editNodeToolStripMenuItem
            // 
            this.editNodeToolStripMenuItem.Name = "editNodeToolStripMenuItem";
            resources.ApplyResources(this.editNodeToolStripMenuItem, "editNodeToolStripMenuItem");
            this.editNodeToolStripMenuItem.Click += new System.EventHandler(this.editNodeToolStripMenuItem_Click);
            // 
            // deleteNodeToolStripMenuItem
            // 
            resources.ApplyResources(this.deleteNodeToolStripMenuItem, "deleteNodeToolStripMenuItem");
            this.deleteNodeToolStripMenuItem.Name = "deleteNodeToolStripMenuItem";
            // 
            // disconnectLineFromAToolStripMenuItem
            // 
            this.disconnectLineFromAToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.nodeAToolStripMenuItem,
            this.nodeBToolStripMenuItem});
            resources.ApplyResources(this.disconnectLineFromAToolStripMenuItem, "disconnectLineFromAToolStripMenuItem");
            this.disconnectLineFromAToolStripMenuItem.Name = "disconnectLineFromAToolStripMenuItem";
            // 
            // nodeAToolStripMenuItem
            // 
            this.nodeAToolStripMenuItem.Name = "nodeAToolStripMenuItem";
            resources.ApplyResources(this.nodeAToolStripMenuItem, "nodeAToolStripMenuItem");
            // 
            // nodeBToolStripMenuItem
            // 
            this.nodeBToolStripMenuItem.Name = "nodeBToolStripMenuItem";
            resources.ApplyResources(this.nodeBToolStripMenuItem, "nodeBToolStripMenuItem");
            // 
            // lb_unit_chosen_display
            // 
            resources.ApplyResources(this.lb_unit_chosen_display, "lb_unit_chosen_display");
            this.lb_unit_chosen_display.Name = "lb_unit_chosen_display";
            // 
            // pb_lock_unlock
            // 
            resources.ApplyResources(this.pb_lock_unlock, "pb_lock_unlock");
            this.pb_lock_unlock.Name = "pb_lock_unlock";
            this.pb_lock_unlock.TabStop = false;
            // 
            // backgroundWorker1
            // 
            this.backgroundWorker1.WorkerSupportsCancellation = true;
            // 
            // Form_Main_PH_Application
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.pb_lock_unlock);
            this.Controls.Add(this.lb_unit_chosen_display);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.gb_showstatus);
            this.Controls.Add(this.lb_db_name);
            this.Controls.Add(this.lb_buildingselectedShow);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.groupBox4ttt);
            this.Controls.Add(this.phChart);
            this.Name = "Form_Main_PH_Application";
            this.Load += new System.EventHandler(this.Form_Main_PH_Application_Load);
            this.Shown += new System.EventHandler(this.Form_Main_PH_Application_Shown);
            ((System.ComponentModel.ISupportInitialize)(this.phChart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.groupBox4ttt.ResumeLayout(false);
            this.groupBox4ttt.PerformLayout();
            this.gb_showstatus.ResumeLayout(false);
            this.gb_showstatus.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.CMSinsertNode.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pb_lock_unlock)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.DataVisualization.Charting.Chart phChart;
        private System.Windows.Forms.Label lb_buildingselectedShow;
        public System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridViewTextBoxColumn id;
        private System.Windows.Forms.DataGridViewTextBoxColumn name;
        private System.Windows.Forms.GroupBox groupBox4ttt;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label labelline1;
        private System.Windows.Forms.Label label25;
        private System.Windows.Forms.Label label24;
        private System.Windows.Forms.Label label23;
        private System.Windows.Forms.Label label21;
        private System.Windows.Forms.GroupBox gb_showstatus;
        private System.Windows.Forms.Label lb_modeshow;
        private System.Windows.Forms.Label lb_vertical_line2;
        private System.Windows.Forms.Label lb_for_line_vertical1;
        private System.Windows.Forms.Label lb_number_of_chart_label;
        private System.Windows.Forms.Label lb_devicestatusshow;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem printToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveConfigurationToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadConfigurationToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem optionToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem simulationMode;
        private System.Windows.Forms.ToolStripMenuItem exportDataToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem historyPlotToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem trashBoxToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem gridViewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem excelExportToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpPsychometricChartToolStripMenuItem;
        public System.Windows.Forms.Label lb_db_name;
        public System.Windows.Forms.Label lb_unit_chosen_display;
        public System.Windows.Forms.Label lb_numberOfHandler;
        public System.Windows.Forms.PictureBox pb_lock_unlock;
        public System.Windows.Forms.Label lb_realtimeshow;
        public System.Windows.Forms.Label lb_device_status;
        public System.ComponentModel.BackgroundWorker backgroundWorker1;
        public System.Windows.Forms.ToolStripMenuItem disconnectLineFromAToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem nodeAToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem nodeBToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem quickNodeInsertToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem disconnectLineToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem clearChartToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem editNodeToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem deleteNodeToolStripMenuItem;
        public System.Windows.Forms.ContextMenuStrip CMSinsertNode;
        public System.Windows.Forms.Label lb_DP;
        public System.Windows.Forms.Label lb_RH;
        public System.Windows.Forms.Label lb_humidity_ratio;
        public System.Windows.Forms.Label lb_dbt;
    }
}