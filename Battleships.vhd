LIBRARY ieee;

USE ieee.std_logic_1164.all; 

USE ieee.std_logic_arith.all; 

USE ieee.std_logic_unsigned.all; 

ENTITY Battleships IS

   PORT (

      KEY : IN STD_LOGIC_VECTOR(1 DOWNTO 0);

      CLOCK_50 : IN STD_LOGIC;

      DRAM_CLK, DRAM_CKE : OUT STD_LOGIC;

      DRAM_ADDR : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);

      DRAM_BA_0, DRAM_BA_1 : BUFFER STD_LOGIC;

      DRAM_CS_N, DRAM_CAS_N, DRAM_RAS_N, DRAM_WE_N : OUT STD_LOGIC;
 
      DRAM_DQ : INOUT STD_LOGIC_VECTOR(15 DOWNTO 0);

      DRAM_UDQM, DRAM_LDQM : BUFFER STD_LOGIC;
		
		VGA_R:out	std_logic_vector(9	downto	0);	
		VGA_G:out	std_logic_vector(9	downto	0);	
		VGA_B:out	std_logic_vector(9	downto	0);	
		VGA_CLK:	out	std_logic;
		VGA_BLANK:	out	std_logic;	
		VGA_HS:out	std_logic;	
		VGA_VS:out	std_logic;	
		VGA_SYNC:out	std_logic;
		
		SRAM_DQ	:	INOUT	STD_LOGIC_VECTOR(15	downto	0);
		SRAM_ADDR	:	OUT	STD_LOGIC_VECTOR(17	downto	0);
		SRAM_LB_N	:	OUT	STD_LOGIC;
		SRAM_UB_N	:	OUT	STD_LOGIC;
		SRAM_CE_N	:	OUT	STD_LOGIC;
		SRAM_OE_N	:	OUT	STD_LOGIC;
		SRAM_WE_N	:	OUT	STD_LOGIC;
		
		I2C_SDAT: inout STD_LOGIC;
		I2C_SCLK: OUT STD_LOGIC;
		AUD_XCK: OUT STD_LOGIC;
		CLOCK_27: IN STD_LOGIC;
		AUD_ADCDAT: IN STD_LOGIC;
		AUD_ADCLRCK: IN STD_LOGIC;
		AUD_BCLK: IN STD_LOGIC;
		AUD_DACDAT: inout STD_LOGIC;
		AUD_DACLRCK: IN STD_LOGIC;
		
		UART_RXD: IN STD_LOGIC;
		UART_TXD: OUT STD_LOGIC);

   END Battleships;



