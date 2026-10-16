library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Main is
    Port (
          -- Switch
          e1 : in STD_LOGIC;
          e2 : in STD_LOGIC;
          e11 : in STD_LOGIC; -- And
          e12 : in STD_LOGIC; -- Or
          e13 : in STD_LOGIC; -- Not
          e14 : in STD_LOGIC; -- Xor
          e15 : in STD_LOGIC; -- Nand
          e16 : in STD_LOGIC; -- Nor
          
          -- LED
          l1 : out STD_LOGIC;
          l2 : out STD_LOGIC;
          l11 : out STD_LOGIC;
          l12 : out STD_LOGIC;
          l13 : out STD_LOGIC;
          l14 : out STD_LOGIC;
          l15 : out STD_LOGIC;
          l16 : out STD_LOGIC;
          
          -- Display Bloc
          a : out STD_LOGIC;
          b : out STD_LOGIC;
          c : out STD_LOGIC;
          d : out STD_LOGIC;
          e : out STD_LOGIC;
          f : out STD_LOGIC;
          g : out STD_LOGIC;
          dp : out STD_LOGIC);
end Main;

architecture Behavioral of Main is
    component Gate_And
        Port ( e1 : in STD_LOGIC;
            e2 : in STD_LOGIC;
            res : out STD_LOGIC);
    end component;
    
    component Gate_Or
        Port ( e1 : in STD_LOGIC;
            e2 : in STD_LOGIC;
            res : out STD_LOGIC);
    end component;
    
    component Gate_Not
        Port ( e : in STD_LOGIC;
            res : out STD_LOGIC);
    end component;
    
    component Gate_Xor
        Port ( e1 : in STD_LOGIC;
            e2 : in STD_LOGIC;
            res : out STD_LOGIC);
    end component;
    
    component Gate_Nand
        Port ( e1 : in STD_LOGIC;
            e2 : in STD_LOGIC;
            res : out STD_LOGIC);
    end component;
    
    component Gate_Nor
        Port ( e1 : in STD_LOGIC;
            e2 : in STD_LOGIC;
            res : out STD_LOGIC);
    end component;

    component Display
        Port ( s : in STD_LOGIC;
            err : in STD_LOGIC;
            a : out STD_LOGIC;
            b : out STD_LOGIC;
            c : out STD_LOGIC;
            d : out STD_LOGIC;
            e : out STD_LOGIC;
            f : out STD_LOGIC;
            g : out STD_LOGIC;
            dp : out STD_LOGIC);
    end component;
    
    component Check_Err
        Port (e11 : in STD_LOGIC;
              e12 : in STD_LOGIC;
              e13 : in STD_LOGIC;
              e14 : in STD_LOGIC;
              e15 : in STD_LOGIC;
              e16 : in STD_LOGIC;
              err : out STD_LOGIC);
    end component;

    signal err: STD_LOGIC:='0';
    signal s: STD_LOGIC:='0';
    
    signal res_and: STD_LOGIC:='0';
    signal res_or: STD_LOGIC:='0';
    signal res_not: STD_LOGIC:='0';
    signal res_xor: STD_LOGIC:='0';
    signal res_nand: STD_LOGIC:='0';
    signal res_nor: STD_LOGIC:='0';
    
begin

    process(e11, e12, e13, e14, e15, e16, res_and, res_or, res_not, res_xor, res_nand, res_nor)
    begin
        s<='0';     
        if e11 = '1' then s<=res_and; end if;
        if e12 = '1' then s<=res_or; end if;
        if e13 = '1' then s<=res_not; end if;
        if e14 = '1' then s<=res_xor; end if;
        if e15 = '1' then s<=res_nand; end if;
        if e16 = '1' then s<=res_nor; end if;
    end process;
    
    l1<= e1 when err='0' else '0';
    l2<= e2 when err='0' and e13='0' else '0';
    
    l11<=e11;
    l12<=e12;
    l13<=e13;
    l14<=e14;
    l15<=e15;
    l16<=e16;
    
    Check_For_Error : Check_Err PORT MAP(e11=>e11, e12=>e12, e13=>e13, e14=>e14, e15=>e15, e16=>e16, err=>err);
    Display_Res : Display PORT MAP(s=>s, err=>err, a=>a, b=>b, c=>c, d=>d, e=>e, f=>f, g=>g, dp=>dp);
    
    Compute_And : Gate_And PORT MAP(e1, e2, res_and);
    Compute_Or : Gate_Or PORT MAP(e1, e2, res_or);
    Compute_Not : Gate_Not PORT MAP(e1, res_not);
    Compute_Xor : Gate_Xor PORT MAP(e1, e2, res_xor);
    Compute_Nand : Gate_Nand PORT MAP(e1, e2, res_nand);
    Compute_Nor : Gate_Nor PORT MAP(e1, e2, res_nor);
end Behavioral;