ARCHITECTURE Structure OF Battleships IS

   COMPONENT nios_system PORT (

      clk_clk : IN STD_LOGIC;
		
		button2_export : IN STD_LOGIC;

      reset_reset_n : IN STD_LOGIC;

      sdram_clk_clk : OUT STD_LOGIC;
 
      sdram_wire_addr : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
 
      sdram_wire_ba : BUFFER STD_LOGIC_VECTOR(1 DOWNTO 0);
 
      sdram_wire_cas_n : OUT STD_LOGIC;

       sdram_wire_cke : OUT STD_LOGIC;

       sdram_wire_cs_n : OUT STD_LOGIC;

       sdram_wire_dq : INOUT STD_LOGIC_VECTOR(15 DOWNTO 0);
 
      sdram_wire_dqm : BUFFER STD_LOGIC_VECTOR(1 DOWNTO 0);
 
      sdram_wire_ras_n : OUT STD_LOGIC;

      sdram_wire_we_n : OUT STD_LOGIC;
		
		vga_controller_R:out	std_logic_vector(9	downto	0);	
		vga_controller_G:out	std_logic_vector(9	downto	0);	
		vga_controller_B:out	std_logic_vector(9	downto	0);	
		vga_controller_CLK:	out	std_logic;
		vga_controller_BLANK:	out	std_logic;	
		vga_controller_HS:out	std_logic;	
		vga_controller_VS:out	std_logic;	
		vga_controller_SYNC:out	std_logic;
		
		sram_DQ	:	INOUT	STD_LOGIC_VECTOR(15	downto	0);
		sram_ADDR	:	OUT	STD_LOGIC_VECTOR(17	downto	0);
		sram_LB_N	:	OUT	STD_LOGIC;
		sram_UB_N	:	OUT	STD_LOGIC;
		sram_CE_N	:	OUT	STD_LOGIC;
		sram_OE_N	:	OUT	STD_LOGIC;
		sram_WE_N	:	OUT	STD_LOGIC;
		
		clocks_clk_in_secondary_clk: IN STD_LOGIC;
		clocks_audio_clk_clk: out STD_LOGIC;
		audio_vid_SDAT: INOUT STD_LOGIC;
		audio_vid_SCLK: out STD_LOGIC;
		audio_ADCDAT: IN STD_LOGIC;
		audio_ADCLRCK: IN STD_LOGIC;
		audio_BCLK: IN STD_LOGIC;
		audio_DACDAT: out STD_LOGIC;
		audio_DACLRCK: IN STD_LOGIC;
		
		serial_RXD: IN STD_LOGIC;
		serial_TXD: OUT STD_LOGIC);

   END COMPONENT;


   SIGNAL DQM : STD_LOGIC_VECTOR(1 DOWNTO 0);

   SIGNAL BA : STD_LOGIC_VECTOR(1 DOWNTO 0);


   BEGIN

      DRAM_BA_0 <= BA(0);
 
      DRAM_BA_1 <= BA(1);
 
      DRAM_UDQM <= DQM(1);
 
      DRAM_LDQM <= DQM(0);

      NiosII: nios_system PORT MAP (

          clk_clk => CLOCK_50,

          reset_reset_n => KEY(0),
			 
			 button2_export => KEY(1),

          sdram_clk_clk => DRAM_CLK,
 
         sdram_wire_addr => DRAM_ADDR,
 
         sdram_wire_ba => BA,
 
         sdram_wire_cas_n => DRAM_CAS_N,
 
         sdram_wire_cke => DRAM_CKE,
 
         sdram_wire_cs_n => DRAM_CS_N,
 
         sdram_wire_dq => DRAM_DQ,
 
         sdram_wire_dqm => DQM,
 
         sdram_wire_ras_n => DRAM_RAS_N,
 
         sdram_wire_we_n => DRAM_WE_N,
			
			vga_controller_CLK	=>	VGA_CLK,	
			vga_controller_HS	=>	VGA_HS,	
			vga_controller_VS	=>	VGA_VS,	
			vga_controller_BLANK	=>	VGA_BLANK,	
			vga_controller_SYNC	=>	VGA_SYNC,	
			vga_controller_R	=>	VGA_R,	
			vga_controller_G	=>	VGA_G,	
			vga_controller_B	=>	VGA_B,
			
			sram_DQ	=>	SRAM_DQ,
			sram_ADDR	=>	SRAM_ADDR,
			sram_LB_N	=>	SRAM_LB_N,
			sram_UB_N	=>	SRAM_UB_N,
			sram_CE_N	=>	SRAM_CE_N,
			sram_OE_N	=>	SRAM_OE_N,
			sram_WE_N	=>	SRAM_WE_N,
			
			audio_vid_SDAT => I2C_SDAT,
			audio_vid_SCLK => I2C_SCLK,
			clocks_audio_clk_clk => AUD_XCK,
			clocks_clk_in_secondary_clk => CLOCK_27,
			audio_ADCDAT => AUD_ADCDAT,
			audio_ADCLRCK => AUD_ADCLRCK,
			audio_BCLK => AUD_BCLK,
			audio_DACDAT => AUD_DACDAT,
			audio_DACLRCK => AUD_DACLRCK,
			
			serial_RXD => UART_RXD,
			serial_TXD => UART_TXD);

   END Structure;