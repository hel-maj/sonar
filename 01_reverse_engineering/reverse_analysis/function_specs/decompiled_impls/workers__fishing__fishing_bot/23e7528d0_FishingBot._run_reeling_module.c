/* ===== 23e7528d0 workers.fishing.fishing_bot:FishingBot._run_reeling_module ===== */
/* ghidra_name=FUN_23e7528d0 entry=23e7528d0 size=9024 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code ******* FUN_23e7528d0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  double dVar2;
  double dVar3;
  code ******ppppppcVar4;
  code ******ppppppcVar5;
  code ****ppppcVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  undefined1 auVar9 [16];
  code *******pppppppcVar10;
  char cVar11;
  int iVar12;
  longlong *plVar13;
  code *******pppppppcVar14;
  longlong lVar15;
  code *******pppppppcVar16;
  longlong *plVar17;
  code *******pppppppcVar18;
  code *******pppppppcVar19;
  code *******pppppppcVar20;
  code *******pppppppcVar21;
  code *******pppppppcVar22;
  code *******pppppppcVar23;
  code ******ppppppcVar24;
  longlong *plVar25;
  longlong lVar26;
  undefined8 *puVar27;
  longlong *plVar28;
  longlong *plVar29;
  longlong *plVar30;
  longlong *plVar31;
  longlong *plVar32;
  longlong *plVar33;
  longlong lVar34;
  code *pcVar35;
  code *******pppppppcVar36;
  longlong *plVar37;
  longlong *plVar38;
  code *******pppppppcVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  code *pcVar42;
  code *pcVar43;
  code *****pppppcVar44;
  undefined8 uVar45;
  undefined8 uVar46;
  longlong *plStack_3f0;
  longlong *plStack_3e8;
  longlong *plStack_3e0;
  longlong *plStack_3d8;
  longlong *plStack_3d0;
  longlong *plStack_3c8;
  longlong *plStack_398;
  longlong *plStack_390;
  undefined1 auStack_388 [16];
  code *******pppppppcStack_378;
  longlong *plStack_368;
  longlong *plStack_360;
  code ******ppppppcStack_350;
  longlong *plStack_348;
  longlong lStack_340;
  longlong *plStack_338;
  longlong *plStack_330;
  longlong *plStack_328;
  longlong *plStack_320;
  code *******pppppppcStack_318;
  longlong *plStack_2f0;
  longlong *plStack_2e8;
  longlong *plStack_2e0;
  longlong *plStack_2d8;
  code *pcStack_2d0;
  longlong *plStack_2c8;
  longlong *plStack_2c0;
  longlong *plStack_2b8;
  longlong *plStack_2b0;
  longlong *plStack_2a8;
  longlong *plStack_2a0;
  longlong *plStack_298;
  longlong *plStack_290;
  code *pcStack_280;
  longlong *plStack_278;
  longlong *plStack_270;
  longlong *plStack_268;
  longlong *plStack_260;
  longlong *plStack_258;
  longlong *plStack_250;
  longlong *plStack_248;
  longlong *plStack_240;
  code *******pppppppcStack_238;
  code *******pppppppcStack_230;
  longlong *plStack_228;
  longlong *plStack_220;
  longlong *plStack_218;
  longlong *plStack_210;
  longlong *plStack_208;
  longlong *plStack_200;
  longlong *plStack_1f8;
  longlong *plStack_1f0;
  longlong *plStack_1e8;
  longlong **pplStack_1e0;
  longlong *plStack_1d8;
  undefined1 auStack_1d0 [16];
  code *******apppppppcStack_1c0 [2];
  longlong *plStack_1b0;
  longlong *plStack_1a8;
  longlong *plStack_1a0;
  code *******pppppppcStack_190;
  longlong *plStack_188;
  code *******pppppppcStack_178;
  undefined8 *puStack_170;
  longlong lStack_168;
  code *******pppppppcStack_160;
  longlong *plStack_158;
  code *******pppppppcStack_150;
  code *******pppppppcStack_148;
  code *******pppppppcStack_140;
  code *******local_118;
  code *******local_110;
  code *******local_108;
  code *******local_100;
  code ******local_f8;
  code *******local_f0;
  code ******local_e0;
  code *******local_d8;
  code *******local_d0;
  undefined8 local_c8;
  code *******local_c0;
  code *******local_b8;
  code *******local_b0;
  code *******local_a8;
  code ******local_a0;
  code *******local_98;
  code *******local_90;
  code *******local_88;
  longlong *plStack_80;
  undefined1 local_78 [16];
  code *******local_68 [5];
  
  pppppppcVar14 = _DAT_23eedae18;
  pppppppcVar36 = (code *******)*param_3;
  local_68[0] = (code *******)0x0;
  local_78._0_8_ = (code *****)0x0;
  local_78._8_8_ = 0;
  if (_DAT_23eedae18 == (code *******)0x0) {
LAB_23e75292d:
    pppppppcStack_140 = (code *******)0x23e752949;
    _DAT_23eedae18 = (code *******)FUN_23e91f3b0(param_1,_DAT_23eedafb0,DAT_23eedaeb8,0x40);
  }
  else {
    ppppppcVar24 = *_DAT_23eedae18;
    if (1 < (longlong)ppppppcVar24) {
      *_DAT_23eedae18 = (code ******)((longlong)ppppppcVar24 + -1);
      goto LAB_23e75292d;
    }
    if (_DAT_23eedae18[2] != (code ******)0x0) {
      *_DAT_23eedae18 = (code ******)((longlong)ppppppcVar24 + -1);
      if ((code ******)((longlong)ppppppcVar24 + -1) == (code ******)0x0) {
        pppppppcStack_140 = (code *******)0x23e7532d2;
        (*(code *)pppppppcVar14[1][6])(pppppppcVar14);
      }
      goto LAB_23e75292d;
    }
  }
  pppppppcVar39 = _DAT_23eedae18;
  lVar15 = *(longlong *)(param_1 + 0x38);
  pppppppcVar14 = _DAT_23eedae18 + 9;
  ppppppcVar24 = *(code *******)(lVar15 + 8);
  _DAT_23eedae18[0xf] = ppppppcVar24;
  *(code ********)(lVar15 + 8) = pppppppcVar14;
  if ((ppppppcVar24 != (code ******)0x0) &&
     (((*(char *)((longlong)ppppppcVar24 + 0x45) == '\x01' ||
       ((code *****)
        ((longlong)ppppppcVar24[4] + (longlong)*(int *)(ppppppcVar24[4] + 0x15) * 2 + 0xb8) <=
        ppppppcVar24[7])) && (pppppppcVar39[0xe] != (code ******)0x0)))) {
    pppppcVar44 = ppppppcVar24[5];
    pppppppcVar39[0xe][2] = pppppcVar44;
    if (pppppcVar44 != (code *****)0x0) {
      *pppppcVar44 = (code ****)((longlong)*pppppcVar44 + 1);
    }
  }
  *pppppppcVar39 = (code ******)((longlong)*pppppppcVar39 + 1);
  uVar45 = DAT_23eed89b0;
  *(undefined4 *)(pppppppcVar39 + 8) = 0;
  pppppppcStack_140 = (code *******)0x23e7529bf;
  plVar13 = (longlong *)FUN_23e8bc2f0(pppppppcVar36,uVar45);
  if (plVar13 == (longlong *)0x0) {
    local_68[0] = *(code ********)(param_1 + 0x70);
    local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    pppppppcVar22 = (code *******)0x0;
    pppppppcVar20 = (code *******)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pppppppcVar14 = (code *******)0x0;
    pppppppcVar16 = (code *******)0x0;
    uVar40 = 0x330;
    local_d8 = (code *******)0x0;
    local_d0 = (code *******)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    local_e0 = (code ******)0x0;
    pppppppcVar19 = DAT_23ed6a4f8;
    pppppppcVar21 = local_c8;
    goto joined_r0x00023e753487;
  }
  *(undefined4 *)(pppppppcVar39 + 5) = 0x330;
  pppppppcStack_140 = (code *******)0x23e7529e9;
  local_e0 = (code ******)plVar13;
  pppppppcVar14 = (code *******)FUN_23e91bfe0(param_1,plVar13,DAT_23eed8d38);
  local_e0 = (code ******)*plVar13;
  *plVar13 = (longlong)local_e0 + -1;
  if ((longlong)local_e0 + -1 == 0) {
    pppppppcStack_140 = (code *******)0x23e752ada;
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if (pppppppcVar14 == (code *******)0x0) {
    local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_68[0] = *(code ********)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar40 = 0x330;
    local_d8 = (code *******)0x0;
    local_d0 = (code *******)0x0;
    local_e0 = (code ******)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pppppppcVar16 = (code *******)0x0;
    pppppppcVar20 = (code *******)0x0;
    pppppppcVar22 = (code *******)0x0;
    pppppppcVar14 = (code *******)0x0;
    pppppppcVar19 = DAT_23ed6a4f8;
    pppppppcVar21 = local_c8;
    local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    goto joined_r0x00023e753487;
  }
  pppppppcStack_140 = (code *******)0x23e752a12;
  iVar12 = FUN_23a35f020(pppppppcVar14);
  ppppppcVar24 = (code ******)((longlong)*pppppppcVar14 + -1);
  if (iVar12 == -1) {
    local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    local_68[0] = *(code ********)(param_1 + 0x70);
    uVar40 = 0x330;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *pppppppcVar14 = ppppppcVar24;
    if (ppppppcVar24 == (code ******)0x0) {
      pppppppcStack_140 = (code *******)0x23e753812;
      (*(code *)pppppppcVar14[1][6])(pppppppcVar14);
      uVar40 = 0x330;
    }
  }
  else {
    *pppppppcVar14 = ppppppcVar24;
    if (ppppppcVar24 == (code ******)0x0) {
      pppppppcStack_140 = (code *******)0x23e752a38;
      (*(code *)pppppppcVar14[1][6])(pppppppcVar14);
    }
    pcVar43 = _Py_NoneStruct_exref;
    lVar15 = DAT_23eed90d0;
    if (iVar12 != 0) {
      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
      local_b8 = (code *******)pcVar43;
      lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar13 = *(longlong **)(lVar15 + 0x28);
      plVar17 = (longlong *)plVar13[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
      *(undefined4 *)(plVar13 + 8) = 0xffffffff;
      if (plVar17 != (longlong *)0x0) {
        plVar13[2] = 0;
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          pppppppcStack_140 = (code *******)0x23e752a8c;
          (**(code **)(plVar17[1] + 0x30))();
        }
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        pppppppcStack_140 = (code *******)0x23e7532fa;
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar13[0xf] = 0;
LAB_23e752a9e:
      *pppppppcVar36 = (code ******)((longlong)*pppppppcVar36 + -1);
      if (*pppppppcVar36 == (code ******)0x0) {
        pppppppcStack_140 = (code *******)0x23e7532ea;
        (*(code *)pppppppcVar36[1][6])(pppppppcVar36);
        return local_b8;
      }
      return local_b8;
    }
    *(undefined4 *)(pppppppcVar39 + 5) = 0x333;
    pppppppcStack_140 = (code *******)0x23e752c24;
    plVar13 = (longlong *)
              FUN_23e915840(param_1,pppppppcVar36,DAT_23eed8b40,*(undefined8 *)(lVar15 + 0x18));
    if (plVar13 == (longlong *)0x0) {
      local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
      local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
      local_68[0] = *(code ********)(param_1 + 0x70);
      pppppppcVar22 = (code *******)0x0;
      pppppppcVar20 = (code *******)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pppppppcVar14 = (code *******)0x0;
      pppppppcVar16 = (code *******)0x0;
      uVar40 = 0x333;
      local_d8 = (code *******)0x0;
      local_d0 = (code *******)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_e0 = (code ******)0x0;
      pppppppcVar19 = DAT_23ed6a4f8;
      pppppppcVar21 = local_c8;
      goto joined_r0x00023e753487;
    }
    local_e0 = (code ******)*plVar13;
    *plVar13 = (longlong)local_e0 + -1;
    if ((longlong)local_e0 + -1 == 0) {
      pppppppcStack_140 = (code *******)0x23e75330a;
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    pppppppcStack_140 = (code *******)0x23e752c59;
    plVar13 = (longlong *)FUN_23e8bc2f0(pppppppcVar36,DAT_23eed8aa8);
    if (plVar13 == (longlong *)0x0) {
      local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
      local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
      local_68[0] = *(code ********)(param_1 + 0x70);
      pppppppcVar22 = (code *******)0x0;
      pppppppcVar20 = (code *******)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pppppppcVar14 = (code *******)0x0;
      pppppppcVar16 = (code *******)0x0;
      uVar40 = 0x336;
      local_d8 = (code *******)0x0;
      local_d0 = (code *******)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_e0 = (code ******)0x0;
      pppppppcVar19 = DAT_23ed6a4f8;
      pppppppcVar21 = local_c8;
      goto joined_r0x00023e753487;
    }
    pppppppcStack_140 = (code *******)0x23e752c79;
    local_e0 = (code ******)plVar13;
    iVar12 = FUN_23e913250(plVar13,DAT_23eed90d8);
    local_e0 = (code ******)*plVar13;
    *plVar13 = (longlong)local_e0 + -1;
    if ((longlong)local_e0 + -1 == 0) {
      pppppppcStack_140 = (code *******)0x23e753317;
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (iVar12 != -1) {
      if (iVar12 == 1) {
        pppppppcStack_140 = (code *******)0x23e753325;
        local_e0 = (code ******)FUN_23e8e0660();
        if (local_e0 == (code ******)0x0) {
          pppppppcVar22 = (code *******)0x0;
          pppppppcVar20 = (code *******)0x0;
          pppppppcVar14 = (code *******)0x0;
          pppppppcVar16 = (code *******)0x0;
          pppppppcStack_140 = (code *******)0x23e753355;
          FUN_23e915740(param_1,local_78,DAT_23eed90e0);
          local_d8 = (code *******)0x0;
          uVar40 = 0x337;
          local_d0 = (code *******)0x0;
          pppppppcVar19 = DAT_23ed6a4f8;
          pppppppcVar21 = local_c8;
          goto joined_r0x00023e753487;
        }
      }
      else {
        pppppppcStack_140 = (code *******)0x23e752cb0;
        local_e0 = (code ******)FUN_23e8e0510();
        if (local_e0 == (code ******)0x0) {
          pppppppcVar22 = (code *******)0x0;
          pppppppcVar20 = (code *******)0x0;
          pppppppcVar14 = (code *******)0x0;
          pppppppcVar16 = (code *******)0x0;
          pppppppcStack_140 = (code *******)0x23e754102;
          FUN_23e915740(param_1,local_78,DAT_23eed90e8);
          local_d8 = (code *******)0x0;
          uVar40 = 0x339;
          local_d0 = (code *******)0x0;
          pppppppcVar19 = DAT_23ed6a4f8;
          pppppppcVar21 = local_c8;
          goto joined_r0x00023e753487;
        }
      }
      *local_e0 = (code *****)((longlong)*local_e0 + 1);
      pppppppcStack_140 = (code *******)0x23e752cc7;
      lVar15 = FUN_23e8e03c0();
      if (lVar15 == 0) {
        pppppppcStack_140 = (code *******)0x23e753b8f;
        FUN_23e915740(param_1,local_78,DAT_23eed90f0);
        pppppppcVar16 = (code *******)0x0;
      }
      else {
        *(undefined4 *)(pppppppcVar39 + 5) = 0x33c;
        pppppppcStack_140 = (code *******)0x23e752cea;
        pppppppcVar16 = (code *******)FUN_23e914090(param_1,lVar15,local_e0);
        lVar15 = _DAT_23eed91e0;
        if (pppppppcVar16 != (code *******)0x0) {
          *(undefined4 *)(pppppppcVar39 + 5) = 0x340;
          pppppppcStack_140 = (code *******)0x23e752d1a;
          plVar13 = (longlong *)
                    FUN_23e915840(param_1,pppppppcVar36,DAT_23eed8b40,*(undefined8 *)(lVar15 + 0x18)
                                 );
          if (plVar13 == (longlong *)0x0) {
            local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_68[0] = *(code ********)(param_1 + 0x70);
            pppppppcVar22 = (code *******)0x0;
            pppppppcVar20 = (code *******)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar40 = 0x340;
            local_d8 = (code *******)0x0;
            local_d0 = (code *******)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pppppppcVar14 = (code *******)0x0;
            pppppppcVar19 = DAT_23ed6a4f8;
            pppppppcVar21 = local_c8;
            goto joined_r0x00023e753487;
          }
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            pppppppcStack_140 = (code *******)0x23e752d36;
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          pppppppcStack_140 = (code *******)0x23e752d3b;
          lVar15 = FUN_23e8e0ba0();
          if (lVar15 == 0) {
            pppppppcStack_140 = (code *******)0x23e754258;
            FUN_23e915740(param_1,local_78,DAT_23eed8c70);
            pppppppcVar14 = (code *******)0x0;
LAB_23e754260:
            local_d8 = (code *******)0x0;
            pppppppcVar22 = (code *******)0x0;
            pppppppcVar20 = (code *******)0x0;
            uVar40 = 0x341;
            local_d0 = (code *******)0x0;
            pppppppcVar19 = DAT_23ed6a4f8;
            pppppppcVar21 = local_c8;
          }
          else {
            *(undefined4 *)(pppppppcVar39 + 5) = 0x341;
            pppppppcStack_140 = (code *******)0x23e752d60;
            plVar13 = (longlong *)FUN_23e91bfe0(param_1,lVar15);
            pcVar43 = PyFloat_Type_exref;
            if (plVar13 == (longlong *)0x0) {
              local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_68[0] = *(code ********)(param_1 + 0x70);
              pppppppcVar22 = (code *******)0x0;
              pppppppcVar14 = (code *******)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar40 = 0x341;
              local_d8 = (code *******)0x0;
              local_d0 = (code *******)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pppppppcVar20 = (code *******)0x0;
              pppppppcVar19 = DAT_23ed6a4f8;
              pppppppcVar21 = local_c8;
              goto joined_r0x00023e753487;
            }
            if ((code *)plVar13[1] == PyFloat_Type_exref) {
              dVar2 = (double)plVar13[2];
              dVar3 = *(double *)(DAT_23eed8b20 + 0x10);
              lVar15 = *(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10);
              pppppppcVar14 = *(code ********)(lVar15 + 0xe08);
              if (pppppppcVar14 == (code *******)0x0) {
                pppppppcStack_140 = (code *******)0x23e75474e;
                pppppppcVar14 = (code *******)(*DAT_23ed6ccd0)(0,0x18);
              }
              else {
                ppppppcVar24 = pppppppcVar14[1];
                *(int *)(lVar15 + 0xe00) = *(int *)(lVar15 + 0xe00) + -1;
                *(code *******)(lVar15 + 0xe08) = ppppppcVar24;
              }
              pppppppcVar14[1] = (code ******)pcVar43;
              *pppppppcVar14 = (code ******)0x1;
              pppppppcVar14[2] = (code ******)(dVar3 + dVar2);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                pppppppcStack_140 = (code *******)0x23e7543f9;
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
            }
            else {
              pppppppcStack_140 = (code *******)0x23e752d8c;
              pppppppcVar14 = (code *******)FUN_23e8bfcd0(plVar13);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                pppppppcStack_140 = (code *******)0x23e75399b;
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              if (pppppppcVar14 == (code *******)0x0) {
                local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                local_68[0] = *(code ********)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e754260;
              }
            }
            if (pppppppcVar36 == (code *******)0x0) {
              pppppppcStack_140 = (code *******)0x23e75454a;
              local_78._8_8_ =
                   PyUnicode_FromFormat
                             ("cannot access local variable \'%U\' where it is not associated with a value"
                              ,DAT_23eed8d30);
              local_78._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
              *(code *****)local_78._0_8_ = (code ****)((longlong)*(code *****)local_78._0_8_ + 1);
              local_68[0] = (code *******)0x0;
              if ((code *)local_78._0_8_ != _Py_NoneStruct_exref) {
                pppppppcStack_140 = (code *******)0x23e7545a6;
                FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
              }
              pppppppcVar22 = (code *******)0x0;
              pppppppcVar20 = (code *******)0x0;
              pppppppcStack_140 = (code *******)0x23e7545c0;
              FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_78._8_8_);
              local_d8 = (code *******)0x0;
              uVar40 = 0x342;
              local_d0 = (code *******)0x0;
              pppppppcVar19 = DAT_23ed6a4f8;
              pppppppcVar21 = local_c8;
            }
            else {
              local_d8 = (code *******)0x0;
              local_d0 = (code *******)0x0;
              local_a8 = (code *******)0x0;
              pppppppcVar20 = (code *******)0x0;
              pppppppcVar23 = local_d8;
              pppppppcVar18 = local_d0;
              local_c0 = pppppppcVar39;
              local_b0 = pppppppcVar36;
              pppppppcVar22 = local_a8;
              local_98 = pppppppcVar16;
              local_90 = pppppppcVar14;
LAB_23e752df1:
              do {
                local_a8 = pppppppcVar22;
                local_d0 = pppppppcVar18;
                local_d8 = pppppppcVar23;
                pppppppcStack_140 = (code *******)0x23e752e05;
                plVar13 = (longlong *)FUN_23e8bc2f0(local_b0,DAT_23eed89b0);
                uVar45 = DAT_23eed8d38;
                if (plVar13 == (longlong *)0x0) {
LAB_23e7538c0:
                  uVar40 = 0x342;
                  local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  local_68[0] = *(code ********)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pppppppcVar39 = local_c0;
                  pppppppcVar16 = local_98;
                  pppppppcVar22 = local_a8;
                  pppppppcVar14 = local_90;
                  pppppppcVar36 = local_b0;
                  pppppppcVar19 = DAT_23ed6a4f8;
                  pppppppcVar21 = local_c8;
                  goto joined_r0x00023e753487;
                }
                *(undefined4 *)(local_c0 + 5) = 0x342;
                pppppppcStack_140 = (code *******)0x23e752e34;
                plVar17 = (longlong *)FUN_23e91bfe0(param_1,plVar13,uVar45);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  pppppppcStack_140 = (code *******)0x23e752e47;
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if (plVar17 == (longlong *)0x0) goto LAB_23e7538c0;
                pppppppcStack_140 = (code *******)0x23e752e58;
                iVar12 = FUN_23a35f020(plVar17);
                *plVar17 = *plVar17 + -1;
                if (*plVar17 == 0) {
                  pppppppcStack_140 = (code *******)0x23e752e6a;
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                if (iVar12 == -1) goto LAB_23e7538c0;
                pcVar43 = _Py_FalseStruct_exref;
                if (iVar12 == 0) {
                  pcVar43 = _Py_TrueStruct_exref;
                }
                pppppppcStack_140 = (code *******)0x23e752e8c;
                iVar12 = FUN_23a35f020(pcVar43);
                if (iVar12 == 1) {
                  pppppppcStack_140 = (code *******)0x23e753855;
                  lVar15 = FUN_23e8e0ba0();
                  pppppppcVar14 = local_90;
                  pppppppcVar16 = local_98;
                  pppppppcVar22 = local_a8;
                  pppppppcVar36 = local_b0;
                  pppppppcVar39 = local_c0;
                  if (lVar15 != 0) {
                    *(undefined4 *)(local_c0 + 5) = 0x342;
                    pppppppcStack_140 = (code *******)0x23e753881;
                    plVar13 = (longlong *)FUN_23e91bfe0(param_1,lVar15);
                    if (plVar13 != (longlong *)0x0) {
                      pppppppcStack_140 = (code *******)0x23e753899;
                      pcVar43 = (code *)FUN_23e8d09c0(plVar13,local_90);
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        pppppppcStack_140 = (code *******)0x23e7538ac;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if (pcVar43 != (code *)0x0) goto LAB_23e752e99;
                    }
                    goto LAB_23e7538c0;
                  }
                  pppppppcStack_140 = (code *******)0x23e7539dd;
                  FUN_23e915740(param_1,local_78,DAT_23eed8c70);
                  uVar40 = 0x342;
                  pppppppcVar19 = DAT_23ed6a4f8;
                  pppppppcVar21 = local_c8;
                  goto joined_r0x00023e753487;
                }
                *(longlong *)pcVar43 = *(longlong *)pcVar43 + 1;
LAB_23e752e99:
                pppppppcStack_140 = (code *******)0x23e752ea1;
                iVar12 = FUN_23a35f020(pcVar43);
                *(longlong *)pcVar43 = *(longlong *)pcVar43 + -1;
                if (*(longlong *)pcVar43 == 0) {
                  pppppppcStack_140 = (code *******)0x23e752eb3;
                  (**(code **)(*(longlong *)(pcVar43 + 8) + 0x30))(pcVar43);
                }
                if (iVar12 == -1) goto LAB_23e7538c0;
                if (iVar12 == 0) {
                  local_b8 = (code *******)_Py_NoneStruct_exref;
                  pppppppcVar16 = local_98;
                  pppppppcVar39 = local_a8;
                  pppppppcVar14 = local_90;
                  pppppppcVar36 = local_b0;
LAB_23e75461c:
                  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar13 = *(longlong **)(lVar15 + 0x28);
                  plVar17 = (longlong *)plVar13[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                       *(undefined8 *)(lVar15 + 0x30);
                  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
                  if (plVar17 != (longlong *)0x0) {
                    plVar13[2] = 0;
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      pppppppcStack_140 = (code *******)0x23e754655;
                      (**(code **)(plVar17[1] + 0x30))();
                    }
                  }
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    pppppppcStack_140 = (code *******)0x23e754665;
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  plVar13[0xf] = 0;
                  *local_b8 = (code ******)((longlong)*local_b8 + 1);
                  local_c8 = (code *******)*local_e0;
                  *local_e0 = (code *****)((longlong)local_c8 + -1);
                  if ((code *****)((longlong)local_c8 + -1) == (code *****)0x0) {
                    pppppppcStack_140 = (code *******)0x23e754699;
                    (*(code *)local_e0[1][6])(local_e0);
                  }
                  *pppppppcVar16 = (code ******)((longlong)*pppppppcVar16 + -1);
                  if (*pppppppcVar16 == (code ******)0x0) {
                    pppppppcStack_140 = (code *******)0x23e7546aa;
                    (*(code *)pppppppcVar16[1][6])(pppppppcVar16);
                  }
                  *pppppppcVar14 = (code ******)((longlong)*pppppppcVar14 + -1);
                  if (*pppppppcVar14 == (code ******)0x0) {
                    pppppppcStack_140 = (code *******)0x23e7546ba;
                    (*(code *)pppppppcVar14[1][6])(pppppppcVar14);
                  }
                  if ((pppppppcVar20 != (code *******)0x0) &&
                     (*pppppppcVar20 = (code ******)((longlong)*pppppppcVar20 + -1),
                     *pppppppcVar20 == (code ******)0x0)) {
                    pppppppcStack_140 = (code *******)0x23e7546d1;
                    (*(code *)pppppppcVar20[1][6])(pppppppcVar20);
                  }
                  if (local_d0 != (code *******)0x0) {
                    local_e0 = *local_d0;
                    *local_d0 = (code ******)((longlong)local_e0 + -1);
                    if ((code ******)((longlong)local_e0 + -1) == (code ******)0x0) {
                      pppppppcStack_140 = (code *******)0x23e7546f6;
                      (*(code *)local_d0[1][6])(local_d0);
                    }
                  }
                  if (local_d8 != (code *******)0x0) {
                    local_e0 = *local_d8;
                    *local_d8 = (code ******)((longlong)local_e0 + -1);
                    if ((code *****)((longlong)local_e0 + -1) == (code *****)0x0) {
                      pppppppcStack_140 = (code *******)0x23e75471b;
                      (*(code *)local_d8[1][6])(local_d8);
                    }
                  }
                  if ((pppppppcVar39 != (code *******)0x0) &&
                     (*pppppppcVar39 = (code ******)((longlong)*pppppppcVar39 + -1),
                     *pppppppcVar39 == (code ******)0x0)) {
                    pppppppcStack_140 = (code *******)0x23e754739;
                    (*(code *)pppppppcVar39[1][6])(pppppppcVar39);
                  }
                  goto LAB_23e752a9e;
                }
                pppppppcStack_140 = (code *******)0x23e752ed8;
                plVar13 = (longlong *)FUN_23e8bc2f0(local_b0,DAT_23eed8a98);
                uVar45 = DAT_23eed8a98;
                if (plVar13 == (longlong *)0x0) {
LAB_23e754400:
                  uVar40 = 0x343;
                  local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  local_68[0] = *(code ********)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pppppppcVar39 = local_c0;
                  pppppppcVar16 = local_98;
                  pppppppcVar22 = local_a8;
                  pppppppcVar14 = local_90;
                  pppppppcVar36 = local_b0;
                  pppppppcVar19 = DAT_23ed6a4f8;
                  pppppppcVar21 = local_c8;
                  goto joined_r0x00023e753487;
                }
                *(undefined4 *)(local_c0 + 5) = 0x343;
                pppppppcStack_140 = (code *******)0x23e752f07;
                local_c8 = (code *******)FUN_23e91bfe0(param_1,plVar13,uVar45);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  pppppppcStack_140 = (code *******)0x23e752f1c;
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if (local_c8 == (code *******)0x0) goto LAB_23e754400;
                if ((pppppppcVar20 != (code *******)0x0) &&
                   (*pppppppcVar20 = (code ******)((longlong)*pppppppcVar20 + -1),
                   *pppppppcVar20 == (code ******)0x0)) {
                  pppppppcStack_140 = (code *******)0x23e752f3f;
                  (*(code *)pppppppcVar20[1][6])(pppppppcVar20);
                }
                uVar45 = DAT_23eed9108;
                local_b8 = (code *******)_Py_NoneStruct_exref;
                if (local_c8 == (code *******)_Py_NoneStruct_exref) {
                  pppppppcStack_140 = (code *******)0x23e753765;
                  lVar15 = FUN_23e8e0ba0();
                  pppppppcVar14 = local_90;
                  pppppppcVar16 = local_98;
                  pppppppcVar22 = local_a8;
                  pppppppcVar36 = local_b0;
                  pppppppcVar39 = local_c0;
                  uVar45 = DAT_23eed8d40;
                  if (lVar15 == 0) {
                    pppppppcStack_140 = (code *******)0x23e7544d3;
                    FUN_23e915740(param_1,local_78,DAT_23eed8c70);
                    uVar40 = 0x345;
                    pppppppcVar20 = local_c8;
                    pppppppcVar19 = DAT_23ed6a4f8;
                    pppppppcVar21 = local_c8;
                    goto joined_r0x00023e753487;
                  }
                  *(undefined4 *)(local_c0 + 5) = 0x345;
                  pppppppcStack_140 = (code *******)0x23e75379c;
                  plVar13 = (longlong *)
                            FUN_23e915840(param_1,lVar15,uVar45,
                                          *(undefined8 *)(_DAT_23eed9178 + 0x18));
                  pppppppcVar22 = local_a8;
                  pppppppcVar20 = local_c8;
                  if (plVar13 == (longlong *)0x0) {
                    uVar40 = 0x345;
                    local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    local_68[0] = *(code ********)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pppppppcVar39 = local_c0;
                    pppppppcVar16 = local_98;
                    pppppppcVar14 = local_90;
                    pppppppcVar36 = local_b0;
                    pppppppcVar19 = DAT_23ed6a4f8;
                    pppppppcVar21 = local_c8;
                    goto joined_r0x00023e753487;
                  }
                  *plVar13 = *plVar13 + -1;
                  pppppppcVar23 = local_d8;
                  pppppppcVar18 = local_d0;
                  if (*plVar13 == 0) {
                    pppppppcStack_140 = (code *******)0x23e7537b5;
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                    pppppppcVar20 = local_c8;
                    pppppppcVar23 = local_d8;
                    pppppppcVar18 = local_d0;
                    pppppppcVar22 = local_a8;
                  }
                  goto LAB_23e752df1;
                }
                *(undefined4 *)(local_c0 + 5) = 0x349;
                pppppppcStack_140 = (code *******)0x23e752f8b;
                plVar13 = (longlong *)FUN_23e915840(param_1,local_98,uVar45,local_c8);
                if (plVar13 == (longlong *)0x0) {
LAB_23e7544eb:
                  pppppcVar44 = *(code ******)(param_1 + 0x60);
                  uVar45 = *(undefined8 *)(param_1 + 0x68);
                  pppppppcVar23 = *(code ********)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pppppppcVar39 = local_c0;
                  pppppppcVar16 = local_98;
                  pppppppcVar22 = local_a8;
                  pppppppcVar14 = local_90;
                  pppppppcVar36 = local_b0;
LAB_23e753e7f:
                  uVar40 = 0x349;
                  pppppppcVar20 = local_c8;
                  pppppppcVar19 = DAT_23ed6a4f8;
                  pppppppcVar21 = local_c8;
                  local_68[0] = pppppppcVar23;
                  local_78._0_8_ = pppppcVar44;
                  local_78._8_8_ = uVar45;
                  goto joined_r0x00023e753487;
                }
                pppppppcStack_140 = (code *******)0x23e752f9f;
                plVar17 = (longlong *)FUN_23a388310(plVar13);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  pppppppcStack_140 = (code *******)0x23e752fb2;
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if (plVar17 == (longlong *)0x0) goto LAB_23e7544eb;
                pppppppcStack_140 = (code *******)0x23e752fc8;
                pppppppcVar18 = (code *******)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                local_a0 = (code ******)local_78;
                if (pppppppcVar18 == (code *******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e753c09;
                  pppppppcVar18 = (code *******)FUN_23a3c1b70(param_1,local_a0,0,7);
                  pppppppcVar36 = local_b0;
                  if (pppppppcVar18 != (code *******)0x0) goto LAB_23e752fe4;
                  local_a0 = (code ******)0x0;
                  plVar13 = (longlong *)0x0;
                  lVar15 = *plVar17;
                  pppppppcVar21 = (code *******)0x0;
                  local_b0 = (code *******)0x0;
                  pppppppcVar19 = (code *******)0x0;
                  pppppppcVar20 = (code *******)0x0;
                  pppppppcVar39 = local_c0;
                  pppppppcVar22 = local_b0;
                  pppppppcVar23 = (code *******)local_a0;
LAB_23e753c70:
                  local_a0 = (code ******)pppppppcVar23;
                  local_b0 = pppppppcVar22;
                  local_c0 = pppppppcVar18;
                  pppppppcVar23 = local_68[0];
                  uVar45 = local_78._8_8_;
                  pppppcVar44 = (code *****)local_78._0_8_;
                  pppppppcVar14 = local_90;
                  pppppppcVar16 = local_98;
                  pppppppcVar22 = local_a8;
                  local_78 = (undefined1  [16])0x0;
                  local_68[0] = (code *******)0x0;
                  *plVar17 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    local_b8 = pppppppcVar23;
                    pppppppcStack_140 = (code *******)0x23e753ccd;
                    local_a8 = pppppppcVar21;
                    local_98 = pppppppcVar20;
                    local_90 = pppppppcVar19;
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                    pppppppcVar20 = local_98;
                    pppppppcVar23 = local_b8;
                    pppppppcVar19 = local_90;
                    pppppppcVar21 = local_a8;
                  }
                  pppppppcVar10 = local_c0;
                  local_68[0] = (code *******)0x0;
                  local_78._0_8_ = (code *****)0x0;
                  local_78._8_8_ = 0;
                  pppppppcVar18 = local_c0;
                  if (local_c0 != (code *******)0x0) {
                    pppppppcVar18 = (code *******)*local_c0;
                    ppppppcVar24 = (code ******)((longlong)pppppppcVar18 + -1);
                    *local_c0 = ppppppcVar24;
                    if (ppppppcVar24 == (code ******)0x0) {
                      pppppppcVar18 = local_c0 + 1;
                      pppppppcStack_140 = (code *******)0x23e753d48;
                      local_c0 = pppppppcVar23;
                      local_b8 = pppppppcVar21;
                      local_a8 = pppppppcVar20;
                      local_98 = pppppppcVar19;
                      (*(code *)(*pppppppcVar18)[6])(pppppppcVar10);
                      pppppppcVar20 = local_a8;
                      pppppppcVar23 = local_c0;
                      pppppppcVar19 = local_98;
                      pppppppcVar21 = local_b8;
                      pppppppcVar18 = local_c0;
                    }
                  }
                  local_c0 = pppppppcVar18;
                  if ((pppppppcVar19 != (code *******)0x0) &&
                     (*pppppppcVar19 = (code ******)((longlong)*pppppppcVar19 + -1),
                     *pppppppcVar19 == (code ******)0x0)) {
                    pppppppcStack_140 = (code *******)0x23e753d90;
                    local_c0 = pppppppcVar23;
                    local_b8 = pppppppcVar21;
                    local_a8 = pppppppcVar20;
                    (*(code *)pppppppcVar19[1][6])(pppppppcVar19);
                    pppppppcVar20 = local_a8;
                    pppppppcVar23 = local_c0;
                    pppppppcVar21 = local_b8;
                  }
                  if ((pppppppcVar20 != (code *******)0x0) &&
                     (*pppppppcVar20 = (code ******)((longlong)*pppppppcVar20 + -1),
                     *pppppppcVar20 == (code ******)0x0)) {
                    pppppppcStack_140 = (code *******)0x23e753dc8;
                    local_c0 = pppppppcVar23;
                    local_b8 = pppppppcVar21;
                    (*(code *)pppppppcVar20[1][6])(pppppppcVar20);
                    pppppppcVar23 = local_c0;
                    pppppppcVar21 = local_b8;
                  }
                  if ((pppppppcVar21 != (code *******)0x0) &&
                     (*pppppppcVar21 = (code ******)((longlong)*pppppppcVar21 + -1),
                     *pppppppcVar21 == (code ******)0x0)) {
                    pppppppcStack_140 = (code *******)0x23e753def;
                    local_c0 = pppppppcVar23;
                    (*(code *)pppppppcVar21[1][6])(pppppppcVar21);
                    pppppppcVar23 = local_c0;
                  }
                  if (local_b0 != (code *******)0x0) {
                    local_c0 = (code *******)*local_b0;
                    *local_b0 = (code ******)((longlong)local_c0 + -1);
                    if ((code ******)((longlong)local_c0 + -1) == (code ******)0x0) {
                      pppppppcStack_140 = (code *******)0x23e753e27;
                      local_c0 = pppppppcVar23;
                      (*(code *)local_b0[1][6])(local_b0);
                      pppppppcVar23 = local_c0;
                    }
                  }
                  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                    pppppppcStack_140 = (code *******)0x23e753e48;
                    local_c0 = pppppppcVar23;
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                    pppppppcVar23 = local_c0;
                  }
                  if (local_a0 != (code ******)0x0) {
                    local_c0 = (code *******)*local_a0;
                    *local_a0 = (code *****)((longlong)local_c0 + -1);
                    if ((code *****)((longlong)local_c0 + -1) == (code *****)0x0) {
                      pppppppcStack_140 = (code *******)0x23e753e7a;
                      local_c0 = pppppppcVar23;
                      (*(code *)local_a0[1][6])(local_a0);
                      pppppppcVar23 = local_c0;
                    }
                  }
                  goto LAB_23e753e7f;
                }
LAB_23e752fe4:
                pppppppcStack_140 = (code *******)0x23e752ff1;
                pppppppcVar19 = (code *******)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                if (pppppppcVar19 == (code *******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e753ec1;
                  pppppppcVar19 = (code *******)FUN_23a3c1b70(param_1,local_a0,1,7);
                  pppppppcVar36 = local_b0;
                  if (pppppppcVar19 == (code *******)0x0) {
                    local_a0 = (code ******)0x0;
                    plVar13 = (longlong *)0x0;
                    lVar15 = *plVar17;
                    pppppppcVar21 = (code *******)0x0;
                    pppppppcVar20 = (code *******)0x0;
                    local_b0 = (code *******)0x0;
                    pppppppcVar39 = local_c0;
                    pppppppcVar22 = local_b0;
                    pppppppcVar23 = (code *******)local_a0;
                    goto LAB_23e753c70;
                  }
                }
                pppppppcStack_140 = (code *******)0x23e75300a;
                pppppppcVar20 = (code *******)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                if (pppppppcVar20 == (code *******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e753f51;
                  pppppppcVar20 = (code *******)FUN_23a3c1b70(param_1,local_a0,2,7);
                  pppppppcVar36 = local_b0;
                  if (pppppppcVar20 == (code *******)0x0) {
                    local_a0 = (code ******)0x0;
                    plVar13 = (longlong *)0x0;
                    lVar15 = *plVar17;
                    pppppppcVar21 = (code *******)0x0;
                    local_b0 = (code *******)0x0;
                    pppppppcVar39 = local_c0;
                    pppppppcVar22 = local_b0;
                    pppppppcVar23 = (code *******)local_a0;
                    goto LAB_23e753c70;
                  }
                }
                pppppppcStack_140 = (code *******)0x23e753023;
                pppppppcVar21 = (code *******)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                if (pppppppcVar21 == (code *******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e753fe1;
                  pppppppcVar21 = (code *******)FUN_23a3c1b70(param_1,local_a0,3,7);
                  pppppppcVar36 = local_b0;
                  if (pppppppcVar21 == (code *******)0x0) {
                    local_a0 = (code ******)0x0;
                    plVar13 = (longlong *)0x0;
                    lVar15 = *plVar17;
                    local_b0 = (code *******)0x0;
                    pppppppcVar39 = local_c0;
                    pppppppcVar22 = local_b0;
                    pppppppcVar23 = (code *******)local_a0;
                    goto LAB_23e753c70;
                  }
                }
                pppppppcStack_140 = (code *******)0x23e75303c;
                pppppppcVar22 = (code *******)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                if (pppppppcVar22 == (code *******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e754071;
                  pppppppcVar22 = (code *******)FUN_23a3c1b70(param_1,local_a0,4,7);
                  if (pppppppcVar22 == (code *******)0x0) {
                    plVar13 = (longlong *)0x0;
                    local_a0 = (code ******)0x0;
                    lVar15 = *plVar17;
                    pppppppcVar39 = local_c0;
                    pppppppcVar36 = local_b0;
                    pppppppcVar23 = (code *******)local_a0;
                    goto LAB_23e753c70;
                  }
                }
                pppppppcStack_140 = (code *******)0x23e753055;
                plVar13 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                if (plVar13 == (longlong *)0x0) {
                  pppppppcStack_140 = (code *******)0x23e754151;
                  plVar13 = (longlong *)FUN_23a3c1b70(param_1,local_a0,5,7);
                  if (plVar13 == (longlong *)0x0) {
                    local_a0 = (code ******)0x0;
                    lVar15 = *plVar17;
                    pppppppcVar39 = local_c0;
                    pppppppcVar36 = local_b0;
                    pppppppcVar23 = (code *******)local_a0;
                    goto LAB_23e753c70;
                  }
                }
                pppppppcStack_140 = (code *******)0x23e75306e;
                pppppppcVar23 = (code *******)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                if (pppppppcVar23 == (code *******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e7541e1;
                  pppppppcVar23 = (code *******)FUN_23a3c1b70(param_1,local_a0,6,7);
                  if (pppppppcVar23 == (code *******)0x0) {
                    lVar15 = *plVar17;
                    pppppppcVar39 = local_c0;
                    pppppppcVar36 = local_b0;
                    goto LAB_23e753c70;
                  }
                }
                pppppppcStack_140 = (code *******)0x23e753098;
                cVar11 = FUN_23a3884a0(param_1,local_a0,plVar17,7);
                lVar15 = *plVar17;
                pppppppcVar39 = local_c0;
                pppppppcVar36 = local_b0;
                if (cVar11 == '\0') goto LAB_23e753c70;
                *plVar17 = lVar15 + -1;
                if (lVar15 + -1 == 0) {
                  pppppppcStack_140 = (code *******)0x23e7530bb;
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                ppppppcVar24 = *pppppppcVar18;
                *pppppppcVar18 = (code ******)((longlong)ppppppcVar24 + 1);
                if (local_d0 != (code *******)0x0) {
                  local_a0 = *local_d0;
                  *local_d0 = (code ******)((longlong)local_a0 + -1);
                  if ((code ******)((longlong)local_a0 + -1) == (code ******)0x0) {
                    pppppppcStack_140 = (code *******)0x23e75398a;
                    (*(code *)local_d0[1][6])(local_d0);
                  }
                  ppppppcVar24 = (code ******)((longlong)*pppppppcVar18 + -1);
                }
                *pppppppcVar18 = ppppppcVar24;
                if (ppppppcVar24 == (code ******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e753100;
                  (*(code *)pppppppcVar18[1][6])(pppppppcVar18);
                }
                ppppppcVar24 = *pppppppcVar19;
                *pppppppcVar19 = (code ******)((longlong)ppppppcVar24 + 1);
                if (local_d8 != (code *******)0x0) {
                  local_d0 = (code *******)*local_d8;
                  *local_d8 = (code ******)((longlong)local_d0 + -1);
                  if ((code *****)((longlong)local_d0 + -1) == (code *****)0x0) {
                    pppppppcStack_140 = (code *******)0x23e75397a;
                    (*(code *)local_d8[1][6])(local_d8);
                  }
                  ppppppcVar24 = (code ******)((longlong)*pppppppcVar19 + -1);
                }
                *pppppppcVar19 = ppppppcVar24;
                if (ppppppcVar24 == (code ******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e753146;
                  (*(code *)pppppppcVar19[1][6])(pppppppcVar19);
                }
                *pppppppcVar20 = (code ******)((longlong)*pppppppcVar20 + 1);
                *pppppppcVar19 = (code ******)((longlong)*pppppppcVar19 + -1);
                if (*pppppppcVar19 == (code ******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e75315b;
                  (*(code *)pppppppcVar19[1][6])(pppppppcVar19);
                }
                *pppppppcVar20 = (code ******)((longlong)*pppppppcVar20 + -1);
                if (*pppppppcVar20 == (code ******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e75316b;
                  (*(code *)pppppppcVar20[1][6])(pppppppcVar20);
                }
                *pppppppcVar21 = (code ******)((longlong)*pppppppcVar21 + 1);
                *pppppppcVar20 = (code ******)((longlong)*pppppppcVar20 + -1);
                if (*pppppppcVar20 == (code ******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e75317f;
                  (*(code *)pppppppcVar20[1][6])(pppppppcVar20);
                }
                *pppppppcVar21 = (code ******)((longlong)*pppppppcVar21 + -1);
                if (*pppppppcVar21 == (code ******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e75318f;
                  (*(code *)pppppppcVar21[1][6])(pppppppcVar21);
                }
                ppppppcVar24 = *pppppppcVar22;
                *pppppppcVar22 = (code ******)((longlong)ppppppcVar24 + 1);
                if (local_a8 != (code *******)0x0) {
                  local_d8 = (code *******)*local_a8;
                  *local_a8 = (code ******)((longlong)local_d8 + -1);
                  if ((code ******)((longlong)local_d8 + -1) == (code ******)0x0) {
                    pppppppcStack_140 = (code *******)0x23e753962;
                    (*(code *)local_a8[1][6])(local_a8);
                  }
                  ppppppcVar24 = (code ******)((longlong)*pppppppcVar22 + -1);
                }
                *pppppppcVar22 = ppppppcVar24;
                if (ppppppcVar24 == (code ******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e7531d8;
                  (*(code *)pppppppcVar22[1][6])(pppppppcVar22);
                }
                *plVar13 = *plVar13 + 1;
                *pppppppcVar21 = (code ******)((longlong)*pppppppcVar21 + -1);
                if (*pppppppcVar21 == (code ******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e7531ed;
                  (*(code *)pppppppcVar21[1][6])(pppppppcVar21);
                }
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  pppppppcStack_140 = (code *******)0x23e7531ff;
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                *pppppppcVar23 = (code ******)((longlong)*pppppppcVar23 + 1);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  pppppppcStack_140 = (code *******)0x23e753215;
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                *pppppppcVar23 = (code ******)((longlong)*pppppppcVar23 + -1);
                if (*pppppppcVar23 == (code ******)0x0) {
                  pppppppcStack_140 = (code *******)0x23e753225;
                  (*(code *)pppppppcVar23[1][6])(pppppppcVar23);
                }
                pppppppcStack_140 = (code *******)0x23e75322d;
                iVar12 = FUN_23a35f020(pppppppcVar22);
                pppppppcVar14 = local_90;
                pppppppcVar16 = local_98;
                pppppppcVar36 = local_b0;
                pppppppcVar39 = local_c0;
                if (iVar12 == -1) {
                  uVar40 = 0x34b;
                  local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  local_68[0] = *(code ********)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pppppppcVar20 = local_c8;
                  pppppppcVar19 = DAT_23ed6a4f8;
                  local_d8 = pppppppcVar23;
                  local_d0 = pppppppcVar18;
                  pppppppcVar21 = local_c8;
                  local_c0 = pppppppcVar18;
                  local_b0 = pppppppcVar22;
                  local_a0 = (code ******)pppppppcVar23;
                  local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  goto joined_r0x00023e753487;
                }
                if (iVar12 != 0) {
                  pppppppcStack_140 = (code *******)0x23e75487c;
                  local_c0 = pppppppcVar18;
                  local_b0 = pppppppcVar22;
                  local_a0 = (code ******)pppppppcVar23;
                  plVar13 = (longlong *)FUN_23e8bc2f0(pppppppcVar36,DAT_23eed8b40);
                  ppppppcVar24 = _DAT_23eed91e8;
                  if (plVar13 == (longlong *)0x0) {
LAB_23e754bd6:
                    local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    local_68[0] = *(code ********)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    lVar15 = *(longlong *)(param_1 + 0x10);
                    pppppppcVar20 = *(code ********)(lVar15 + 0xe38);
                    if (pppppppcVar20 == (code *******)0x0) {
                      pppppppcStack_140 = (code *******)0x23e754bce;
                      pppppppcVar20 = (code *******)FUN_23e916a20(PyTuple_Type_exref,5);
                    }
                    else {
                      ppppppcVar4 = pppppppcVar20[3];
                      *(int *)(lVar15 + 0xec8) = *(int *)(lVar15 + 0xec8) + -1;
                      *(code *******)(lVar15 + 0xe38) = ppppppcVar4;
                      *pppppppcVar20 = (code ******)0x1;
                    }
                    pcVar43 = _PyRuntime_exref;
                    *(undefined1 (*) [16])(pppppppcVar20 + 4) = (undefined1  [16])0x0;
                    lVar15 = *(longlong *)(pcVar43 + 0x1f8);
                    *(undefined1 (*) [16])(pppppppcVar20 + 6) = (undefined1  [16])0x0;
                    pppppppcVar22 = *(code ********)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
                    ppppppcVar4 = pppppppcVar20[-1];
                    ppppppcVar5 = pppppppcVar22[1];
                    *ppppppcVar5 = (code *****)(pppppppcVar20 + -2);
                    pppppppcVar20[-2] = (code ******)pppppppcVar22;
                    pppppppcVar20[-1] =
                         (code ******)((ulonglong)((uint)ppppppcVar4 & 3) | (ulonglong)ppppppcVar5);
                    pppppppcVar22[1] = (code ******)(pppppppcVar20 + -2);
                    uVar45 = _DAT_23eed91f0;
                    *ppppppcVar24 = (code *****)((longlong)*ppppppcVar24 + 1);
                    pppppppcVar20[3] = ppppppcVar24;
                    pppppppcStack_140 = (code *******)0x23e75492c;
                    local_d8 = pppppppcVar20;
                    pppppppcVar19 = (code *******)FUN_23e8bc2f0(pppppppcVar16,uVar45);
                    plVar17 = DAT_23ed6cd28;
                    pppppppcVar20 = local_d8;
                    if (pppppppcVar19 != (code *******)0x0) {
                      if (DAT_23ed6a4c0 == (longlong *)0x0) {
                        pppppppcStack_140 = (code *******)0x23e754c54;
                        plVar25 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                        pppppppcStack_190 = pppppppcVar19;
                        if (plVar25 != (longlong *)0x0) {
                          *plVar25 = *plVar25 + 1;
                          DAT_23ed6a4c0 = plVar25;
                          goto LAB_23e754960;
                        }
LAB_23e754cb4:
                        pppppppcStack_140 = (code *******)0x23e754cbc;
                        PyErr_PrintEx(0,0);
                        lVar15 = 1;
                        pppppppcStack_140 = (code *******)0x23e754cc7;
                        Py_Exit();
                        ppppppcVar24 = _DAT_23eedae10;
                        pppppppcStack_140 = pppppppcVar36;
                        pppppppcStack_148 = pppppppcVar14;
                        pppppppcStack_160 = pppppppcVar16;
                        puStack_170 = &DAT_23ed6a4c0;
                        pppppppcStack_178 = pppppppcVar39;
                        pppppppcVar22 = (code *******)*pppppppcVar22;
                        apppppppcStack_1c0[0] = (code *******)0x0;
                        auStack_1d0._0_8_ = (code *)0x0;
                        auStack_1d0._8_8_ = 0;
                        plStack_188 = plVar17;
                        lStack_168 = param_1;
                        plStack_158 = plVar13;
                        pppppppcStack_150 = pppppppcVar19;
                        if (_DAT_23eedae10 == (code ******)0x0) {
LAB_23e754d2d:
                          pppppppcStack_318 = (code *******)0x23e754d49;
                          _DAT_23eedae10 =
                               (code ******)FUN_23e91f3b0(lVar15,_DAT_23eedaf80,DAT_23eedaeb8,0x78);
                        }
                        else {
                          pppppcVar44 = *_DAT_23eedae10;
                          if (1 < (longlong)pppppcVar44) {
                            *_DAT_23eedae10 = (code *****)((longlong)pppppcVar44 + -1);
                            goto LAB_23e754d2d;
                          }
                          if (_DAT_23eedae10[2] != (code *****)0x0) {
                            *_DAT_23eedae10 = (code *****)((longlong)pppppcVar44 + -1);
                            if ((code *****)((longlong)pppppcVar44 + -1) == (code *****)0x0) {
                              pppppppcStack_318 = (code *******)0x23e755a22;
                              (*(code *)ppppppcVar24[1][6])(ppppppcVar24);
                            }
                            goto LAB_23e754d2d;
                          }
                        }
                        ppppppcVar4 = _DAT_23eedae10;
                        lVar26 = *(longlong *)(lVar15 + 0x38);
                        ppppppcVar24 = _DAT_23eedae10 + 9;
                        pppppcVar44 = *(code ******)(lVar26 + 8);
                        _DAT_23eedae10[0xf] = pppppcVar44;
                        *(code *******)(lVar26 + 8) = ppppppcVar24;
                        if ((pppppcVar44 != (code *****)0x0) &&
                           (((*(char *)((longlong)pppppcVar44 + 0x45) == '\x01' ||
                             ((code ****)
                              ((longlong)pppppcVar44[4] +
                              (longlong)*(int *)(pppppcVar44[4] + 0x15) * 2 + 0xb8) <=
                              pppppcVar44[7])) && (ppppppcVar4[0xe] != (code *****)0x0)))) {
                          ppppcVar6 = pppppcVar44[5];
                          ppppppcVar4[0xe][2] = ppppcVar6;
                          if (ppppcVar6 != (code ****)0x0) {
                            *ppppcVar6 = (code ***)((longlong)*ppppcVar6 + 1);
                          }
                        }
                        *ppppppcVar4 = (code *****)((longlong)*ppppppcVar4 + 1);
                        uVar45 = DAT_23eed89b0;
                        *(undefined4 *)(ppppppcVar4 + 8) = 0;
                        pppppppcStack_318 = (code *******)0x23e754dbf;
                        plVar13 = (longlong *)FUN_23e8bc2f0(pppppppcVar22,uVar45);
                        if (plVar13 == (longlong *)0x0) {
                          apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
                          auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
                          auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
                          plVar37 = (longlong *)0x0;
                          plVar29 = (longlong *)0x0;
                          *(undefined8 *)(lVar15 + 0x70) = 0;
                          plVar25 = (longlong *)0x0;
                          plVar17 = (longlong *)0x0;
                          uVar40 = 0x353;
                          plStack_270 = (longlong *)0x0;
                          plStack_248 = (longlong *)0x0;
                          plStack_260 = (longlong *)0x0;
                          plStack_250 = (longlong *)0x0;
                          plStack_268 = (longlong *)0x0;
                          plStack_278 = (longlong *)0x0;
                          pcStack_280 = (code *)0x0;
                          plStack_240 = (longlong *)0x0;
                          plStack_258 = (longlong *)0x0;
                          *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                          plVar13 = (longlong *)0x0;
                          goto LAB_23e755c16;
                        }
                        *(undefined4 *)(ppppppcVar4 + 5) = 0x353;
                        pppppppcStack_318 = (code *******)0x23e754de4;
                        plVar17 = (longlong *)FUN_23e91bfe0(lVar15,plVar13,DAT_23eed8d38);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          pppppppcStack_318 = (code *******)0x23e754eca;
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        if (plVar17 == (longlong *)0x0) {
                          auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
                          auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
                          apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
                          plVar37 = (longlong *)0x0;
                          plVar29 = (longlong *)0x0;
                          *(undefined8 *)(lVar15 + 0x70) = 0;
                          plVar25 = (longlong *)0x0;
                          plVar13 = (longlong *)0x0;
                          uVar41 = 0x353;
                          uVar40 = 0x353;
                          plStack_270 = (longlong *)0x0;
                          plStack_248 = (longlong *)0x0;
                          plStack_260 = (longlong *)0x0;
                          plStack_250 = (longlong *)0x0;
                          plStack_268 = (longlong *)0x0;
                          plStack_278 = (longlong *)0x0;
                          pcStack_280 = (code *)0x0;
                          plStack_240 = (longlong *)0x0;
                          plStack_258 = (longlong *)0x0;
                          *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                          plVar17 = (longlong *)0x0;
                          if (apppppppcStack_1c0[0] != (code *******)0x0) goto LAB_23e755c1f;
                          apppppppcStack_1c0[0] = (code *******)0x0;
                          plVar17 = (longlong *)0x0;
                          goto LAB_23e754f90;
                        }
                        pppppppcStack_318 = (code *******)0x23e754e02;
                        iVar12 = FUN_23a35f020(plVar17);
                        lVar26 = *plVar17 + -1;
                        if (iVar12 == -1) {
                          auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
                          auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
                          apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
                          uVar40 = 0x353;
                          *(undefined8 *)(lVar15 + 0x70) = 0;
                          *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                          *plVar17 = lVar26;
                          if (lVar26 == 0) {
                            pppppppcStack_318 = (code *******)0x23e7561da;
                            (**(code **)(plVar17[1] + 0x30))(plVar17);
                            uVar40 = 0x353;
                          }
LAB_23e7561e8:
                          plStack_270 = (longlong *)0x0;
                          plVar17 = (longlong *)0x0;
                          plVar13 = (longlong *)0x0;
                          plVar37 = (longlong *)0x0;
                          plStack_248 = (longlong *)0x0;
                          plVar29 = (longlong *)0x0;
                          plVar25 = (longlong *)0x0;
                          plStack_260 = (longlong *)0x0;
                          plStack_250 = (longlong *)0x0;
                          plStack_268 = (longlong *)0x0;
                          plStack_278 = (longlong *)0x0;
                          pcStack_280 = (code *)0x0;
                          plStack_240 = (longlong *)0x0;
                          plStack_258 = (longlong *)0x0;
                          goto LAB_23e755c16;
                        }
                        *plVar17 = lVar26;
                        if (lVar26 == 0) {
                          pppppppcStack_318 = (code *******)0x23e754e28;
                          (**(code **)(plVar17[1] + 0x30))(plVar17);
                        }
                        pcVar43 = _Py_NoneStruct_exref;
                        if (iVar12 != 0) {
                          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                          pppppppcStack_238 = (code *******)pcVar43;
                          lVar26 = *(longlong *)(*(longlong *)(lVar15 + 0x38) + 8);
                          plVar13 = *(longlong **)(lVar26 + 0x28);
                          plVar17 = (longlong *)plVar13[2];
                          *(undefined8 *)(*(longlong *)(lVar15 + 0x38) + 8) =
                               *(undefined8 *)(lVar26 + 0x30);
                          *(undefined4 *)(plVar13 + 8) = 0xffffffff;
                          if (plVar17 != (longlong *)0x0) {
                            plVar13[2] = 0;
                            *plVar17 = *plVar17 + -1;
                            if (*plVar17 == 0) {
                              pppppppcStack_318 = (code *******)0x23e754e7c;
                              (**(code **)(plVar17[1] + 0x30))();
                            }
                          }
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            pppppppcStack_318 = (code *******)0x23e755a4a;
                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                          }
                          plVar13[0xf] = 0;
                          goto LAB_23e754e8e;
                        }
                        *(undefined4 *)(ppppppcVar4 + 5) = 0x356;
                        pppppppcStack_318 = (code *******)0x23e755074;
                        plVar13 = (longlong *)FUN_23e915840(lVar15,pppppppcVar22,DAT_23eed8b40);
                        if (plVar13 == (longlong *)0x0) {
                          auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
                          auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
                          apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
                          plVar37 = (longlong *)0x0;
                          plVar29 = (longlong *)0x0;
                          *(undefined8 *)(lVar15 + 0x70) = 0;
                          plVar25 = (longlong *)0x0;
                          plVar17 = (longlong *)0x0;
                          uVar40 = 0x356;
                          plStack_270 = (longlong *)0x0;
                          plStack_248 = (longlong *)0x0;
                          plStack_260 = (longlong *)0x0;
                          plStack_250 = (longlong *)0x0;
                          plStack_268 = (longlong *)0x0;
                          plStack_278 = (longlong *)0x0;
                          pcStack_280 = (code *)0x0;
                          plStack_240 = (longlong *)0x0;
                          plStack_258 = (longlong *)0x0;
                          *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                          plVar13 = (longlong *)0x0;
                          goto LAB_23e755c16;
                        }
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          pppppppcStack_318 = (code *******)0x23e755a5a;
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        pppppppcStack_318 = (code *******)0x23e755099;
                        plVar13 = (longlong *)FUN_23e8bc2f0(pppppppcVar22,DAT_23eed8aa8);
                        if (plVar13 == (longlong *)0x0) {
                          auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
                          auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
                          apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
                          plVar37 = (longlong *)0x0;
                          plVar29 = (longlong *)0x0;
                          *(undefined8 *)(lVar15 + 0x70) = 0;
                          plVar25 = (longlong *)0x0;
                          plVar17 = (longlong *)0x0;
                          uVar40 = 0x359;
                          plStack_270 = (longlong *)0x0;
                          plStack_248 = (longlong *)0x0;
                          plStack_260 = (longlong *)0x0;
                          plStack_250 = (longlong *)0x0;
                          plStack_268 = (longlong *)0x0;
                          plStack_278 = (longlong *)0x0;
                          pcStack_280 = (code *)0x0;
                          plStack_240 = (longlong *)0x0;
                          plStack_258 = (longlong *)0x0;
                          *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                          plVar13 = (longlong *)0x0;
                          goto LAB_23e755c16;
                        }
                        pppppppcStack_318 = (code *******)0x23e7550b4;
                        iVar12 = FUN_23e913250(plVar13,DAT_23eed90d8);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          pppppppcStack_318 = (code *******)0x23e755a6a;
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        if (iVar12 == -1) {
                          auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
                          auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
                          apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
                          uVar40 = 0x359;
                          *(undefined8 *)(lVar15 + 0x70) = 0;
                          *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e7561e8;
                        }
                        lVar26 = *(longlong *)(DAT_23eed8950 + 0x20);
                        if (iVar12 == 1) {
                          if (*(char *)(lVar26 + 10) == '\0') {
                            pppppppcStack_318 = (code *******)0x23e756758;
                            puVar27 = (undefined8 *)FUN_23a37a020(DAT_23eed8950,_DAT_23eed9210);
                            if (puVar27 == (undefined8 *)0x0) goto LAB_23e756770;
                            plVar13 = (longlong *)*puVar27;
LAB_23e756760:
                            if (plVar13 == (longlong *)0x0) goto LAB_23e756770;
                          }
                          else {
                            iVar12 = *(int *)(lVar26 + 0xc);
                            if (*(int *)(lVar26 + 0xc) == 0) {
                              *(int *)(lVar26 + 0xc) = DAT_23ec1545c;
                              iVar12 = DAT_23ec1545c;
                              DAT_23ec1545c = DAT_23ec1545c + 1;
                            }
                            if (_DAT_23ec15430 != iVar12) {
                              pppppppcStack_318 = (code *******)0x23e756599;
                              _DAT_23ec15430 = iVar12;
                              _DAT_23eedadf0 =
                                   FUN_23e8cbd60(lVar26,_DAT_23eed9210,
                                                 *(undefined8 *)(_DAT_23eed9210 + 0x18));
                            }
                            if (-1 < _DAT_23eedadf0) {
                              lVar34 = lVar26 + 0x20 + (1L << (*(byte *)(lVar26 + 9) & 0x3f));
                              plVar13 = *(longlong **)(lVar34 + 8 + _DAT_23eedadf0 * 0x10);
                              if (plVar13 != (longlong *)0x0) goto LAB_23e755ad6;
                              pppppppcStack_318 = (code *******)0x23e757b86;
                              _DAT_23eedadf0 =
                                   FUN_23e8cbd60(lVar26,_DAT_23eed9210,
                                                 *(undefined8 *)(_DAT_23eed9210 + 0x18));
                              if (-1 < _DAT_23eedadf0) {
                                plVar13 = *(longlong **)(lVar34 + 8 + _DAT_23eedadf0 * 0x10);
                                goto LAB_23e756760;
                              }
                            }
LAB_23e756770:
                            pppppppcStack_318 = (code *******)0x23e756786;
                            puVar27 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9210);
                            if ((puVar27 == (undefined8 *)0x0) ||
                               (plVar13 = (longlong *)*puVar27, plVar13 == (longlong *)0x0)) {
                              pppppppcStack_318 = (code *******)0x23e7567ae;
                              FUN_23e915740(lVar15,auStack_1d0,_DAT_23eed9210);
                              uVar40 = 0x35a;
                              goto LAB_23e7561e8;
                            }
                          }
LAB_23e755ad6:
                          lVar34 = DAT_23eed8950;
                          *plVar13 = *plVar13 + 1;
                          lVar26 = *(longlong *)(lVar34 + 0x20);
                          if (*(char *)(lVar26 + 10) != '\0') {
                            iVar12 = *(int *)(lVar26 + 0xc);
                            if (*(int *)(lVar26 + 0xc) == 0) {
                              *(int *)(lVar26 + 0xc) = DAT_23ec1545c;
                              iVar12 = DAT_23ec1545c;
                              DAT_23ec1545c = DAT_23ec1545c + 1;
                            }
                            if (_DAT_23ec15434 != iVar12) {
                              pppppppcStack_318 = (code *******)0x23e7567e1;
                              _DAT_23ec15434 = iVar12;
                              _DAT_23eedadf8 =
                                   FUN_23e8cbd60(lVar26,_DAT_23eed9218,
                                                 *(undefined8 *)(_DAT_23eed9218 + 0x18));
                            }
                            if (-1 < _DAT_23eedadf8) {
                              lVar34 = lVar26 + 0x20 + (1L << (*(byte *)(lVar26 + 9) & 0x3f));
                              plVar17 = *(longlong **)(lVar34 + 8 + _DAT_23eedadf8 * 0x10);
                              if (plVar17 != (longlong *)0x0) goto LAB_23e755b4f;
                              pppppppcStack_318 = (code *******)0x23e757bb7;
                              _DAT_23eedadf8 =
                                   FUN_23e8cbd60(lVar26,_DAT_23eed9218,
                                                 *(undefined8 *)(_DAT_23eed9218 + 0x18));
                              if (-1 < _DAT_23eedadf8) {
                                plVar17 = *(longlong **)(lVar34 + 8 + _DAT_23eedadf8 * 0x10);
                                goto LAB_23e756801;
                              }
                            }
LAB_23e756810:
                            pppppppcStack_318 = (code *******)0x23e756826;
                            puVar27 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9218);
                            if ((puVar27 != (undefined8 *)0x0) &&
                               (plVar17 = (longlong *)*puVar27, plVar17 != (longlong *)0x0))
                            goto LAB_23e755b4f;
                            pppppppcStack_318 = (code *******)0x23e75684e;
                            FUN_23e915740(lVar15,auStack_1d0,_DAT_23eed9218);
                            uVar40 = 0x35b;
LAB_23e7563fc:
                            plStack_270 = (longlong *)0x0;
                            plVar37 = (longlong *)0x0;
                            plVar17 = (longlong *)0x0;
                            plVar29 = (longlong *)0x0;
                            plStack_248 = (longlong *)0x0;
                            plVar25 = (longlong *)0x0;
                            plStack_260 = (longlong *)0x0;
                            plStack_250 = (longlong *)0x0;
                            plStack_268 = (longlong *)0x0;
                            plStack_278 = (longlong *)0x0;
                            pcStack_280 = (code *)0x0;
                            plStack_240 = (longlong *)0x0;
                            plStack_258 = (longlong *)0x0;
                            goto LAB_23e755c16;
                          }
                          pppppppcStack_318 = (code *******)0x23e7567f9;
                          puVar27 = (undefined8 *)FUN_23a37a020(lVar34,_DAT_23eed9218);
                          if (puVar27 == (undefined8 *)0x0) goto LAB_23e756810;
                          plVar17 = (longlong *)*puVar27;
LAB_23e756801:
                          if (plVar17 == (longlong *)0x0) goto LAB_23e756810;
LAB_23e755b4f:
                          plVar25 = DAT_23eed9220;
                          plStack_258 = DAT_23eed9220;
                          *plVar17 = *plVar17 + 1;
                          *plVar25 = *plVar25 + 1;
                        }
                        else {
                          if (*(char *)(lVar26 + 10) == '\0') {
                            pppppppcStack_318 = (code *******)0x23e7562fc;
                            puVar27 = (undefined8 *)FUN_23a37a020(DAT_23eed8950,_DAT_23eed9228);
                            if (puVar27 == (undefined8 *)0x0) goto LAB_23e756310;
                            plVar13 = (longlong *)*puVar27;
LAB_23e756304:
                            if (plVar13 == (longlong *)0x0) goto LAB_23e756310;
                          }
                          else {
                            iVar12 = *(int *)(lVar26 + 0xc);
                            if (*(int *)(lVar26 + 0xc) == 0) {
                              *(int *)(lVar26 + 0xc) = DAT_23ec1545c;
                              iVar12 = DAT_23ec1545c;
                              DAT_23ec1545c = DAT_23ec1545c + 1;
                            }
                            if (_DAT_23ec15438 != iVar12) {
                              pppppppcStack_318 = (code *******)0x23e756289;
                              _DAT_23ec15438 = iVar12;
                              _DAT_23eedae00 =
                                   FUN_23e8cbd60(lVar26,_DAT_23eed9228,
                                                 *(undefined8 *)(_DAT_23eed9228 + 0x18));
                            }
                            if (-1 < _DAT_23eedae00) {
                              lVar34 = lVar26 + 0x20 + (1L << (*(byte *)(lVar26 + 9) & 0x3f));
                              plVar13 = *(longlong **)(lVar34 + 8 + _DAT_23eedae00 * 0x10);
                              if (plVar13 != (longlong *)0x0) goto LAB_23e755149;
                              pppppppcStack_318 = (code *******)0x23e757648;
                              _DAT_23eedae00 =
                                   FUN_23e8cbd60(lVar26,_DAT_23eed9228,
                                                 *(undefined8 *)(_DAT_23eed9228 + 0x18));
                              if (-1 < _DAT_23eedae00) {
                                plVar13 = *(longlong **)(lVar34 + 8 + _DAT_23eedae00 * 0x10);
                                goto LAB_23e756304;
                              }
                            }
LAB_23e756310:
                            pppppppcStack_318 = (code *******)0x23e756326;
                            puVar27 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9228);
                            if ((puVar27 == (undefined8 *)0x0) ||
                               (plVar13 = (longlong *)*puVar27, plVar13 == (longlong *)0x0)) {
                              pppppppcStack_318 = (code *******)0x23e75634e;
                              FUN_23e915740(lVar15,auStack_1d0,_DAT_23eed9228);
                              uVar40 = 0x35e;
                              goto LAB_23e7561e8;
                            }
                          }
LAB_23e755149:
                          lVar34 = DAT_23eed8950;
                          *plVar13 = *plVar13 + 1;
                          lVar26 = *(longlong *)(lVar34 + 0x20);
                          if (*(char *)(lVar26 + 10) == '\0') {
                            pppppppcStack_318 = (code *******)0x23e75639c;
                            puVar27 = (undefined8 *)FUN_23a37a020(lVar34,_DAT_23eed9230);
                            if (puVar27 == (undefined8 *)0x0) goto LAB_23e7563b0;
                            plVar17 = (longlong *)*puVar27;
LAB_23e7563a4:
                            if (plVar17 == (longlong *)0x0) goto LAB_23e7563b0;
                          }
                          else {
                            iVar12 = *(int *)(lVar26 + 0xc);
                            if (*(int *)(lVar26 + 0xc) == 0) {
                              *(int *)(lVar26 + 0xc) = DAT_23ec1545c;
                              iVar12 = DAT_23ec1545c;
                              DAT_23ec1545c = DAT_23ec1545c + 1;
                            }
                            if (_DAT_23ec1543c != iVar12) {
                              pppppppcStack_318 = (code *******)0x23e756381;
                              _DAT_23ec1543c = iVar12;
                              _DAT_23eedae08 =
                                   FUN_23e8cbd60(lVar26,_DAT_23eed9230,
                                                 *(undefined8 *)(_DAT_23eed9230 + 0x18));
                            }
                            if (-1 < _DAT_23eedae08) {
                              lVar34 = lVar26 + 0x20 + (1L << (*(byte *)(lVar26 + 9) & 0x3f));
                              plVar17 = *(longlong **)(lVar34 + 8 + _DAT_23eedae08 * 0x10);
                              if (plVar17 != (longlong *)0x0) goto LAB_23e7551c2;
                              pppppppcStack_318 = (code *******)0x23e757679;
                              _DAT_23eedae08 =
                                   FUN_23e8cbd60(lVar26,_DAT_23eed9230,
                                                 *(undefined8 *)(_DAT_23eed9230 + 0x18));
                              if (-1 < _DAT_23eedae08) {
                                plVar17 = *(longlong **)(lVar34 + 8 + _DAT_23eedae08 * 0x10);
                                goto LAB_23e7563a4;
                              }
                            }
LAB_23e7563b0:
                            pppppppcStack_318 = (code *******)0x23e7563c6;
                            puVar27 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9230);
                            if ((puVar27 == (undefined8 *)0x0) ||
                               (plVar17 = (longlong *)*puVar27, plVar17 == (longlong *)0x0)) {
                              pppppppcStack_318 = (code *******)0x23e7563ee;
                              FUN_23e915740(lVar15,auStack_1d0,_DAT_23eed9230);
                              uVar40 = 0x35f;
                              goto LAB_23e7563fc;
                            }
                          }
LAB_23e7551c2:
                          plStack_258 = _DAT_23eed9238;
                          *plVar17 = *plVar17 + 1;
                          *plStack_258 = *plStack_258 + 1;
                        }
                        pppppppcStack_318 = (code *******)0x23e7551df;
                        lVar26 = FUN_23e8e0270();
                        if (lVar26 == 0) {
                          pppppppcStack_318 = (code *******)0x23e756ac7;
                          FUN_23e915740(lVar15,auStack_1d0,_DAT_23eed9160);
                          plVar25 = (longlong *)0x0;
                        }
                        else {
                          *(undefined4 *)(ppppppcVar4 + 5) = 0x363;
                          plStack_1a0 = plStack_258;
                          pplStack_1e0 = &plStack_1b0;
                          pppppppcStack_318 = (code *******)0x23e755230;
                          plStack_1b0 = plVar13;
                          plStack_1a8 = plVar17;
                          plVar25 = (longlong *)FUN_23e956150(lVar15,lVar26,pplStack_1e0);
                          if (plVar25 != (longlong *)0x0) {
                            pppppppcStack_318 = (code *******)0x23e755241;
                            plStack_240 = (longlong *)FUN_23e8e0ba0();
                            if (plStack_240 == (longlong *)0x0) {
                              pppppppcStack_318 = (code *******)0x23e756ae8;
                              FUN_23e915740(lVar15,auStack_1d0,DAT_23eed8c70);
LAB_23e756af0:
                              plStack_270 = (longlong *)0x0;
                              plVar37 = (longlong *)0x0;
                              plVar29 = (longlong *)0x0;
                              uVar40 = 0x368;
                              plStack_248 = (longlong *)0x0;
                              plStack_260 = (longlong *)0x0;
                              plStack_250 = (longlong *)0x0;
                              plStack_268 = (longlong *)0x0;
                              plStack_278 = (longlong *)0x0;
                              pcStack_280 = (code *)0x0;
                              goto LAB_23e755c16;
                            }
                            *(undefined4 *)(ppppppcVar4 + 5) = 0x368;
                            pppppppcStack_318 = (code *******)0x23e75526b;
                            puVar27 = (undefined8 *)FUN_23e91bfe0(lVar15,plStack_240);
                            pcVar43 = PyFloat_Type_exref;
                            if (puVar27 == (undefined8 *)0x0) {
                              auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
                              auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
                              apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
                              plVar37 = (longlong *)0x0;
                              plVar29 = (longlong *)0x0;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uVar40 = 0x368;
                              plStack_270 = (longlong *)0x0;
                              plStack_248 = (longlong *)0x0;
                              plStack_260 = (longlong *)0x0;
                              plStack_250 = (longlong *)0x0;
                              plStack_268 = (longlong *)0x0;
                              plStack_278 = (longlong *)0x0;
                              plStack_240 = (longlong *)0x0;
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              pcStack_280 = (code *)0x0;
                              goto LAB_23e755c16;
                            }
                            pcStack_280 = (code *)puVar27;
                            if ((code *)puVar27[1] == PyFloat_Type_exref) {
                              dVar2 = (double)puVar27[2];
                              dVar3 = *(double *)(DAT_23eed8b20 + 0x10);
                              lVar26 = *(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10)
                              ;
                              plStack_240 = *(longlong **)(lVar26 + 0xe08);
                              if (plStack_240 == (longlong *)0x0) {
                                pppppppcStack_318 = (code *******)0x23e757be5;
                                plStack_240 = (longlong *)(*DAT_23ed6ccd0)(0,0x18);
                              }
                              else {
                                lVar34 = plStack_240[1];
                                *(int *)(lVar26 + 0xe00) = *(int *)(lVar26 + 0xe00) + -1;
                                *(longlong *)(lVar26 + 0xe08) = lVar34;
                              }
                              pcVar35 = pcStack_280;
                              plStack_240[1] = (longlong)pcVar43;
                              *plStack_240 = 1;
                              plStack_240[2] = (longlong)(dVar3 + dVar2);
                              pcVar43 = *(code **)pcStack_280;
                              *(code **)pcStack_280 = pcVar43 + -1;
                              if (pcVar43 + -1 == (code *)0x0) {
                                plVar29 = (longlong *)((longlong)pcStack_280 + 8);
                                pppppppcStack_318 = (code *******)0x23e7574c4;
                                pcStack_280 = pcVar43;
                                (**(code **)(*plVar29 + 0x30))(pcVar35);
                                pcVar43 = pcStack_280;
                              }
                            }
                            else {
                              pppppppcStack_318 = (code *******)0x23e75529f;
                              plStack_240 = (longlong *)FUN_23e8bfcd0(puVar27);
                              pcStack_280 = (code *)*puVar27;
                              *puVar27 = pcStack_280 + -1;
                              if (pcStack_280 + -1 == (code *)0x0) {
                                pppppppcStack_318 = (code *******)0x23e7564db;
                                (**(code **)(puVar27[1] + 0x30))(puVar27);
                              }
                              pcVar43 = pcStack_280;
                              if (plStack_240 == (longlong *)0x0) {
                                auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
                                auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
                                apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
                                *(undefined8 *)(lVar15 + 0x70) = 0;
                                *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e756af0;
                              }
                            }
                            pcStack_280 = pcVar43;
                            if (pppppppcVar22 != (code *******)0x0) {
                              plStack_270 = (longlong *)0x0;
                              plStack_248 = (longlong *)0x0;
                              plStack_260 = (longlong *)0x0;
                              plStack_250 = (longlong *)0x0;
                              plStack_268 = (longlong *)0x0;
                              plStack_278 = (longlong *)0x0;
                              plStack_210 = (longlong *)0x0;
                              plStack_208 = (longlong *)0x0;
                              pcVar43 = (code *)0x0;
                              pppppppcStack_230 = pppppppcVar22;
                              plStack_1f8 = plVar25;
                              plStack_1f0 = plVar13;
                              plStack_1e8 = plVar17;
                              goto LAB_23e755363;
                            }
                            pppppppcStack_318 = (code *******)0x23e75775f;
                            auStack_1d0._8_8_ =
                                 PyUnicode_FromFormat
                                           ("cannot access local variable \'%U\' where it is not associated with a value"
                                            ,DAT_23eed8d30);
                            auStack_1d0._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                            *(longlong *)auStack_1d0._0_8_ = *(longlong *)auStack_1d0._0_8_ + 1;
                            apppppppcStack_1c0[0] = (code *******)0x0;
                            if ((code *)auStack_1d0._0_8_ != _Py_NoneStruct_exref) {
                              pppppppcStack_318 = (code *******)0x23e7577bb;
                              FUN_23e91b1b0(lVar15,auStack_1d0,auStack_1d0 + 8,apppppppcStack_1c0);
                            }
                            plVar37 = (longlong *)0x0;
                            plVar29 = (longlong *)0x0;
                            pppppppcStack_318 = (code *******)0x23e7577d5;
                            FUN_23ebf6a40(*(undefined8 *)(lVar15 + 0x138),auStack_1d0._8_8_);
                            plStack_270 = (longlong *)0x0;
                            uVar40 = 0x369;
                            plStack_248 = (longlong *)0x0;
                            plStack_260 = (longlong *)0x0;
                            plStack_250 = (longlong *)0x0;
                            plStack_268 = (longlong *)0x0;
                            plStack_278 = (longlong *)0x0;
                            pcStack_280 = (code *)0x0;
                            goto LAB_23e755c16;
                          }
                          apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
                          auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
                          auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
                          *(undefined8 *)(lVar15 + 0x70) = 0;
                          *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                        }
                        plStack_270 = (longlong *)0x0;
                        plVar37 = (longlong *)0x0;
                        plVar29 = (longlong *)0x0;
                        uVar40 = 0x363;
                        plStack_248 = (longlong *)0x0;
                        plStack_260 = (longlong *)0x0;
                        plStack_250 = (longlong *)0x0;
                        plStack_268 = (longlong *)0x0;
                        plStack_278 = (longlong *)0x0;
                        pcStack_280 = (code *)0x0;
                        plStack_240 = (longlong *)0x0;
                        goto LAB_23e755c16;
                      }
LAB_23e754960:
                      pppppppcVar22 = (code *******)&local_88;
                      plStack_80 = plVar17;
                      pppppppcStack_140 = (code *******)0x23e754985;
                      local_d0 = local_d8;
                      local_d8 = pppppppcVar22;
                      local_88 = pppppppcVar19;
                      pppppppcVar21 = (code *******)FUN_23e94ed00(param_1,DAT_23ed6a4c0);
                      *pppppppcVar19 = (code ******)((longlong)*pppppppcVar19 + -1);
                      if (*pppppppcVar19 == (code ******)0x0) {
                        pppppppcStack_140 = (code *******)0x23e7549a1;
                        local_a8 = pppppppcVar21;
                        FUN_23a334bc0(pppppppcVar19);
                        pppppppcVar21 = local_a8;
                      }
                      pppppppcVar23 = local_c0;
                      plVar25 = DAT_23ed6a4c0;
                      pppppppcVar20 = local_d0;
                      if (pppppppcVar21 != (code *******)0x0) {
                        local_d0[4] = (code ******)pppppppcVar21;
                        ppppppcVar24 = _DAT_23eed91f8;
                        *_DAT_23eed91f8 = (code *****)((longlong)*_DAT_23eed91f8 + 1);
                        local_d0[5] = ppppppcVar24;
                        plVar17 = DAT_23ed6cd28;
                        if (plVar25 == (longlong *)0x0) {
                          pppppppcStack_140 = (code *******)0x23e754c1b;
                          plVar25 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                          pppppppcStack_190 = pppppppcVar23;
                          if (plVar25 == (longlong *)0x0) goto LAB_23e754cb4;
                          *plVar25 = *plVar25 + 1;
                          DAT_23ed6a4c0 = plVar25;
                        }
                        local_88 = pppppppcVar23;
                        plStack_80 = plVar17;
                        pppppppcStack_140 = (code *******)0x23e754a01;
                        ppppppcVar24 = (code ******)FUN_23e94ed00(param_1,plVar25,local_d8);
                        pppppppcVar20 = local_d0;
                        if (ppppppcVar24 != (code ******)0x0) {
                          local_d0[6] = ppppppcVar24;
                          ppppppcVar24 = _DAT_23eed9200;
                          local_d8 = local_d0;
                          *_DAT_23eed9200 = (code *****)((longlong)*_DAT_23eed9200 + 1);
                          local_d0[7] = ppppppcVar24;
                          pppppppcStack_140 = (code *******)0x23e754a3b;
                          plVar17 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,local_d0);
                          *local_d8 = (code ******)((longlong)*local_d8 + -1);
                          if (*local_d8 == (code ******)0x0) {
                            pppppppcStack_140 = (code *******)0x23e754a51;
                            FUN_23a334bc0();
                          }
                          if (plVar17 != (longlong *)0x0) {
                            *(undefined4 *)(pppppppcVar39 + 5) = 0x34c;
                            pppppppcStack_140 = (code *******)0x23e754a6f;
                            plVar25 = (longlong *)FUN_23e914090(param_1,plVar13,plVar17);
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              pppppppcStack_140 = (code *******)0x23e754a81;
                              FUN_23a334bc0(plVar13);
                            }
                            *plVar17 = *plVar17 + -1;
                            if (*plVar17 == 0) {
                              pppppppcStack_140 = (code *******)0x23e754a90;
                              FUN_23a334bc0(plVar17);
                            }
                            if (plVar25 != (longlong *)0x0) {
                              *plVar25 = *plVar25 + -1;
                              if (*plVar25 == 0) {
                                pppppppcStack_140 = (code *******)0x23e754aa7;
                                FUN_23a334bc0(plVar25);
                              }
                              local_d8 = (code *******)local_a0;
                              local_d0 = local_c0;
                              pppppppcVar20 = local_c8;
                              pppppppcVar39 = local_b0;
                              goto LAB_23e75461c;
                            }
                            goto LAB_23e754bd6;
                          }
                          local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          local_68[0] = *(code ********)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            pppppppcStack_140 = (code *******)0x23e754ca7;
                            FUN_23a334bc0(plVar13);
                          }
                          goto LAB_23e754b8e;
                        }
                      }
                    }
                    local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    local_68[0] = *(code ********)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      pppppppcStack_140 = (code *******)0x23e754b73;
                      local_d8 = pppppppcVar20;
                      FUN_23a334bc0(plVar13);
                      pppppppcVar20 = local_d8;
                    }
                    *pppppppcVar20 = (code ******)((longlong)*pppppppcVar20 + -1);
                    if (*pppppppcVar20 == (code ******)0x0) {
                      pppppppcStack_140 = (code *******)0x23e754b86;
                      FUN_23a334bc0(pppppppcVar20);
                    }
                  }
LAB_23e754b8e:
                  uVar40 = 0x34c;
                  pppppppcVar20 = local_c8;
                  pppppppcVar22 = local_b0;
                  pppppppcVar19 = DAT_23ed6a4f8;
                  local_d8 = (code *******)local_a0;
                  local_d0 = local_c0;
                  pppppppcVar21 = local_c8;
                  goto joined_r0x00023e753487;
                }
                lVar15 = *(longlong *)(param_1 + 0x10);
                if ((*(int *)(*(longlong *)(lVar15 + 0x28) + 0x160) != 0) ||
                   (*(int *)(lVar15 + 0x78) != 0)) {
                  pppppppcStack_140 = (code *******)0x23e753386;
                  iVar12 = Py_MakePendingCalls();
                  if ((iVar12 < 0) &&
                     (pppppppcVar39 = local_c0, pppppppcVar16 = local_98, pppppppcVar14 = local_90,
                     pppppppcVar36 = local_b0, *(longlong *)(param_1 + 0x60) != 0))
                  goto LAB_23e7533e0;
                }
                if (*(int *)(lVar15 + 0x68) != 0) {
                  pppppppcStack_140 = (code *******)0x23e753a4e;
                  PyEval_SaveThread();
                  pppppppcStack_140 = (code *******)0x23e753a5c;
                  PyEval_AcquireThread(param_1);
                }
                pppppppcVar14 = local_90;
                pppppppcVar16 = local_98;
                pppppppcVar36 = local_b0;
                pppppppcVar39 = local_c0;
                plVar13 = *(longlong **)(param_1 + 0x90);
                pppppppcVar20 = local_c8;
              } while (plVar13 == (longlong *)0x0);
              plVar17 = *(longlong **)(param_1 + 0x60);
              plVar25 = *(longlong **)(param_1 + 0x70);
              plVar29 = *(longlong **)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x90) = 0;
              *(longlong **)(param_1 + 0x60) = plVar13;
              *plVar13 = *plVar13 + 1;
              *(undefined8 *)(param_1 + 0x68) = 0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_c0 = pppppppcVar18;
              local_b0 = pppppppcVar22;
              local_a0 = (code ******)pppppppcVar23;
              if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                pppppppcStack_140 = (code *******)0x23e754303;
                (**(code **)(plVar17[1] + 0x30))();
              }
              if ((plVar29 != (longlong *)0x0) && (*plVar29 = *plVar29 + -1, *plVar29 == 0)) {
                pppppppcStack_140 = (code *******)0x23e754319;
                (**(code **)(plVar29[1] + 0x30))(plVar29);
              }
              pppppppcVar18 = local_c0;
              pppppppcVar22 = local_b0;
              pppppppcVar23 = (code *******)local_a0;
              if ((plVar25 != (longlong *)0x0) && (*plVar25 = *plVar25 + -1, *plVar25 == 0)) {
                pppppppcStack_140 = (code *******)0x23e754336;
                (**(code **)(plVar25[1] + 0x30))(plVar25);
                pppppppcVar18 = local_c0;
                pppppppcVar22 = local_b0;
                pppppppcVar23 = (code *******)local_a0;
              }
LAB_23e7533e0:
              local_a0 = (code ******)pppppppcVar23;
              local_b0 = pppppppcVar22;
              local_c0 = pppppppcVar18;
              local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
              uVar40 = 0x342;
              local_68[0] = *(code ********)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pppppppcVar20 = local_c8;
              pppppppcVar22 = local_b0;
              pppppppcVar19 = DAT_23ed6a4f8;
              local_d8 = (code *******)local_a0;
              local_d0 = local_c0;
              pppppppcVar21 = local_c8;
              local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
            }
          }
          goto joined_r0x00023e753487;
        }
        local_68[0] = *(code ********)(param_1 + 0x70);
        local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      pppppppcVar22 = (code *******)0x0;
      pppppppcVar20 = (code *******)0x0;
      pppppppcVar14 = (code *******)0x0;
      uVar40 = 0x33c;
      local_d8 = (code *******)0x0;
      local_d0 = (code *******)0x0;
      pppppppcVar19 = DAT_23ed6a4f8;
      pppppppcVar21 = local_c8;
      goto joined_r0x00023e753487;
    }
    local_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    local_68[0] = *(code ********)(param_1 + 0x70);
    uVar40 = 0x336;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  pppppppcVar22 = (code *******)0x0;
  pppppppcVar20 = (code *******)0x0;
  pppppppcVar14 = (code *******)0x0;
  pppppppcVar16 = (code *******)0x0;
  local_d8 = (code *******)0x0;
  local_d0 = (code *******)0x0;
  local_e0 = (code ******)0x0;
  pppppppcVar19 = DAT_23ed6a4f8;
  pppppppcVar21 = local_c8;
joined_r0x00023e753487:
  local_c8._4_4_ = (undefined4)((ulonglong)pppppppcVar21 >> 0x20);
  DAT_23ed6a4f8 = pppppppcVar19;
  local_c8 = pppppppcVar21;
  if (local_68[0] == (code *******)0x0) {
    if (pppppppcVar19 == (code *******)0x0) {
      local_c8 = (code *******)CONCAT44(local_c8._4_4_,uVar40);
      pppppppcStack_140 = (code *******)0x23e753b61;
      pppppppcVar19 = (code *******)FUN_23a33a530(PyTraceBack_Type_exref);
      uVar40 = SUB84(local_c8,0);
    }
    else {
      DAT_23ed6a4f8 = (code *******)*pppppppcVar19;
      *pppppppcVar19 = (code ******)0x1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar43 = _PyRuntime_exref;
    pppppppcVar19[2] = (code ******)0x0;
    pppppppcVar19[3] = (code ******)pppppppcVar39;
    *pppppppcVar39 = (code ******)((longlong)*pppppppcVar39 + 1);
    lVar15 = *(longlong *)(pcVar43 + 0x1f8);
    *(undefined4 *)((longlong)pppppppcVar19 + 0x24) = uVar40;
    lVar15 = *(longlong *)(lVar15 + 0x10);
    *(undefined4 *)(pppppppcVar19 + 4) = 0xffffffff;
    ppppppcVar24 = *(code *******)(lVar15 + 0x2e8);
    ppppppcVar4 = pppppppcVar19[-1];
    pppppcVar44 = ppppppcVar24[1];
    *pppppcVar44 = (code ****)(pppppppcVar19 + -2);
    pppppppcVar19[-2] = ppppppcVar24;
    pppppppcVar19[-1] = (code ******)((ulonglong)((uint)ppppppcVar4 & 3) | (ulonglong)pppppcVar44);
    ppppppcVar24[1] = (code *****)(pppppppcVar19 + -2);
    pppppppcVar21 = local_c8;
    pppppppcVar23 = pppppppcVar19;
    if ((local_68[0] != (code *******)0x0) &&
       (*local_68[0] = (code ******)((longlong)*local_68[0] + -1), *local_68[0] == (code ******)0x0)
       ) {
      pppppppcStack_140 = (code *******)0x23e752bec;
      local_c8 = pppppppcVar19;
      (*(code *)local_68[0][1][6])(local_68[0]);
      pppppppcVar21 = local_c8;
      pppppppcVar23 = local_c8;
    }
  }
  else {
    pppppppcVar23 = local_68[0];
    if (*(code ********)((longlong)local_68[0] + 0x18) != pppppppcVar39) {
      if (pppppppcVar19 == (code *******)0x0) {
        local_c8 = (code *******)CONCAT44(local_c8._4_4_,uVar40);
        pppppppcStack_140 = (code *******)0x23e75393e;
        local_c0 = local_68[0];
        pppppppcVar19 = (code *******)FUN_23a33a530(PyTraceBack_Type_exref);
        uVar40 = SUB84(local_c8,0);
        pppppppcVar21 = local_c0;
      }
      else {
        DAT_23ed6a4f8 = (code *******)*pppppppcVar19;
        *pppppppcVar19 = (code ******)0x1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        pppppppcVar21 = local_68[0];
      }
      pcVar43 = _PyRuntime_exref;
      pppppppcVar19[3] = (code ******)pppppppcVar39;
      *pppppppcVar39 = (code ******)((longlong)*pppppppcVar39 + 1);
      lVar15 = *(longlong *)(pcVar43 + 0x1f8);
      *(undefined4 *)((longlong)pppppppcVar19 + 0x24) = uVar40;
      *(undefined4 *)(pppppppcVar19 + 4) = 0xffffffff;
      ppppppcVar24 = *(code *******)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
      ppppppcVar4 = pppppppcVar19[-1];
      pppppcVar44 = ppppppcVar24[1];
      *pppppcVar44 = (code ****)(pppppppcVar19 + -2);
      pppppppcVar19[-2] = ppppppcVar24;
      pppppppcVar19[-1] = (code ******)((ulonglong)((uint)ppppppcVar4 & 3) | (ulonglong)pppppcVar44)
      ;
      ppppppcVar24[1] = (code *****)(pppppppcVar19 + -2);
      pppppppcVar19[2] = (code ******)pppppppcVar21;
      *pppppppcVar21 = (code ******)((longlong)*pppppppcVar21 + 1);
      pppppppcVar21 = local_c8;
      pppppppcVar23 = pppppppcVar19;
      if ((local_68[0] != (code *******)0x0) &&
         (*local_68[0] = (code ******)((longlong)*local_68[0] + -1),
         *local_68[0] == (code ******)0x0)) {
        pppppppcStack_140 = (code *******)0x23e75353d;
        local_c8 = pppppppcVar19;
        (*(code *)local_68[0][1][6])(local_68[0]);
        pppppppcVar21 = local_c8;
        pppppppcVar23 = local_c8;
      }
    }
  }
  local_68[0] = pppppppcVar23;
  local_c8 = pppppppcVar21;
  local_f8 = (code ******)local_d8;
  local_100 = local_d0;
  pppppppcStack_140 = (code *******)0x23e753589;
  local_118 = pppppppcVar16;
  local_110 = pppppppcVar14;
  local_108 = pppppppcVar20;
  local_f0 = pppppppcVar22;
  FUN_23e8bba40(pppppppcVar39,"oooooooo",pppppppcVar36,local_e0);
  if (_DAT_23eedae18 == pppppppcVar39) {
    *pppppppcVar39 = (code ******)((longlong)*pppppppcVar39 + -1);
    if (*pppppppcVar39 == (code ******)0x0) {
      pppppppcStack_140 = (code *******)0x23e753748;
      (*(code *)(*(code *******)((longlong)pppppppcVar39 + 8))[6])(pppppppcVar39);
    }
    _DAT_23eedae18 = (code *******)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar13 = *(longlong **)(lVar15 + 0x28);
  plVar17 = (longlong *)plVar13[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
  if (plVar17 != (longlong *)0x0) {
    plVar13[2] = 0;
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      pppppppcStack_140 = (code *******)0x23e7535cf;
      (**(code **)(plVar17[1] + 0x30))();
    }
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    pppppppcStack_140 = (code *******)0x23e7535df;
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  pppppppcVar39 = local_68[0];
  uVar46 = local_78._8_8_;
  uVar45 = local_78._0_8_;
  ppppppcVar4 = local_e0;
  plVar13[0xf] = 0;
  local_78 = (undefined1  [16])0x0;
  local_68[0] = (code *******)0x0;
  ppppppcVar24 = local_e0;
  if (local_e0 != (code ******)0x0) {
    ppppppcVar24 = (code ******)*local_e0;
    *local_e0 = (code *****)((longlong)ppppppcVar24 + -1);
    if ((code *****)((longlong)ppppppcVar24 + -1) == (code *****)0x0) {
      ppppppcVar5 = local_e0 + 1;
      pppppppcStack_140 = (code *******)0x23e753635;
      local_e0 = ppppppcVar24;
      (*(code *)(*ppppppcVar5)[6])(ppppppcVar4);
      ppppppcVar24 = local_e0;
    }
  }
  local_e0 = ppppppcVar24;
  if ((pppppppcVar16 != (code *******)0x0) &&
     (*pppppppcVar16 = (code ******)((longlong)*pppppppcVar16 + -1),
     *pppppppcVar16 == (code ******)0x0)) {
    pppppppcStack_140 = (code *******)0x23e75364b;
    (*(code *)(*(code *******)((longlong)pppppppcVar16 + 8))[6])(pppppppcVar16);
  }
  if ((pppppppcVar14 != (code *******)0x0) &&
     (*pppppppcVar14 = (code ******)((longlong)*pppppppcVar14 + -1),
     *pppppppcVar14 == (code ******)0x0)) {
    pppppppcStack_140 = (code *******)0x23e753660;
    (*(code *)(*(code *******)((longlong)pppppppcVar14 + 8))[6])(pppppppcVar14);
  }
  if ((pppppppcVar20 != (code *******)0x0) &&
     (*pppppppcVar20 = (code ******)((longlong)*pppppppcVar20 + -1),
     *pppppppcVar20 == (code ******)0x0)) {
    pppppppcStack_140 = (code *******)0x23e753677;
    (*(code *)(*(code *******)((longlong)pppppppcVar20 + 8))[6])(pppppppcVar20);
  }
  if (local_d0 != (code *******)0x0) {
    local_e0 = *local_d0;
    *local_d0 = (code ******)((longlong)local_e0 + -1);
    if ((code ******)((longlong)local_e0 + -1) == (code ******)0x0) {
      pppppppcStack_140 = (code *******)0x23e75369c;
      (*(code *)local_d0[1][6])(local_d0);
    }
  }
  if (local_d8 != (code *******)0x0) {
    local_e0 = *local_d8;
    *local_d8 = (code ******)((longlong)local_e0 + -1);
    if ((code *****)((longlong)local_e0 + -1) == (code *****)0x0) {
      pppppppcStack_140 = (code *******)0x23e7536c1;
      (*(code *)local_d8[1][6])(local_d8);
    }
  }
  if ((pppppppcVar22 != (code *******)0x0) &&
     (*pppppppcVar22 = (code ******)((longlong)*pppppppcVar22 + -1),
     *pppppppcVar22 == (code ******)0x0)) {
    pppppppcStack_140 = (code *******)0x23e7536d7;
    (*(code *)(*(code *******)((longlong)pppppppcVar22 + 8))[6])(pppppppcVar22);
  }
  *pppppppcVar36 = (code ******)((longlong)*pppppppcVar36 + -1);
  local_68[0] = pppppppcVar39;
  local_78._0_8_ = uVar45;
  local_78._8_8_ = uVar46;
  if (*pppppppcVar36 == (code ******)0x0) {
    pppppppcStack_140 = (code *******)0x23e75371a;
    (*(code *)(*(code *******)((longlong)pppppppcVar36 + 8))[6])(pppppppcVar36);
  }
  pppppppcStack_140 = (code *******)0x23e753705;
  FUN_23a33aa70(param_1,local_78._0_8_,local_78._8_8_,local_68[0]);
  return (code *******)0x0;
LAB_23e755363:
  pppppppcStack_318 = (code *******)0x23e755377;
  plVar13 = (longlong *)FUN_23e8bc2f0(pppppppcStack_230,DAT_23eed89b0);
  if (plVar13 == (longlong *)0x0) {
LAB_23e756610:
    auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
    auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
    apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
    uVar40 = 0x369;
    *(undefined8 *)(lVar15 + 0x70) = 0;
    *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
    plVar17 = plStack_1e8;
    plVar13 = plStack_1f0;
    plVar37 = plStack_208;
    plVar29 = plStack_210;
    plVar25 = plStack_1f8;
    pppppppcVar22 = pppppppcStack_230;
    pcStack_280 = pcVar43;
LAB_23e755c16:
    uVar41 = uVar40;
    if (apppppppcStack_1c0[0] == (code *******)0x0) {
LAB_23e754f90:
      pppppppcVar36 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *******)0x0) {
        pppppppcStack_238 = (code *******)CONCAT44(pppppppcStack_238._4_4_,uVar40);
        pppppppcStack_318 = (code *******)0x23e756a04;
        pppppppcVar36 = (code *******)FUN_23a33a530(PyTraceBack_Type_exref);
        uVar40 = SUB84(pppppppcStack_238,0);
      }
      else {
        pppppppcVar14 = (code *******)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = (code ******)0x1;
        DAT_23ed6a4f8 = pppppppcVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar43 = _PyRuntime_exref;
      pppppppcVar36[2] = (code ******)0x0;
      pppppppcVar36[3] = ppppppcVar4;
      *ppppppcVar4 = (code *****)((longlong)*ppppppcVar4 + 1);
      lVar26 = *(longlong *)(pcVar43 + 0x1f8);
      *(undefined4 *)((longlong)pppppppcVar36 + 0x24) = uVar40;
      lVar26 = *(longlong *)(lVar26 + 0x10);
      *(undefined4 *)(pppppppcVar36 + 4) = 0xffffffff;
      ppppppcVar24 = *(code *******)(lVar26 + 0x2e8);
      ppppppcVar5 = pppppppcVar36[-1];
      pppppcVar44 = ppppppcVar24[1];
      *pppppcVar44 = (code ****)(pppppppcVar36 + -2);
      pppppppcVar36[-2] = ppppppcVar24;
      pppppppcVar36[-1] = (code ******)((ulonglong)((uint)ppppppcVar5 & 3) | (ulonglong)pppppcVar44)
      ;
      ppppppcVar24[1] = (code *****)(pppppppcVar36 + -2);
      if ((apppppppcStack_1c0[0] != (code *******)0x0) &&
         (*apppppppcStack_1c0[0] = (code ******)((longlong)*apppppppcStack_1c0[0] + -1),
         *apppppppcStack_1c0[0] == (code ******)0x0)) {
        pppppppcStack_318 = (code *******)0x23e75503f;
        pppppppcStack_238 = pppppppcVar36;
        (*(code *)apppppppcStack_1c0[0][1][6])(apppppppcStack_1c0[0]);
        pppppppcVar36 = pppppppcStack_238;
      }
    }
    else {
LAB_23e755c1f:
      pppppppcVar14 = DAT_23ed6a4f8;
      pppppppcVar36 = apppppppcStack_1c0[0];
      if (apppppppcStack_1c0[0][3] != ppppppcVar4) {
        if (DAT_23ed6a4f8 == (code *******)0x0) {
          pppppppcStack_238 = (code *******)CONCAT44(pppppppcStack_238._4_4_,uVar41);
          pppppppcStack_318 = (code *******)0x23e75649c;
          pppppppcStack_230 = apppppppcStack_1c0[0];
          pppppppcVar14 = (code *******)FUN_23a33a530(PyTraceBack_Type_exref);
          uVar41 = SUB84(pppppppcStack_238,0);
          pppppppcVar36 = pppppppcStack_230;
        }
        else {
          pppppppcVar36 = (code *******)*DAT_23ed6a4f8;
          *DAT_23ed6a4f8 = (code ******)0x1;
          DAT_23ed6a4f8 = pppppppcVar36;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          pppppppcVar36 = apppppppcStack_1c0[0];
        }
        pcVar43 = _PyRuntime_exref;
        pppppppcVar14[3] = ppppppcVar4;
        *ppppppcVar4 = (code *****)((longlong)*ppppppcVar4 + 1);
        lVar26 = *(longlong *)(pcVar43 + 0x1f8);
        *(undefined4 *)((longlong)pppppppcVar14 + 0x24) = uVar41;
        *(undefined4 *)(pppppppcVar14 + 4) = 0xffffffff;
        ppppppcVar24 = *(code *******)(*(longlong *)(lVar26 + 0x10) + 0x2e8);
        ppppppcVar5 = pppppppcVar14[-1];
        pppppcVar44 = ppppppcVar24[1];
        *pppppcVar44 = (code ****)(pppppppcVar14 + -2);
        pppppppcVar14[-2] = ppppppcVar24;
        pppppppcVar14[-1] =
             (code ******)((ulonglong)((uint)ppppppcVar5 & 3) | (ulonglong)pppppcVar44);
        ppppppcVar24[1] = (code *****)(pppppppcVar14 + -2);
        pppppppcVar14[2] = (code ******)pppppppcVar36;
        *pppppppcVar36 = (code ******)((longlong)*pppppppcVar36 + 1);
        pppppppcVar36 = pppppppcVar14;
        if ((apppppppcStack_1c0[0] != (code *******)0x0) &&
           (*apppppppcStack_1c0[0] = (code ******)((longlong)*apppppppcStack_1c0[0] + -1),
           *apppppppcStack_1c0[0] == (code ******)0x0)) {
          pppppppcStack_318 = (code *******)0x23e755cd2;
          pppppppcStack_238 = pppppppcVar14;
          (*(code *)apppppppcStack_1c0[0][1][6])(apppppppcStack_1c0[0]);
          pppppppcVar36 = pppppppcStack_238;
        }
      }
    }
    apppppppcStack_1c0[0] = pppppppcVar36;
    plStack_290 = plStack_270;
    plStack_298 = plStack_248;
    plStack_2a0 = plStack_260;
    plStack_2b0 = plStack_250;
    plStack_2b8 = plStack_268;
    plStack_2c0 = plStack_278;
    pcStack_2d0 = pcStack_280;
    plStack_2d8 = plStack_240;
    plStack_2e8 = plStack_258;
    pppppppcStack_318 = (code *******)0x23e755d83;
    plStack_2f0 = plVar17;
    plStack_2e0 = plVar25;
    plStack_2c8 = plVar29;
    plStack_2a8 = plVar37;
    FUN_23e8bba40(ppppppcVar4,"ooooooooooooooo",pppppppcVar22,plVar13);
    if (_DAT_23eedae10 == ppppppcVar4) {
      *ppppppcVar4 = (code *****)((longlong)*ppppppcVar4 + -1);
      if (*ppppppcVar4 == (code *****)0x0) {
        pppppppcStack_318 = (code *******)0x23e756068;
        (*(code *)ppppppcVar4[1][6])(ppppppcVar4);
      }
      _DAT_23eedae10 = (code ******)0x0;
    }
    lVar26 = *(longlong *)(*(longlong *)(lVar15 + 0x38) + 8);
    plVar28 = *(longlong **)(lVar26 + 0x28);
    plVar38 = (longlong *)plVar28[2];
    *(undefined8 *)(*(longlong *)(lVar15 + 0x38) + 8) = *(undefined8 *)(lVar26 + 0x30);
    *(undefined4 *)(plVar28 + 8) = 0xffffffff;
    if (plVar38 != (longlong *)0x0) {
      plVar28[2] = 0;
      *plVar38 = *plVar38 + -1;
      if (*plVar38 == 0) {
        pppppppcStack_318 = (code *******)0x23e755dc9;
        (**(code **)(plVar38[1] + 0x30))();
      }
    }
    *plVar28 = *plVar28 + -1;
    if (*plVar28 == 0) {
      pppppppcStack_318 = (code *******)0x23e755dd9;
      (**(code **)(plVar28[1] + 0x30))(plVar28);
    }
    pppppppcVar36 = apppppppcStack_1c0[0];
    uVar46 = auStack_1d0._8_8_;
    uVar45 = auStack_1d0._0_8_;
    plVar28[0xf] = 0;
    auStack_1d0 = (undefined1  [16])0x0;
    apppppppcStack_1c0[0] = (code *******)0x0;
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      pppppppcStack_318 = (code *******)0x23e755e1f;
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
      pppppppcStack_318 = (code *******)0x23e755e35;
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    plVar17 = plStack_258;
    plVar13 = plStack_258;
    if (plStack_258 != (longlong *)0x0) {
      plVar13 = (longlong *)*plStack_258;
      *plStack_258 = (longlong)plVar13 + -1;
      if ((longlong)plVar13 + -1 == 0) {
        plVar28 = plStack_258 + 1;
        pppppppcStack_318 = (code *******)0x23e755e60;
        plStack_258 = plVar13;
        (**(code **)(*plVar28 + 0x30))(plVar17);
        plVar13 = plStack_258;
      }
    }
    plStack_258 = plVar13;
    if ((plVar25 != (longlong *)0x0) && (*plVar25 = *plVar25 + -1, *plVar25 == 0)) {
      pppppppcStack_318 = (code *******)0x23e755e75;
      (**(code **)(plVar25[1] + 0x30))(plVar25);
    }
    if (plStack_240 != (longlong *)0x0) {
      plStack_258 = (longlong *)*plStack_240;
      *plStack_240 = (longlong)plStack_258 + -1;
      if ((longlong)plStack_258 + -1 == 0) {
        pppppppcStack_318 = (code *******)0x23e755ea0;
        (**(code **)(plStack_240[1] + 0x30))(plStack_240);
      }
    }
    pcVar35 = pcStack_280;
    pcVar43 = pcStack_280;
    if (pcStack_280 != (code *)0x0) {
      pcVar43 = *(code **)pcStack_280;
      *(code **)pcStack_280 = pcVar43 + -1;
      if (pcVar43 + -1 == (code *)0x0) {
        pcVar42 = pcStack_280 + 8;
        pppppppcStack_318 = (code *******)0x23e755ecb;
        pcStack_280 = pcVar43;
        (**(code **)(*(longlong *)pcVar42 + 0x30))(pcVar35);
        pcVar43 = pcStack_280;
      }
    }
    pcStack_280 = pcVar43;
    if ((plVar29 != (longlong *)0x0) && (*plVar29 = *plVar29 + -1, *plVar29 == 0)) {
      pppppppcStack_318 = (code *******)0x23e755ee1;
      (**(code **)(plVar29[1] + 0x30))(plVar29);
    }
    if (plStack_278 != (longlong *)0x0) {
      pcStack_280 = (code *)*plStack_278;
      *plStack_278 = (longlong)(pcStack_280 + -1);
      if (pcStack_280 + -1 == (code *)0x0) {
        pppppppcStack_318 = (code *******)0x23e755f0c;
        (**(code **)(plStack_278[1] + 0x30))(plStack_278);
      }
    }
    if (plStack_268 != (longlong *)0x0) {
      pcStack_280 = (code *)*plStack_268;
      *plStack_268 = (longlong)(pcStack_280 + -1);
      if (pcStack_280 + -1 == (code *)0x0) {
        pppppppcStack_318 = (code *******)0x23e755f37;
        (**(code **)(plStack_268[1] + 0x30))(plStack_268);
      }
    }
    if (plStack_250 != (longlong *)0x0) {
      pcStack_280 = (code *)*plStack_250;
      *plStack_250 = (longlong)(pcStack_280 + -1);
      if (pcStack_280 + -1 == (code *)0x0) {
        pppppppcStack_318 = (code *******)0x23e755f62;
        (**(code **)(plStack_250[1] + 0x30))(plStack_250);
      }
    }
    if ((plVar37 != (longlong *)0x0) && (*plVar37 = *plVar37 + -1, *plVar37 == 0)) {
      pppppppcStack_318 = (code *******)0x23e755f79;
      (**(code **)(plVar37[1] + 0x30))(plVar37);
    }
    if (plStack_260 != (longlong *)0x0) {
      pcStack_280 = (code *)*plStack_260;
      *plStack_260 = (longlong)(pcStack_280 + -1);
      if (pcStack_280 + -1 == (code *)0x0) {
        pppppppcStack_318 = (code *******)0x23e755fa4;
        (**(code **)(plStack_260[1] + 0x30))(plStack_260);
      }
    }
    if (plStack_248 != (longlong *)0x0) {
      pcStack_280 = (code *)*plStack_248;
      *plStack_248 = (longlong)(pcStack_280 + -1);
      if (pcStack_280 + -1 == (code *)0x0) {
        pppppppcStack_318 = (code *******)0x23e755fcf;
        (**(code **)(plStack_248[1] + 0x30))(plStack_248);
      }
    }
    if (plStack_270 != (longlong *)0x0) {
      pcStack_280 = (code *)*plStack_270;
      *plStack_270 = (longlong)(pcStack_280 + -1);
      if (pcStack_280 + -1 == (code *)0x0) {
        pppppppcStack_318 = (code *******)0x23e755ffa;
        (**(code **)(plStack_270[1] + 0x30))(plStack_270);
      }
    }
    *pppppppcVar22 = (code ******)((longlong)*pppppppcVar22 + -1);
    apppppppcStack_1c0[0] = pppppppcVar36;
    auStack_1d0._0_8_ = uVar45;
    auStack_1d0._8_8_ = uVar46;
    if (*pppppppcVar22 == (code ******)0x0) {
      pppppppcStack_318 = (code *******)0x23e75603a;
      (*(code *)pppppppcVar22[1][6])(pppppppcVar22);
    }
    pppppppcStack_318 = (code *******)0x23e756028;
    FUN_23a33aa70(lVar15,auStack_1d0._0_8_,auStack_1d0._8_8_,apppppppcStack_1c0[0]);
    return (code *******)0x0;
  }
  *(undefined4 *)(ppppppcVar4 + 5) = 0x369;
  pppppppcStack_318 = (code *******)0x23e75539d;
  plVar17 = (longlong *)FUN_23e91bfe0(lVar15,plVar13,DAT_23eed8d38);
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    pppppppcStack_318 = (code *******)0x23e7553b0;
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if (plVar17 == (longlong *)0x0) goto LAB_23e756610;
  pppppppcStack_318 = (code *******)0x23e7553c1;
  iVar12 = FUN_23a35f020(plVar17);
  *plVar17 = *plVar17 + -1;
  if (*plVar17 == 0) {
    pppppppcStack_318 = (code *******)0x23e7553d3;
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if (iVar12 == -1) goto LAB_23e756610;
  pcVar35 = _Py_FalseStruct_exref;
  if (iVar12 == 0) {
    pcVar35 = _Py_TrueStruct_exref;
  }
  pppppppcStack_318 = (code *******)0x23e7553f5;
  iVar12 = FUN_23a35f020(pcVar35);
  if (iVar12 == 1) {
    pppppppcStack_318 = (code *******)0x23e7565ad;
    lVar26 = FUN_23e8e0ba0();
    plVar17 = plStack_1e8;
    plVar13 = plStack_1f0;
    plVar25 = plStack_1f8;
    plVar37 = plStack_208;
    plVar29 = plStack_210;
    pppppppcVar22 = pppppppcStack_230;
    if (lVar26 == 0) {
      pppppppcStack_318 = (code *******)0x23e75788a;
      pcStack_280 = pcVar43;
      FUN_23e915740(lVar15,auStack_1d0,DAT_23eed8c70);
      uVar40 = 0x369;
      goto LAB_23e755c16;
    }
    *(undefined4 *)(ppppppcVar4 + 5) = 0x369;
    pppppppcStack_318 = (code *******)0x23e7565d0;
    plVar13 = (longlong *)FUN_23e91bfe0(lVar15,lVar26);
    if (plVar13 == (longlong *)0x0) goto LAB_23e756610;
    pppppppcStack_318 = (code *******)0x23e7565e8;
    pcVar35 = (code *)FUN_23e8d09c0(plVar13,plStack_240);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      pppppppcStack_318 = (code *******)0x23e7565fb;
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (pcVar35 == (code *)0x0) goto LAB_23e756610;
  }
  else {
    *(longlong *)pcVar35 = *(longlong *)pcVar35 + 1;
  }
  pppppppcStack_318 = (code *******)0x23e75540a;
  iVar12 = FUN_23a35f020(pcVar35);
  *(longlong *)pcVar35 = *(longlong *)pcVar35 + -1;
  if (*(longlong *)pcVar35 == 0) {
    pppppppcStack_318 = (code *******)0x23e75541c;
    (**(code **)(*(longlong *)(pcVar35 + 8) + 0x30))(pcVar35);
  }
  if (iVar12 == -1) goto LAB_23e756610;
  if (iVar12 == 0) {
    pppppppcStack_238 = (code *******)_Py_NoneStruct_exref;
    plVar17 = plStack_1e8;
    plVar13 = plStack_1f0;
    plVar29 = plStack_210;
    plVar25 = plStack_1f8;
    pppppppcVar22 = pppppppcStack_230;
    goto LAB_23e7578e2;
  }
  pppppppcStack_318 = (code *******)0x23e755441;
  plVar13 = (longlong *)FUN_23e8bc2f0(pppppppcStack_230,DAT_23eed8a98);
  if (plVar13 == (longlong *)0x0) {
LAB_23e7575c0:
    auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
    auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
    apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
    uVar40 = 0x36a;
    *(undefined8 *)(lVar15 + 0x70) = 0;
    *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
    plVar17 = plStack_1e8;
    plVar13 = plStack_1f0;
    plVar37 = plStack_208;
    plVar29 = plStack_210;
    plVar25 = plStack_1f8;
    pppppppcVar22 = pppppppcStack_230;
    pcStack_280 = pcVar43;
    goto LAB_23e755c16;
  }
  *(undefined4 *)(ppppppcVar4 + 5) = 0x36a;
  pppppppcStack_318 = (code *******)0x23e755467;
  pcStack_280 = (code *)FUN_23e91bfe0(lVar15,plVar13,DAT_23eed8a98);
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    pppppppcStack_318 = (code *******)0x23e75547f;
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if (pcStack_280 == (code *)0x0) goto LAB_23e7575c0;
  if ((pcVar43 != (code *)0x0) &&
     (*(longlong *)pcVar43 = *(longlong *)pcVar43 + -1, *(longlong *)pcVar43 == 0)) {
    pppppppcStack_318 = (code *******)0x23e7554a3;
    (**(code **)(*(longlong *)(pcVar43 + 8) + 0x30))(pcVar43);
  }
  pppppppcStack_238 = (code *******)_Py_NoneStruct_exref;
  if (pcStack_280 == _Py_NoneStruct_exref) {
    pppppppcStack_318 = (code *******)0x23e75629d;
    lVar34 = FUN_23e8e0ba0();
    plVar17 = plStack_1e8;
    plVar13 = plStack_1f0;
    plVar25 = plStack_1f8;
    plVar37 = plStack_208;
    plVar29 = plStack_210;
    pppppppcVar22 = pppppppcStack_230;
    lVar26 = _DAT_23eed9178;
    if (lVar34 == 0) {
      pppppppcStack_318 = (code *******)0x23e7576e4;
      FUN_23e915740(lVar15,auStack_1d0,DAT_23eed8c70);
      uVar40 = 0x36c;
      goto LAB_23e755c16;
    }
    *(undefined4 *)(ppppppcVar4 + 5) = 0x36c;
    pppppppcStack_318 = (code *******)0x23e7562cb;
    plVar13 = (longlong *)FUN_23e915840(lVar15,lVar34,DAT_23eed8d40,*(undefined8 *)(lVar26 + 0x18));
    if (plVar13 == (longlong *)0x0) {
      auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
      auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
      apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
      uVar40 = 0x36c;
      *(undefined8 *)(lVar15 + 0x70) = 0;
      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
      plVar17 = plStack_1e8;
      plVar13 = plStack_1f0;
      plVar37 = plStack_208;
      plVar29 = plStack_210;
      plVar25 = plStack_1f8;
      pppppppcVar22 = pppppppcStack_230;
      goto LAB_23e755c16;
    }
    *plVar13 = *plVar13 + -1;
    pcVar43 = pcStack_280;
    if (*plVar13 == 0) {
      pppppppcStack_318 = (code *******)0x23e7562e8;
      (**(code **)(plVar13[1] + 0x30))(plVar13);
      pcVar43 = pcStack_280;
    }
  }
  else {
    *(undefined4 *)(ppppppcVar4 + 5) = 0x36f;
    pppppppcStack_318 = (code *******)0x23e7554e9;
    plVar13 = (longlong *)FUN_23e915840(lVar15,plStack_1f8,DAT_23eed9108,pcStack_280);
    if (plVar13 == (longlong *)0x0) {
LAB_23e7576f7:
      pcVar43 = *(code **)(lVar15 + 0x60);
      uVar45 = *(undefined8 *)(lVar15 + 0x68);
      pppppppcVar36 = *(code ********)(lVar15 + 0x70);
      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(lVar15 + 0x70) = 0;
      plVar17 = plStack_1e8;
      plVar13 = plStack_1f0;
      plVar37 = plStack_208;
      plVar29 = plStack_210;
      plVar25 = plStack_1f8;
      pppppppcVar22 = pppppppcStack_230;
LAB_23e756e46:
      uVar40 = 0x36f;
      apppppppcStack_1c0[0] = pppppppcVar36;
      auStack_1d0._0_8_ = pcVar43;
      auStack_1d0._8_8_ = uVar45;
      goto LAB_23e755c16;
    }
    pppppppcStack_318 = (code *******)0x23e7554fd;
    plVar28 = (longlong *)FUN_23a388310(plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      pppppppcStack_318 = (code *******)0x23e755510;
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar28 == (longlong *)0x0) goto LAB_23e7576f7;
    pppppppcStack_318 = (code *******)0x23e755526;
    plVar29 = (longlong *)(**(code **)(plVar28[1] + 0xe0))(plVar28);
    plStack_200 = (longlong *)auStack_1d0;
    if (plVar29 == (longlong *)0x0) {
      pppppppcStack_318 = (code *******)0x23e756b6c;
      plVar29 = (longlong *)FUN_23a3c1b70(lVar15,plStack_200,0,8);
      plVar13 = plStack_1f0;
      plVar37 = plStack_208;
      plVar38 = plStack_210;
      if (plVar29 != (longlong *)0x0) goto LAB_23e755542;
      plStack_218 = (longlong *)0x0;
      plStack_220 = (longlong *)0x0;
      lVar26 = *plVar28;
      plStack_228 = (longlong *)0x0;
      plStack_208 = (longlong *)0x0;
      plStack_200 = (longlong *)0x0;
      plStack_210 = (longlong *)0x0;
      plStack_1f0 = (longlong *)0x0;
      plVar31 = plStack_210;
      plVar33 = plStack_208;
      plVar32 = plStack_200;
      plVar30 = plStack_1f0;
LAB_23e756c10:
      plStack_1d8 = plVar29;
      plStack_1f0 = plVar30;
      plStack_200 = plVar32;
      plStack_208 = plVar33;
      plStack_210 = plVar31;
      pppppppcVar36 = apppppppcStack_1c0[0];
      uVar45 = auStack_1d0._8_8_;
      pcVar43 = (code *)auStack_1d0._0_8_;
      plVar17 = plStack_1e8;
      plVar25 = plStack_1f8;
      pppppppcVar22 = pppppppcStack_230;
      auStack_1d0 = (undefined1  [16])0x0;
      apppppppcStack_1c0[0] = (code *******)0x0;
      *plVar28 = lVar26 + -1;
      if (lVar26 + -1 == 0) {
        pppppppcStack_238 = pppppppcVar36;
        pppppppcStack_318 = (code *******)0x23e756c54;
        (**(code **)(plVar28[1] + 0x30))(plVar28);
        pppppppcVar36 = pppppppcStack_238;
      }
      apppppppcStack_1c0[0] = (code *******)0x0;
      auStack_1d0._0_8_ = 0;
      auStack_1d0._8_8_ = 0;
      if (plStack_1d8 != (longlong *)0x0) {
        pppppppcStack_238 = (code *******)*plStack_1d8;
        *plStack_1d8 = (longlong)pppppppcStack_238 + -1;
        if ((code *)((longlong)pppppppcStack_238 + -1) == (code *)0x0) {
          pppppppcStack_318 = (code *******)0x23e756ca4;
          pppppppcStack_238 = pppppppcVar36;
          (**(code **)(plStack_1d8[1] + 0x30))();
          pppppppcVar36 = pppppppcStack_238;
        }
      }
      if (plStack_1f0 != (longlong *)0x0) {
        pppppppcStack_238 = (code *******)*plStack_1f0;
        *plStack_1f0 = (longlong)pppppppcStack_238 + -1;
        if ((code *)((longlong)pppppppcStack_238 + -1) == (code *)0x0) {
          pppppppcStack_318 = (code *******)0x23e756cdc;
          pppppppcStack_238 = pppppppcVar36;
          (**(code **)(plStack_1f0[1] + 0x30))();
          pppppppcVar36 = pppppppcStack_238;
        }
      }
      if (plStack_210 != (longlong *)0x0) {
        pppppppcStack_238 = (code *******)*plStack_210;
        *plStack_210 = (longlong)pppppppcStack_238 + -1;
        if ((code *)((longlong)pppppppcStack_238 + -1) == (code *)0x0) {
          pppppppcStack_318 = (code *******)0x23e756d14;
          pppppppcStack_238 = pppppppcVar36;
          (**(code **)(plStack_210[1] + 0x30))();
          pppppppcVar36 = pppppppcStack_238;
        }
      }
      if (plStack_200 != (longlong *)0x0) {
        pppppppcStack_238 = (code *******)*plStack_200;
        *plStack_200 = (longlong)pppppppcStack_238 + -1;
        if ((code *)((longlong)pppppppcStack_238 + -1) == (code *)0x0) {
          pppppppcStack_318 = (code *******)0x23e756d52;
          pppppppcStack_238 = pppppppcVar36;
          (**(code **)(plStack_200[1] + 0x30))();
          pppppppcVar36 = pppppppcStack_238;
        }
      }
      if (plStack_208 != (longlong *)0x0) {
        pppppppcStack_238 = (code *******)*plStack_208;
        *plStack_208 = (longlong)pppppppcStack_238 + -1;
        if ((code *)((longlong)pppppppcStack_238 + -1) == (code *)0x0) {
          pppppppcStack_318 = (code *******)0x23e756d90;
          pppppppcStack_238 = pppppppcVar36;
          (**(code **)(plStack_208[1] + 0x30))();
          pppppppcVar36 = pppppppcStack_238;
        }
      }
      if (plStack_228 != (longlong *)0x0) {
        pppppppcStack_238 = (code *******)*plStack_228;
        *plStack_228 = (longlong)pppppppcStack_238 + -1;
        if ((code *)((longlong)pppppppcStack_238 + -1) == (code *)0x0) {
          pppppppcStack_318 = (code *******)0x23e756dce;
          pppppppcStack_238 = pppppppcVar36;
          (**(code **)(plStack_228[1] + 0x30))();
          pppppppcVar36 = pppppppcStack_238;
        }
      }
      if (plStack_220 != (longlong *)0x0) {
        pppppppcStack_238 = (code *******)*plStack_220;
        *plStack_220 = (longlong)pppppppcStack_238 + -1;
        if ((code *)((longlong)pppppppcStack_238 + -1) == (code *)0x0) {
          pppppppcStack_318 = (code *******)0x23e756e06;
          pppppppcStack_238 = pppppppcVar36;
          (**(code **)(plStack_220[1] + 0x30))();
          pppppppcVar36 = pppppppcStack_238;
        }
      }
      plVar29 = plVar38;
      if (plStack_218 != (longlong *)0x0) {
        pppppppcStack_238 = (code *******)*plStack_218;
        *plStack_218 = (longlong)pppppppcStack_238 + -1;
        if ((code *)((longlong)pppppppcStack_238 + -1) == (code *)0x0) {
          pppppppcStack_318 = (code *******)0x23e756e3e;
          pppppppcStack_238 = pppppppcVar36;
          (**(code **)(plStack_218[1] + 0x30))();
          pppppppcVar36 = pppppppcStack_238;
        }
      }
      goto LAB_23e756e46;
    }
LAB_23e755542:
    pppppppcStack_318 = (code *******)0x23e75554f;
    plVar30 = (longlong *)(**(code **)(plVar28[1] + 0xe0))(plVar28);
    if (plVar30 == (longlong *)0x0) {
      pppppppcStack_318 = (code *******)0x23e756e84;
      plVar30 = (longlong *)FUN_23a3c1b70(lVar15,plStack_200,1,8);
      plVar37 = plStack_208;
      plVar38 = plStack_210;
      if (plVar30 == (longlong *)0x0) {
        lVar26 = *plVar28;
        plStack_218 = (longlong *)0x0;
        plStack_220 = (longlong *)0x0;
        plStack_228 = (longlong *)0x0;
        plStack_208 = (longlong *)0x0;
        plStack_200 = (longlong *)0x0;
        plStack_210 = (longlong *)0x0;
        plVar13 = plStack_1f0;
        plVar31 = plStack_210;
        plVar33 = plStack_208;
        plVar32 = plStack_200;
        goto LAB_23e756c10;
      }
    }
    pppppppcStack_318 = (code *******)0x23e755568;
    plVar31 = (longlong *)(**(code **)(plVar28[1] + 0xe0))(plVar28);
    if (plVar31 == (longlong *)0x0) {
      pppppppcStack_318 = (code *******)0x23e756f4c;
      plVar31 = (longlong *)FUN_23a3c1b70(lVar15,plStack_200,2,8);
      plVar37 = plStack_208;
      if (plVar31 == (longlong *)0x0) {
        lVar26 = *plVar28;
        plStack_218 = (longlong *)0x0;
        plStack_220 = (longlong *)0x0;
        plStack_228 = (longlong *)0x0;
        plStack_208 = (longlong *)0x0;
        plStack_200 = (longlong *)0x0;
        plVar13 = plStack_1f0;
        plVar38 = plStack_210;
        plVar33 = plStack_208;
        plVar32 = plStack_200;
        goto LAB_23e756c10;
      }
    }
    pppppppcStack_318 = (code *******)0x23e755581;
    plVar32 = (longlong *)(**(code **)(plVar28[1] + 0xe0))(plVar28);
    if (plVar32 == (longlong *)0x0) {
      pppppppcStack_318 = (code *******)0x23e75700c;
      plVar32 = (longlong *)FUN_23a3c1b70(lVar15,plStack_200,3,8);
      plVar37 = plStack_208;
      if (plVar32 == (longlong *)0x0) {
        lVar26 = *plVar28;
        plStack_218 = (longlong *)0x0;
        plStack_220 = (longlong *)0x0;
        plStack_228 = (longlong *)0x0;
        plStack_208 = (longlong *)0x0;
        plVar13 = plStack_1f0;
        plVar38 = plStack_210;
        plVar33 = plStack_208;
        goto LAB_23e756c10;
      }
    }
    pppppppcStack_318 = (code *******)0x23e75559a;
    plVar33 = (longlong *)(**(code **)(plVar28[1] + 0xe0))(plVar28);
    if (plVar33 == (longlong *)0x0) {
      pppppppcStack_318 = (code *******)0x23e7570cc;
      plVar33 = (longlong *)FUN_23a3c1b70(lVar15,plStack_200,4,8);
      if (plVar33 == (longlong *)0x0) {
        lVar26 = *plVar28;
        plStack_218 = (longlong *)0x0;
        plStack_220 = (longlong *)0x0;
        plStack_228 = (longlong *)0x0;
        plVar13 = plStack_1f0;
        plVar37 = plStack_208;
        plVar38 = plStack_210;
        goto LAB_23e756c10;
      }
    }
    pppppppcStack_318 = (code *******)0x23e7555b3;
    plStack_228 = (longlong *)(**(code **)(plVar28[1] + 0xe0))(plVar28);
    if (plStack_228 == (longlong *)0x0) {
      pppppppcStack_318 = (code *******)0x23e757184;
      plStack_228 = (longlong *)FUN_23a3c1b70(lVar15,plStack_200,5,8);
      if (plStack_228 == (longlong *)0x0) {
        lVar26 = *plVar28;
        plStack_218 = (longlong *)0x0;
        plStack_220 = (longlong *)0x0;
        plVar13 = plStack_1f0;
        plVar37 = plStack_208;
        plVar38 = plStack_210;
        goto LAB_23e756c10;
      }
    }
    pppppppcStack_318 = (code *******)0x23e7555d1;
    plStack_220 = (longlong *)(**(code **)(plVar28[1] + 0xe0))(plVar28);
    if (plStack_220 == (longlong *)0x0) {
      pppppppcStack_318 = (code *******)0x23e75723c;
      plStack_220 = (longlong *)FUN_23a3c1b70(lVar15,plStack_200,6,8);
      if (plStack_220 == (longlong *)0x0) {
        lVar26 = *plVar28;
        plStack_218 = (longlong *)0x0;
        plVar13 = plStack_1f0;
        plVar37 = plStack_208;
        plVar38 = plStack_210;
        goto LAB_23e756c10;
      }
    }
    pppppppcStack_318 = (code *******)0x23e7555ef;
    plStack_218 = (longlong *)(**(code **)(plVar28[1] + 0xe0))(plVar28);
    if (plStack_218 == (longlong *)0x0) {
      pppppppcStack_318 = (code *******)0x23e7572e4;
      plStack_218 = (longlong *)FUN_23a3c1b70(lVar15,plStack_200,7,8);
      if (plStack_218 == (longlong *)0x0) {
        lVar26 = *plVar28;
        plVar13 = plStack_1f0;
        plVar37 = plStack_208;
        plVar38 = plStack_210;
        goto LAB_23e756c10;
      }
    }
    pppppppcStack_318 = (code *******)0x23e755619;
    cVar11 = FUN_23a3884a0(lVar15,plStack_200,plVar28,8);
    lVar26 = *plVar28;
    plVar13 = plStack_1f0;
    plVar37 = plStack_208;
    plVar38 = plStack_210;
    if (cVar11 == '\0') goto LAB_23e756c10;
    *plVar28 = lVar26 + -1;
    if (lVar26 + -1 == 0) {
      pppppppcStack_318 = (code *******)0x23e75563e;
      (**(code **)(plVar28[1] + 0x30))(plVar28);
    }
    lVar26 = *plVar29;
    *plVar29 = lVar26 + 1;
    if (plStack_210 != (longlong *)0x0) {
      plStack_1d8 = (longlong *)*plStack_210;
      *plStack_210 = (longlong)plStack_1d8 + -1;
      if ((longlong)plStack_1d8 + -1 == 0) {
        pppppppcStack_318 = (code *******)0x23e75657a;
        (**(code **)(plStack_210[1] + 0x30))(plStack_210);
      }
      lVar26 = *plVar29 + -1;
    }
    *plVar29 = lVar26;
    if (lVar26 == 0) {
      pppppppcStack_318 = (code *******)0x23e755686;
      (**(code **)(plVar29[1] + 0x30))(plVar29);
    }
    lVar26 = *plVar30;
    *plVar30 = lVar26 + 1;
    if (plStack_278 != (longlong *)0x0) {
      plStack_210 = (longlong *)*plStack_278;
      *plStack_278 = (longlong)plStack_210 + -1;
      if ((longlong)plStack_210 + -1 == 0) {
        pppppppcStack_318 = (code *******)0x23e75656a;
        (**(code **)(plStack_278[1] + 0x30))(plStack_278);
      }
      lVar26 = *plVar30 + -1;
    }
    *plVar30 = lVar26;
    if (lVar26 == 0) {
      pppppppcStack_318 = (code *******)0x23e7556ce;
      (**(code **)(plVar30[1] + 0x30))(plVar30);
    }
    lVar26 = *plVar31;
    *plVar31 = lVar26 + 1;
    if (plStack_268 != (longlong *)0x0) {
      plStack_278 = (longlong *)*plStack_268;
      *plStack_268 = (longlong)plStack_278 + -1;
      if ((longlong)plStack_278 + -1 == 0) {
        pppppppcStack_318 = (code *******)0x23e75655a;
        (**(code **)(plStack_268[1] + 0x30))(plStack_268);
      }
      lVar26 = *plVar31 + -1;
    }
    *plVar31 = lVar26;
    if (lVar26 == 0) {
      pppppppcStack_318 = (code *******)0x23e75571a;
      (**(code **)(plVar31[1] + 0x30))(plVar31);
    }
    lVar26 = *plVar32;
    *plVar32 = lVar26 + 1;
    if (plStack_250 != (longlong *)0x0) {
      plStack_278 = (longlong *)*plStack_250;
      *plStack_250 = (longlong)plStack_278 + -1;
      if ((longlong)plStack_278 + -1 == 0) {
        pppppppcStack_318 = (code *******)0x23e75654a;
        (**(code **)(plStack_250[1] + 0x30))(plStack_250);
      }
      lVar26 = *plVar32 + -1;
    }
    *plVar32 = lVar26;
    if (lVar26 == 0) {
      pppppppcStack_318 = (code *******)0x23e755767;
      (**(code **)(plVar32[1] + 0x30))(plVar32);
    }
    lVar26 = *plVar33;
    *plVar33 = lVar26 + 1;
    if (plStack_208 != (longlong *)0x0) {
      plStack_278 = (longlong *)*plStack_208;
      *plStack_208 = (longlong)plStack_278 + -1;
      if ((longlong)plStack_278 + -1 == 0) {
        pppppppcStack_318 = (code *******)0x23e756532;
        (**(code **)(plStack_208[1] + 0x30))(plStack_208);
      }
      lVar26 = *plVar33 + -1;
    }
    *plVar33 = lVar26;
    if (lVar26 == 0) {
      pppppppcStack_318 = (code *******)0x23e7557af;
      (**(code **)(plVar33[1] + 0x30))(plVar33);
    }
    lVar26 = *plStack_228;
    *plStack_228 = lVar26 + 1;
    if (plStack_260 != (longlong *)0x0) {
      plStack_278 = (longlong *)*plStack_260;
      *plStack_260 = (longlong)plStack_278 + -1;
      if ((longlong)plStack_278 + -1 == 0) {
        pppppppcStack_318 = (code *******)0x23e7557ed;
        (**(code **)(plStack_260[1] + 0x30))();
        plStack_278 = (longlong *)*plStack_228;
        lVar26 = (longlong)plStack_278 + -1;
      }
      else {
        plStack_278 = (longlong *)*plStack_228;
        lVar26 = (longlong)plStack_278 + -1;
      }
    }
    *plStack_228 = lVar26;
    if (lVar26 == 0) {
      pppppppcStack_318 = (code *******)0x23e75581b;
      (**(code **)(plStack_228[1] + 0x30))();
    }
    lVar26 = *plStack_220;
    *plStack_220 = lVar26 + 1;
    if (plStack_248 != (longlong *)0x0) {
      plStack_278 = (longlong *)*plStack_248;
      *plStack_248 = (longlong)plStack_278 + -1;
      if ((longlong)plStack_278 + -1 == 0) {
        pppppppcStack_318 = (code *******)0x23e75585c;
        (**(code **)(plStack_248[1] + 0x30))(plStack_248);
        plStack_278 = (longlong *)*plStack_220;
        lVar26 = (longlong)plStack_278 + -1;
      }
      else {
        plStack_278 = (longlong *)*plStack_220;
        lVar26 = (longlong)plStack_278 + -1;
      }
    }
    *plStack_220 = lVar26;
    if (lVar26 == 0) {
      pppppppcStack_318 = (code *******)0x23e75588a;
      (**(code **)(plStack_220[1] + 0x30))();
    }
    lVar26 = *plStack_218;
    *plStack_218 = lVar26 + 1;
    if (plStack_270 != (longlong *)0x0) {
      plStack_278 = (longlong *)*plStack_270;
      *plStack_270 = (longlong)plStack_278 + -1;
      if ((longlong)plStack_278 + -1 == 0) {
        pppppppcStack_318 = (code *******)0x23e7558c8;
        (**(code **)(plStack_270[1] + 0x30))();
        plStack_278 = (longlong *)*plStack_218;
        lVar26 = (longlong)plStack_278 + -1;
      }
      else {
        plStack_278 = (longlong *)*plStack_218;
        lVar26 = (longlong)plStack_278 + -1;
      }
    }
    *plStack_218 = lVar26;
    if (lVar26 == 0) {
      pppppppcStack_318 = (code *******)0x23e7558f6;
      (**(code **)(plStack_218[1] + 0x30))();
    }
    pppppppcStack_318 = (code *******)0x23e7558fe;
    iVar12 = FUN_23a35f020(plVar33);
    plVar17 = plStack_1e8;
    plVar13 = plStack_1f0;
    plVar25 = plStack_1f8;
    pppppppcVar22 = pppppppcStack_230;
    plVar37 = plVar33;
    if (iVar12 == -1) {
      uVar40 = 0x370;
      plStack_270 = plStack_218;
      plStack_248 = plStack_220;
      auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
      plStack_260 = plStack_228;
      apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
      *(undefined8 *)(lVar15 + 0x70) = 0;
      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
      plStack_278 = plVar30;
      plStack_268 = plVar31;
      plStack_250 = plVar32;
      plStack_210 = plVar31;
      plStack_208 = plVar33;
      plStack_200 = plVar32;
      plStack_1f0 = plVar30;
      plStack_1d8 = plVar29;
      auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
      goto LAB_23e755c16;
    }
    if (iVar12 != 0) {
      pppppppcStack_318 = (code *******)0x23e757dd1;
      plStack_210 = plVar31;
      plStack_208 = plVar33;
      plStack_200 = plVar32;
      plStack_1f0 = plVar30;
      plStack_1d8 = plVar29;
      plVar37 = (longlong *)FUN_23e8bc2f0(pppppppcStack_230,DAT_23eed8b40);
      plVar29 = _DAT_23eed9168;
      if (plVar37 == (longlong *)0x0) {
LAB_23e758138:
        apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
        auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
        auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
        *(undefined8 *)(lVar15 + 0x70) = 0;
        *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        lVar26 = *(longlong *)(lVar15 + 0x10);
        plVar28 = *(longlong **)(lVar26 + 0xe28);
        if (plVar28 == (longlong *)0x0) {
          plStack_278 = _DAT_23eed9168;
          pppppppcStack_318 = (code *******)0x23e758128;
          plVar28 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
          plVar29 = plStack_278;
        }
        else {
          lVar34 = plVar28[3];
          *(int *)(lVar26 + 0xec0) = *(int *)(lVar26 + 0xec0) + -1;
          *(longlong *)(lVar26 + 0xe28) = lVar34;
          *plVar28 = 1;
        }
        plVar38 = plStack_228;
        pcVar43 = _PyRuntime_exref;
        *(undefined1 (*) [16])(plVar28 + 4) = (undefined1  [16])0x0;
        puVar27 = *(undefined8 **)(*(longlong *)(*(longlong *)(pcVar43 + 0x1f8) + 0x10) + 0x2e8);
        lVar26 = plVar28[-1];
        puVar8 = (undefined8 *)puVar27[1];
        *puVar8 = plVar28 + -2;
        plVar28[-2] = (longlong)puVar27;
        plVar28[-1] = (ulonglong)((uint)lVar26 & 3) | (ulonglong)puVar8;
        puVar27[1] = plVar28 + -2;
        *plVar29 = *plVar29 + 1;
        plVar28[3] = (longlong)plVar29;
        plVar29 = DAT_23ed6cd28;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          pppppppcStack_318 = (code *******)0x23e758245;
          plVar31 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar31 == (longlong *)0x0) {
            pppppppcStack_318 = (code *******)0x23e7582b0;
            PyErr_PrintEx(0);
            lVar26 = 1;
            pppppppcStack_318 = (code *******)0x23e7582bb;
            Py_Exit();
            ppppppcVar24 = DAT_23eedade8;
            pppppppcStack_318 = pppppppcVar22;
            plStack_320 = plVar25;
            plStack_338 = plVar17;
            plStack_348 = plVar13;
            plStack_368 = plVar38;
            plStack_360 = plVar29;
            plVar13 = (longlong *)*puVar27;
            pppppppcStack_378 = (code *******)0x0;
            auStack_388 = (undefined1  [16])0x0;
            ppppppcStack_350 = ppppppcVar4;
            lStack_340 = lVar15;
            plStack_330 = plVar28;
            plStack_328 = plVar37;
            if (DAT_23eedade8 == (code ******)0x0) {
LAB_23e75831d:
              DAT_23eedade8 = (code ******)FUN_23e91f3b0(lVar26,DAT_23eedaf90,DAT_23eedaeb8,0x60);
            }
            else {
              pppppcVar44 = *DAT_23eedade8;
              if (1 < (longlong)pppppcVar44) {
                *DAT_23eedade8 = (code *****)((longlong)pppppcVar44 + -1);
                goto LAB_23e75831d;
              }
              if (DAT_23eedade8[2] != (code *****)0x0) {
                *DAT_23eedade8 = (code *****)((longlong)pppppcVar44 + -1);
                if ((code *****)((longlong)pppppcVar44 + -1) == (code *****)0x0) {
                  (*(code *)ppppppcVar24[1][6])(ppppppcVar24);
                }
                goto LAB_23e75831d;
              }
            }
            ppppppcVar4 = DAT_23eedade8;
            lVar15 = *(longlong *)(lVar26 + 0x38);
            ppppppcVar24 = DAT_23eedade8 + 9;
            pppppcVar44 = *(code ******)(lVar15 + 8);
            DAT_23eedade8[0xf] = pppppcVar44;
            *(code *******)(lVar15 + 8) = ppppppcVar24;
            if ((pppppcVar44 != (code *****)0x0) &&
               (((*(char *)((longlong)pppppcVar44 + 0x45) == '\x01' ||
                 ((code ****)
                  ((longlong)pppppcVar44[4] + (longlong)*(int *)(pppppcVar44[4] + 0x15) * 2 + 0xb8)
                  <= pppppcVar44[7])) && (ppppppcVar4[0xe] != (code *****)0x0)))) {
              ppppcVar6 = pppppcVar44[5];
              ppppppcVar4[0xe][2] = ppppcVar6;
              if (ppppcVar6 != (code ****)0x0) {
                *ppppcVar6 = (code ***)((longlong)*ppppcVar6 + 1);
              }
            }
            *ppppppcVar4 = (code *****)((longlong)*ppppppcVar4 + 1);
            uVar45 = DAT_23eed89b0;
            *(undefined4 *)(ppppppcVar4 + 8) = 0;
            plVar17 = (longlong *)FUN_23e8bc2f0(plVar13,uVar45);
            if (plVar17 == (longlong *)0x0) {
              pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
              auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
              plVar37 = (longlong *)0x0;
              plVar29 = (longlong *)0x0;
              *(undefined8 *)(lVar26 + 0x70) = 0;
              pcVar43 = (code *)0x0;
              plVar25 = (longlong *)0x0;
              uVar40 = 0x378;
              plStack_3e0 = (longlong *)0x0;
              plStack_3c8 = (longlong *)0x0;
              plStack_3d8 = (longlong *)0x0;
              plStack_3f0 = (longlong *)0x0;
              plStack_3d0 = (longlong *)0x0;
              plStack_3e8 = (longlong *)0x0;
              *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
              plVar17 = (longlong *)0x0;
              goto LAB_23e758dff;
            }
            *(undefined4 *)(ppppppcVar4 + 5) = 0x378;
            plVar25 = (longlong *)FUN_23e91bfe0(lVar26,plVar17,DAT_23eed8d38);
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
              if (plVar25 == (longlong *)0x0) goto LAB_23e758b73;
LAB_23e7583ea:
              iVar12 = FUN_23a35f020(plVar25);
              lVar15 = *plVar25 + -1;
              if (iVar12 == -1) {
                auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                *(undefined8 *)(lVar26 + 0x70) = 0;
                *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                *plVar25 = lVar15;
                if (lVar15 == 0) {
                  (**(code **)(plVar25[1] + 0x30))(plVar25);
                }
                plStack_3f0 = (longlong *)0x0;
                plVar37 = (longlong *)0x0;
                plVar25 = (longlong *)0x0;
                plVar17 = (longlong *)0x0;
                plStack_3e0 = (longlong *)0x0;
                plVar29 = (longlong *)0x0;
                uVar40 = 0x378;
                pcVar43 = (code *)0x0;
                plStack_3c8 = (longlong *)0x0;
                plStack_3d8 = (longlong *)0x0;
                plStack_3d0 = (longlong *)0x0;
                plStack_3e8 = (longlong *)0x0;
                goto LAB_23e758dff;
              }
              *plVar25 = lVar15;
              if (lVar15 == 0) {
                (**(code **)(plVar25[1] + 0x30))(plVar25);
              }
              pppppppcVar36 = (code *******)_Py_NoneStruct_exref;
              if (iVar12 != 0) {
                lVar15 = *(longlong *)(lVar26 + 0x38);
                lVar26 = *(longlong *)(lVar15 + 8);
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                plVar17 = *(longlong **)(lVar26 + 0x28);
                plVar25 = (longlong *)plVar17[2];
                *(undefined8 *)(lVar15 + 8) = *(undefined8 *)(lVar26 + 0x30);
                *(undefined4 *)(plVar17 + 8) = 0xffffffff;
                if (plVar25 != (longlong *)0x0) {
                  plVar17[2] = 0;
                  *plVar25 = *plVar25 + -1;
                  if (*plVar25 == 0) {
                    (**(code **)(plVar25[1] + 0x30))();
                  }
                }
                *plVar17 = *plVar17 + -1;
                if (*plVar17 == 0) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                plVar17[0xf] = 0;
LAB_23e758d12:
                *plVar13 = *plVar13 + -1;
                lVar15 = *plVar13;
joined_r0x00023e758d17:
                if (lVar15 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                  return pppppppcVar36;
                }
                return pppppppcVar36;
              }
              lVar34 = FUN_23e8e0ba0();
              lVar15 = DAT_23eed8c58;
              if (lVar34 == 0) {
                FUN_23e915740(lVar26,auStack_388,DAT_23eed8c70);
LAB_23e7594d7:
                plVar17 = (longlong *)0x0;
                plStack_3f0 = (longlong *)0x0;
                plVar37 = (longlong *)0x0;
                plVar29 = (longlong *)0x0;
                plVar25 = (longlong *)0x0;
                plStack_3e0 = (longlong *)0x0;
                pcVar43 = (code *)0x0;
                uVar40 = 0x37c;
                plStack_3c8 = (longlong *)0x0;
                plStack_3d8 = (longlong *)0x0;
                plStack_3d0 = (longlong *)0x0;
                plStack_3e8 = (longlong *)0x0;
              }
              else {
                *(undefined4 *)(ppppppcVar4 + 5) = 0x37c;
                plVar17 = (longlong *)
                          FUN_23e915840(lVar26,lVar34,DAT_23eed8d40,*(undefined8 *)(lVar15 + 0x18));
                if (plVar17 == (longlong *)0x0) {
                  auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                  pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                  *(undefined8 *)(lVar26 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7594d7;
                }
                *plVar17 = *plVar17 + -1;
                if (*plVar17 == 0) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                plVar25 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eed8968);
                if (plVar25 == (longlong *)0x0) {
                  auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                  pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                  plVar37 = (longlong *)0x0;
                  plVar29 = (longlong *)0x0;
                  *(undefined8 *)(lVar26 + 0x70) = 0;
                  pcVar43 = (code *)0x0;
                  plVar17 = (longlong *)0x0;
                  uVar40 = 0x37e;
                  plStack_3e0 = (longlong *)0x0;
                  plStack_3c8 = (longlong *)0x0;
                  plStack_3d8 = (longlong *)0x0;
                  plStack_3f0 = (longlong *)0x0;
                  plStack_3d0 = (longlong *)0x0;
                  plStack_3e8 = (longlong *)0x0;
                  *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                  plVar25 = (longlong *)0x0;
                }
                else {
                  *(undefined4 *)(ppppppcVar4 + 5) = 0x37e;
                  plVar17 = (longlong *)FUN_23e91bfe0(lVar26,plVar25,DAT_23eed9248);
                  *plVar25 = *plVar25 + -1;
                  if (*plVar25 == 0) {
                    (**(code **)(plVar25[1] + 0x30))(plVar25);
                  }
                  if (plVar17 == (longlong *)0x0) {
                    auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                    pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                    plVar37 = (longlong *)0x0;
                    plVar29 = (longlong *)0x0;
                    *(undefined8 *)(lVar26 + 0x70) = 0;
                    pcVar43 = (code *)0x0;
                    plVar25 = (longlong *)0x0;
                    uVar40 = 0x37e;
                    plStack_3e0 = (longlong *)0x0;
                    plStack_3c8 = (longlong *)0x0;
                    plStack_3d8 = (longlong *)0x0;
                    plStack_3f0 = (longlong *)0x0;
                    plStack_3d0 = (longlong *)0x0;
                    plStack_3e8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    plVar29 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eed8968);
                    if (plVar29 == (longlong *)0x0) {
                      auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                      pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                      plVar37 = (longlong *)0x0;
                      plVar29 = (longlong *)0x0;
                      *(undefined8 *)(lVar26 + 0x70) = 0;
                      plVar25 = (longlong *)0x0;
                      uVar40 = 0x37f;
                      plStack_3e0 = (longlong *)0x0;
                      plStack_3c8 = (longlong *)0x0;
                      plStack_3d8 = (longlong *)0x0;
                      plStack_3f0 = (longlong *)0x0;
                      plStack_3d0 = (longlong *)0x0;
                      plStack_3e8 = (longlong *)0x0;
                      *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                      pcVar43 = (code *)0x0;
                    }
                    else {
                      *(undefined4 *)(ppppppcVar4 + 5) = 0x37f;
                      plVar25 = (longlong *)FUN_23e91bfe0(lVar26,plVar29,DAT_23eed9250);
                      *plVar29 = *plVar29 + -1;
                      if (*plVar29 == 0) {
                        (**(code **)(plVar29[1] + 0x30))(plVar29);
                      }
                      if (plVar25 == (longlong *)0x0) {
                        auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                        pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                        plVar37 = (longlong *)0x0;
                        plVar29 = (longlong *)0x0;
                        *(undefined8 *)(lVar26 + 0x70) = 0;
                        pcVar43 = (code *)0x0;
                        uVar40 = 0x37f;
                        plStack_3e0 = (longlong *)0x0;
                        plStack_3c8 = (longlong *)0x0;
                        plStack_3d8 = (longlong *)0x0;
                        plStack_3f0 = (longlong *)0x0;
                        plStack_3d0 = (longlong *)0x0;
                        plStack_3e8 = (longlong *)0x0;
                        *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        plVar29 = (longlong *)FUN_23e8bd600(lVar26,plVar17);
                        if (plVar29 == (longlong *)0x0) {
LAB_23e759690:
                          pcVar43 = (code *)0x0;
                          auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                          pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                          plVar37 = (longlong *)0x0;
                          plVar29 = (longlong *)0x0;
                          *(undefined8 *)(lVar26 + 0x70) = 0;
                          uVar40 = 0x380;
                          plStack_3e0 = (longlong *)0x0;
                          plStack_3c8 = (longlong *)0x0;
                          plStack_3d8 = (longlong *)0x0;
                          plStack_3f0 = (longlong *)0x0;
                          plStack_3d0 = (longlong *)0x0;
                          plStack_3e8 = (longlong *)0x0;
                          *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          lVar15 = *plVar29 + -1;
                          *plVar29 = lVar15;
                          if (plVar29[2] == 0) {
                            pcVar43 = _Py_TrueStruct_exref;
                            if (lVar15 == 0) {
                              (**(code **)(plVar29[1] + 0x30))(plVar29);
                              pcVar43 = _Py_TrueStruct_exref;
                            }
                          }
                          else {
                            pcVar43 = _Py_FalseStruct_exref;
                            if (lVar15 == 0) {
                              (**(code **)(plVar29[1] + 0x30))(plVar29);
                              pcVar43 = _Py_FalseStruct_exref;
                            }
                          }
                          iVar12 = FUN_23a35f020(pcVar43);
                          if (iVar12 == 1) {
                            plVar29 = (longlong *)FUN_23e8bd600(lVar26,plVar25);
                            if (plVar29 == (longlong *)0x0) goto LAB_23e759690;
                            lVar15 = plVar29[2];
                            lVar34 = *plVar29 + -1;
                            *plVar29 = lVar34;
                            if (lVar15 == 0) {
                              if (lVar34 == 0) {
                                (**(code **)(plVar29[1] + 0x30))(plVar29);
                              }
                            }
                            else {
                              if (lVar34 == 0) {
                                (**(code **)(plVar29[1] + 0x30))(plVar29);
                              }
                              pcVar43 = _Py_TrueStruct_exref;
                              if (0 < lVar15) goto LAB_23e75855a;
                            }
                            pcVar43 = _Py_FalseStruct_exref;
                          }
LAB_23e75855a:
                          lVar34 = DAT_23eed8950;
                          *(longlong *)pcVar43 = *(longlong *)pcVar43 + 1;
                          lVar15 = *(longlong *)(lVar34 + 0x20);
                          if (*(char *)(lVar15 + 10) == '\0') {
                            plVar29 = (longlong *)FUN_23a37a020(lVar34,DAT_23eed9258);
                            if (plVar29 == (longlong *)0x0) goto LAB_23e759370;
                            lVar34 = *plVar29;
LAB_23e759364:
                            if (lVar34 == 0) goto LAB_23e759370;
                          }
                          else {
                            iVar12 = *(int *)(lVar15 + 0xc);
                            if (*(int *)(lVar15 + 0xc) == 0) {
                              *(int *)(lVar15 + 0xc) = DAT_23ec1545c;
                              iVar12 = DAT_23ec1545c;
                              DAT_23ec1545c = DAT_23ec1545c + 1;
                            }
                            if (DAT_23ec15428 != iVar12) {
                              DAT_23ec15428 = iVar12;
                              DAT_23eedadd8 =
                                   FUN_23e8cbd60(lVar15,DAT_23eed9258,
                                                 *(undefined8 *)(DAT_23eed9258 + 0x18));
                            }
                            if (-1 < DAT_23eedadd8) {
                              lVar1 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
                              lVar34 = *(longlong *)(lVar1 + 8 + DAT_23eedadd8 * 0x10);
                              if (lVar34 != 0) goto LAB_23e7585d0;
                              DAT_23eedadd8 =
                                   FUN_23e8cbd60(lVar15,DAT_23eed9258,
                                                 *(undefined8 *)(DAT_23eed9258 + 0x18));
                              if (-1 < DAT_23eedadd8) {
                                lVar34 = *(longlong *)(lVar1 + 8 + DAT_23eedadd8 * 0x10);
                                goto LAB_23e759364;
                              }
                            }
LAB_23e759370:
                            plVar29 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eed9258);
                            if ((plVar29 == (longlong *)0x0) || (lVar34 = *plVar29, lVar34 == 0)) {
                              plVar37 = (longlong *)0x0;
                              plVar29 = (longlong *)0x0;
                              FUN_23e915740(lVar26,auStack_388,DAT_23eed9258);
                              plStack_3e0 = (longlong *)0x0;
                              uVar40 = 0x382;
                              plStack_3c8 = (longlong *)0x0;
                              plStack_3d8 = (longlong *)0x0;
                              plStack_3f0 = (longlong *)0x0;
                              plStack_3d0 = (longlong *)0x0;
                              plStack_3e8 = (longlong *)0x0;
                              goto LAB_23e758dff;
                            }
                          }
LAB_23e7585d0:
                          plVar29 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eed8aa8);
                          if (plVar29 == (longlong *)0x0) {
                            auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                            pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                            plVar37 = (longlong *)0x0;
                            plVar29 = (longlong *)0x0;
                            *(undefined8 *)(lVar26 + 0x70) = 0;
                            uVar40 = 0x382;
                            plStack_3e0 = (longlong *)0x0;
                            plStack_3c8 = (longlong *)0x0;
                            plStack_3d8 = (longlong *)0x0;
                            plStack_3f0 = (longlong *)0x0;
                            plStack_3e8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                            plStack_3d0 = (longlong *)0x0;
                          }
                          else {
                            plStack_3e8 = (longlong *)FUN_23a38cc10(lVar26,lVar34,plVar29);
                            lVar15 = *plVar29;
                            *plVar29 = lVar15 + -1;
                            if (lVar15 + -1 == 0) {
                              (**(code **)(plVar29[1] + 0x30))(plVar29);
                            }
                            if (plStack_3e8 == (longlong *)0x0) {
                              auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                              pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                              plVar37 = (longlong *)0x0;
                              plVar29 = (longlong *)0x0;
                              *(undefined8 *)(lVar26 + 0x70) = 0;
                              uVar40 = 0x382;
                              plStack_3e0 = (longlong *)0x0;
                              plStack_3c8 = (longlong *)0x0;
                              plStack_3d8 = (longlong *)0x0;
                              plStack_3f0 = (longlong *)0x0;
                              plStack_3d0 = (longlong *)0x0;
                              *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                            }
                            else {
                              lVar15 = *(longlong *)(DAT_23eed8950 + 0x20);
                              if (*(char *)(lVar15 + 10) == '\0') {
                                plVar29 = (longlong *)FUN_23a37a020(DAT_23eed8950,DAT_23eed9260);
                                if (plVar29 == (longlong *)0x0) goto LAB_23e759600;
                                lVar34 = *plVar29;
LAB_23e7595f5:
                                if (lVar34 == 0) goto LAB_23e759600;
                              }
                              else {
                                iVar12 = *(int *)(lVar15 + 0xc);
                                if (*(int *)(lVar15 + 0xc) == 0) {
                                  *(int *)(lVar15 + 0xc) = DAT_23ec1545c;
                                  iVar12 = DAT_23ec1545c;
                                  DAT_23ec1545c = DAT_23ec1545c + 1;
                                }
                                if (DAT_23ec1542c != iVar12) {
                                  DAT_23ec1542c = iVar12;
                                  DAT_23eedade0 =
                                       FUN_23e8cbd60(lVar15,DAT_23eed9260,
                                                     *(undefined8 *)(DAT_23eed9260 + 0x18));
                                }
                                if (-1 < DAT_23eedade0) {
                                  lVar1 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
                                  lVar34 = *(longlong *)(lVar1 + 8 + DAT_23eedade0 * 0x10);
                                  if (lVar34 != 0) goto LAB_23e7586a4;
                                  DAT_23eedade0 =
                                       FUN_23e8cbd60(lVar15,DAT_23eed9260,
                                                     *(undefined8 *)(DAT_23eed9260 + 0x18));
                                  if (-1 < DAT_23eedade0) {
                                    lVar34 = *(longlong *)(lVar1 + 8 + DAT_23eedade0 * 0x10);
                                    goto LAB_23e7595f5;
                                  }
                                }
LAB_23e759600:
                                plVar29 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eed9260);
                                if ((plVar29 == (longlong *)0x0) || (lVar34 = *plVar29, lVar34 == 0)
                                   ) {
                                  plVar37 = (longlong *)0x0;
                                  plVar29 = (longlong *)0x0;
                                  FUN_23e915740(lVar26,auStack_388,DAT_23eed9260);
                                  plStack_3e0 = (longlong *)0x0;
                                  uVar40 = 899;
                                  plStack_3c8 = (longlong *)0x0;
                                  plStack_3d8 = (longlong *)0x0;
                                  plStack_3f0 = (longlong *)0x0;
                                  plStack_3d0 = (longlong *)0x0;
                                  goto LAB_23e758dff;
                                }
                              }
LAB_23e7586a4:
                              plVar29 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eed8aa8);
                              if (plVar29 == (longlong *)0x0) {
                                auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                plStack_3e0 = (longlong *)0x0;
                                plVar37 = (longlong *)0x0;
                                *(undefined8 *)(lVar26 + 0x70) = 0;
                                uVar40 = 899;
                                plStack_3c8 = (longlong *)0x0;
                                plStack_3d8 = (longlong *)0x0;
                                plStack_3f0 = (longlong *)0x0;
                                plStack_3d0 = (longlong *)0x0;
                                *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                                plVar29 = (longlong *)0x0;
                              }
                              else {
                                plStack_3d0 = (longlong *)FUN_23a38cc10(lVar26,lVar34,plVar29);
                                *plVar29 = *plVar29 + -1;
                                if (*plVar29 == 0) {
                                  (**(code **)(plVar29[1] + 0x30))(plVar29);
                                }
                                if (plStack_3d0 == (longlong *)0x0) {
                                  auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                  pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                  plVar37 = (longlong *)0x0;
                                  plVar29 = (longlong *)0x0;
                                  *(undefined8 *)(lVar26 + 0x70) = 0;
                                  uVar40 = 899;
                                  plStack_3e0 = (longlong *)0x0;
                                  plStack_3c8 = (longlong *)0x0;
                                  plStack_3d8 = (longlong *)0x0;
                                  plStack_3f0 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                                }
                                else {
                                  plVar37 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eed8af8);
                                  plVar29 = (longlong *)0x0;
                                  if (plVar37 == (longlong *)0x0) {
LAB_23e759950:
                                    auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                    pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                    plStack_3e0 = (longlong *)0x0;
                                    plVar37 = (longlong *)0x0;
                                    *(undefined8 *)(lVar26 + 0x70) = 0;
                                    uVar40 = 0x386;
                                    plStack_3c8 = (longlong *)0x0;
                                    plStack_3d8 = (longlong *)0x0;
                                    plStack_3f0 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    plVar28 = (longlong *)FUN_23e8bc2f0(plVar37,DAT_23eed9268);
                                    *plVar37 = *plVar37 + -1;
                                    if (*plVar37 == 0) {
                                      (**(code **)(plVar37[1] + 0x30))(plVar37);
                                    }
                                    lVar15 = DAT_23eed9270;
                                    if (plVar28 == (longlong *)0x0) {
                                      auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                      pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                      plStack_3e0 = (longlong *)0x0;
                                      plVar29 = (longlong *)0x0;
                                      *(undefined8 *)(lVar26 + 0x70) = 0;
                                      uVar40 = 0x386;
                                      plStack_3c8 = (longlong *)0x0;
                                      plStack_3d8 = (longlong *)0x0;
                                      plStack_3f0 = (longlong *)0x0;
                                      *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
                                      plVar37 = (longlong *)0x0;
                                    }
                                    else {
                                      *(undefined4 *)(ppppppcVar4 + 5) = 0x386;
                                      plVar29 = (longlong *)
                                                FUN_23e9186b0(lVar26,plVar28,lVar15 + 0x18,
                                                              DAT_23eed8ce8);
                                      *plVar28 = *plVar28 + -1;
                                      if (*plVar28 == 0) {
                                        (**(code **)(plVar28[1] + 0x30))(plVar28);
                                      }
                                      if (plVar29 == (longlong *)0x0) goto LAB_23e759950;
                                      iVar12 = FUN_23a35f020(plVar29);
                                      if (iVar12 == -1) {
LAB_23e75a60d:
                                        pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                        auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                        uVar40 = 0x388;
                                        *(undefined8 *)(lVar26 + 0x70) = 0;
                                        *(undefined1 (*) [16])(lVar26 + 0x60) =
                                             (undefined1  [16])0x0;
LAB_23e75a63c:
                                        plStack_3e0 = (longlong *)0x0;
                                        plVar37 = (longlong *)0x0;
                                        plStack_3c8 = (longlong *)0x0;
                                        plStack_3d8 = (longlong *)0x0;
                                        plStack_3f0 = (longlong *)0x0;
                                      }
                                      else if (iVar12 == 0) {
LAB_23e75879d:
                                        iVar12 = FUN_23a35f020(pcVar43);
                                        lVar34 = DAT_23eed92d8;
                                        lVar15 = DAT_23eed92d0;
                                        uVar45 = DAT_23eed8b40;
                                        if (iVar12 == -1) {
                                          auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                          pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                          uVar40 = 0x39c;
                                          *(undefined8 *)(lVar26 + 0x70) = 0;
                                          *(undefined1 (*) [16])(lVar26 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e75a63c;
                                        }
                                        if (iVar12 == 0) {
                                          *(undefined4 *)(ppppppcVar4 + 5) = 0x3a1;
                                          plVar37 = (longlong *)
                                                    FUN_23e915840(lVar26,plVar13,uVar45,
                                                                  *(undefined8 *)(lVar34 + 0x18));
                                          if (plVar37 == (longlong *)0x0) {
                                            auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                            pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                            *(undefined8 *)(lVar26 + 0x70) = 0;
                                            plStack_3e0 = (longlong *)0x0;
                                            plStack_3c8 = (longlong *)0x0;
                                            plStack_3d8 = (longlong *)0x0;
                                            plStack_3f0 = (longlong *)0x0;
                                            *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            plVar37 = (longlong *)0x0;
                                            uVar40 = 0x3a1;
                                          }
                                          else {
LAB_23e7588d7:
                                            *plVar37 = *plVar37 + -1;
                                            if (*plVar37 == 0) {
                                              (**(code **)(plVar37[1] + 0x30))(plVar37);
                                            }
                                            plStack_3e0 = (longlong *)0x0;
                                            plVar37 = (longlong *)0x0;
                                            plStack_3c8 = (longlong *)0x0;
                                            plStack_3d8 = (longlong *)0x0;
                                            plStack_3f0 = (longlong *)0x0;
LAB_23e758917:
                                            lVar15 = FUN_23e8e0e20();
                                            if (lVar15 == 0) {
                                              FUN_23e915740(lVar26,auStack_388,DAT_23eed8988);
                                              uVar40 = 0x3a3;
                                            }
                                            else {
                                              plVar28 = (longlong *)
                                                        FUN_23e8bc2f0(lVar15,DAT_23eed8990);
                                              if (plVar28 != (longlong *)0x0) {
                                                cVar11 = FUN_23e8d9ac0(plVar13,DAT_23eed8998,plVar28
                                                                      );
                                                *plVar28 = *plVar28 + -1;
                                                if (*plVar28 == 0) {
                                                  (**(code **)(plVar28[1] + 0x30))(plVar28);
                                                }
                                                if (cVar11 != '\0') {
                                                  lVar15 = *(longlong *)
                                                            (*(longlong *)(lVar26 + 0x38) + 8);
                                                  plVar28 = *(longlong **)(lVar15 + 0x28);
                                                  plVar38 = (longlong *)plVar28[2];
                                                  *(undefined8 *)(*(longlong *)(lVar26 + 0x38) + 8)
                                                       = *(undefined8 *)(lVar15 + 0x30);
                                                  *(undefined4 *)(plVar28 + 8) = 0xffffffff;
                                                  if (plVar38 != (longlong *)0x0) {
                                                    plVar28[2] = 0;
                                                    *plVar38 = *plVar38 + -1;
                                                    if (*plVar38 == 0) {
                                                      (**(code **)(plVar38[1] + 0x30))();
                                                    }
                                                  }
                                                  *plVar28 = *plVar28 + -1;
                                                  if (*plVar28 == 0) {
                                                    (**(code **)(plVar28[1] + 0x30))(plVar28);
                                                  }
                                                  plVar28[0xf] = 0;
                                                  pppppppcVar36 = (code *******)_Py_NoneStruct_exref
                                                  ;
                                                  *(longlong *)_Py_NoneStruct_exref =
                                                       *(longlong *)_Py_NoneStruct_exref + 1;
                                                  *plVar17 = *plVar17 + -1;
                                                  if (*plVar17 == 0) {
                                                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                                                  }
                                                  *plVar25 = *plVar25 + -1;
                                                  if (*plVar25 == 0) {
                                                    (**(code **)(plVar25[1] + 0x30))(plVar25);
                                                  }
                                                  *(longlong *)pcVar43 = *(longlong *)pcVar43 + -1;
                                                  if (*(longlong *)pcVar43 == 0) {
                                                    (**(code **)(*(longlong *)(pcVar43 + 8) + 0x30))
                                                              (pcVar43);
                                                  }
                                                  lVar15 = *plStack_3e8;
                                                  *plStack_3e8 = lVar15 + -1;
                                                  if (lVar15 + -1 == 0) {
                                                    (**(code **)(plStack_3e8[1] + 0x30))
                                                              (plStack_3e8);
                                                  }
                                                  lVar15 = *plStack_3d0;
                                                  *plStack_3d0 = lVar15 + -1;
                                                  if (lVar15 + -1 == 0) {
                                                    (**(code **)(plStack_3d0[1] + 0x30))();
                                                  }
                                                  *plVar29 = *plVar29 + -1;
                                                  if (*plVar29 == 0) {
                                                    (**(code **)(plVar29[1] + 0x30))(plVar29);
                                                  }
                                                  if ((plVar37 != (longlong *)0x0) &&
                                                     (*plVar37 = *plVar37 + -1, *plVar37 == 0)) {
                                                    (**(code **)(plVar37[1] + 0x30))(plVar37);
                                                  }
                                                  if ((plStack_3f0 != (longlong *)0x0) &&
                                                     (lVar15 = *plStack_3f0,
                                                     *plStack_3f0 = lVar15 + -1, lVar15 + -1 == 0))
                                                  {
                                                    (**(code **)(plStack_3f0[1] + 0x30))
                                                              (plStack_3f0);
                                                  }
                                                  if ((plStack_3d8 != (longlong *)0x0) &&
                                                     (lVar15 = *plStack_3d8,
                                                     *plStack_3d8 = lVar15 + -1, lVar15 + -1 == 0))
                                                  {
                                                    (**(code **)(plStack_3d8[1] + 0x30))();
                                                  }
                                                  if ((plStack_3c8 != (longlong *)0x0) &&
                                                     (lVar15 = *plStack_3c8,
                                                     *plStack_3c8 = lVar15 + -1, lVar15 + -1 == 0))
                                                  {
                                                    (**(code **)(plStack_3c8[1] + 0x30))
                                                              (plStack_3c8);
                                                  }
                                                  if ((plStack_3e0 != (longlong *)0x0) &&
                                                     (lVar15 = *plStack_3e0,
                                                     *plStack_3e0 = lVar15 + -1, lVar15 + -1 == 0))
                                                  {
                                                    (**(code **)(plStack_3e0[1] + 0x30))
                                                              (plStack_3e0);
                                                    *plVar13 = *plVar13 + -1;
                                                    lVar15 = *plVar13;
                                                    goto joined_r0x00023e758d17;
                                                  }
                                                  goto LAB_23e758d12;
                                                }
                                              }
                                              auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                              pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                              *(undefined8 *)(lVar26 + 0x70) = 0;
                                              *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              uVar40 = 0x3a3;
                                            }
                                          }
                                        }
                                        else {
                                          *(undefined4 *)(ppppppcVar4 + 5) = 0x39d;
                                          plVar37 = (longlong *)
                                                    FUN_23e915840(lVar26,plVar13,uVar45,
                                                                  *(undefined8 *)(lVar15 + 0x18));
                                          if (plVar37 == (longlong *)0x0) {
                                            auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                            pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                            *(undefined8 *)(lVar26 + 0x70) = 0;
                                            plStack_3e0 = (longlong *)0x0;
                                            plStack_3c8 = (longlong *)0x0;
                                            plStack_3d8 = (longlong *)0x0;
                                            plStack_3f0 = (longlong *)0x0;
                                            *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            plVar37 = (longlong *)0x0;
                                            uVar40 = 0x39d;
                                          }
                                          else {
                                            *plVar37 = *plVar37 + -1;
                                            if (*plVar37 == 0) {
                                              (**(code **)(plVar37[1] + 0x30))(plVar37);
                                            }
                                            plVar37 = (longlong *)
                                                      FUN_23e8bc2f0(plVar13,DAT_23eed8a98);
                                            if (plVar37 == (longlong *)0x0) {
                                              auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                              pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                              plVar37 = (longlong *)0x0;
                                              *(undefined8 *)(lVar26 + 0x70) = 0;
                                              plStack_3e0 = (longlong *)0x0;
                                              plStack_3c8 = (longlong *)0x0;
                                              plStack_3d8 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plStack_3f0 = (longlong *)0x0;
                                              uVar40 = 0x39e;
                                            }
                                            else {
                                              plVar28 = (longlong *)
                                                        FUN_23e8bc2f0(plVar37,DAT_23eed92c0);
                                              lVar15 = *plVar37;
                                              *plVar37 = lVar15 + -1;
                                              if (lVar15 + -1 == 0) {
                                                (**(code **)(plVar37[1] + 0x30))(plVar37);
                                              }
                                              if (plVar28 != (longlong *)0x0) {
                                                *plStack_3d0 = *plStack_3d0 + 1;
                                                plStack_398 = plVar28;
                                                plStack_390 = plStack_3d0;
                                                plVar37 = (longlong *)
                                                          FUN_23ab01810(lVar26,&plStack_398);
                                                if (plVar37 != (longlong *)0x0) {
                                                  *plVar37 = *plVar37 + -1;
                                                  if (*plVar37 == 0) {
                                                    (**(code **)(plVar37[1] + 0x30))(plVar37);
                                                  }
                                                  lVar15 = FUN_23e8e0ba0();
                                                  if (lVar15 == 0) {
                                                    FUN_23e915740(lVar26,auStack_388);
                                                  }
                                                  else {
                                                    *(undefined4 *)(ppppppcVar4 + 5) = 0x39f;
                                                    plVar37 = (longlong *)
                                                              FUN_23e915840(lVar26,lVar15);
                                                    if (plVar37 != (longlong *)0x0)
                                                    goto LAB_23e7588d7;
                                                    pppppppcStack_378 =
                                                         *(code ********)(lVar26 + 0x70);
                                                    auStack_388 = *(undefined1 (*) [16])
                                                                   (lVar26 + 0x60);
                                                    *(undefined8 *)(lVar26 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  plVar37 = (longlong *)0x0;
                                                  plStack_3e0 = (longlong *)0x0;
                                                  plStack_3c8 = (longlong *)0x0;
                                                  plStack_3d8 = (longlong *)0x0;
                                                  plStack_3f0 = (longlong *)0x0;
                                                  uVar40 = 0x39f;
                                                  goto LAB_23e758dff;
                                                }
                                              }
                                              plVar37 = (longlong *)0x0;
                                              auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                              pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                              plStack_3e0 = (longlong *)0x0;
                                              *(undefined8 *)(lVar26 + 0x70) = 0;
                                              plStack_3c8 = (longlong *)0x0;
                                              plStack_3d8 = (longlong *)0x0;
                                              plStack_3f0 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              uVar40 = 0x39e;
                                            }
                                          }
                                        }
                                      }
                                      else {
                                        plVar37 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eed89b0);
                                        if (plVar37 == (longlong *)0x0) {
                                          auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                          pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                          plStack_3e0 = (longlong *)0x0;
                                          uVar40 = 0x388;
                                          *(undefined8 *)(lVar26 + 0x70) = 0;
                                          plStack_3c8 = (longlong *)0x0;
                                          plStack_3d8 = (longlong *)0x0;
                                          plStack_3f0 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(lVar26 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plVar37 = (longlong *)0x0;
                                        }
                                        else {
                                          *(undefined4 *)(ppppppcVar4 + 5) = 0x388;
                                          plVar28 = (longlong *)
                                                    FUN_23e91bfe0(lVar26,plVar37,DAT_23eed8d38);
                                          *plVar37 = *plVar37 + -1;
                                          if (*plVar37 == 0) {
                                            (**(code **)(plVar37[1] + 0x30))(plVar37);
                                          }
                                          if (plVar28 != (longlong *)0x0) {
                                            iVar12 = FUN_23a35f020(plVar28);
                                            lVar15 = *plVar28;
                                            *plVar28 = lVar15 + -1;
                                            if (lVar15 + -1 == 0) {
                                              (**(code **)(plVar28[1] + 0x30))(plVar28);
                                            }
                                            if (iVar12 == -1) goto LAB_23e75a60d;
                                            if (iVar12 != 0) goto LAB_23e75879d;
                                            plVar28 = (longlong *)FUN_23a388310(plVar29);
                                            if (plVar28 == (longlong *)0x0) {
                                              uVar45 = *(undefined8 *)(lVar26 + 0x60);
                                              uVar46 = *(undefined8 *)(lVar26 + 0x68);
                                              pppppppcVar36 = *(code ********)(lVar26 + 0x70);
                                              *(undefined8 *)(lVar26 + 0x70) = 0;
                                              *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                   (undefined1  [16])0x0;
                                            }
                                            else {
                                              plVar37 = (longlong *)
                                                        (**(code **)(plVar28[1] + 0xe0))(plVar28);
                                              if ((plVar37 == (longlong *)0x0) &&
                                                 (plVar37 = (longlong *)
                                                            FUN_23a3c1b70(lVar26,auStack_388,0),
                                                 plVar37 == (longlong *)0x0)) {
                                                plStack_3d8 = (longlong *)0x0;
                                                plStack_3f0 = (longlong *)0x0;
                                              }
                                              else {
                                                plStack_3f0 = (longlong *)
                                                              (**(code **)(plVar28[1] + 0xe0))
                                                                        (plVar28);
                                                if ((plStack_3f0 == (longlong *)0x0) &&
                                                   (plStack_3f0 = (longlong *)
                                                                  FUN_23a3c1b70(lVar26,auStack_388,1
                                                                                ,3),
                                                   plStack_3f0 == (longlong *)0x0)) {
                                                  plStack_3d8 = (longlong *)0x0;
                                                }
                                                else {
                                                  plStack_3d8 = (longlong *)
                                                                (**(code **)(plVar28[1] + 0xe0))
                                                                          (plVar28);
                                                  if (((plStack_3d8 != (longlong *)0x0) ||
                                                      (plStack_3d8 = (longlong *)
                                                                     FUN_23a3c1b70(lVar26,
                                                  auStack_388,2,3), plStack_3d8 != (longlong *)0x0))
                                                  && (cVar11 = FUN_23a3884a0(lVar26,auStack_388,
                                                                             plVar28,3),
                                                     cVar11 != '\0')) {
                                                    *plVar28 = *plVar28 + -1;
                                                    if (*plVar28 == 0) {
                                                      (**(code **)(plVar28[1] + 0x30))(plVar28);
                                                    }
                                                    if (*plVar37 == 0) {
                                                      (**(code **)(plVar37[1] + 0x30))(plVar37);
                                                    }
                                                    if (*plStack_3f0 == 0) {
                                                      (**(code **)(plStack_3f0[1] + 0x30))();
                                                    }
                                                    if (*plStack_3d8 == 0) {
                                                      (**(code **)(plStack_3d8[1] + 0x30))();
                                                    }
                                                    plVar38 = (longlong *)
                                                              FUN_23e8bc2f0(plVar13,DAT_23eed8b40);
                                                    plVar28 = DAT_23eed9278;
                                                    if (plVar38 == (longlong *)0x0) {
                                                      auStack_388 = *(undefined1 (*) [16])
                                                                     (lVar26 + 0x60);
                                                      pppppppcStack_378 =
                                                           *(code ********)(lVar26 + 0x70);
                                                      uVar40 = 0x38a;
                                                      *(undefined8 *)(lVar26 + 0x70) = 0;
                                                      plStack_3c8 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_3e0 = (longlong *)0x0;
                                                      goto LAB_23e758dff;
                                                    }
                                                    lVar15 = *(longlong *)(lVar26 + 0x10);
                                                    plVar31 = *(longlong **)(lVar15 + 0xe38);
                                                    if (plVar31 == (longlong *)0x0) {
                                                      plVar31 = (longlong *)
                                                                FUN_23e916a20(PyTuple_Type_exref,5);
                                                    }
                                                    else {
                                                      lVar34 = plVar31[3];
                                                      *(int *)(lVar15 + 0xec8) =
                                                           *(int *)(lVar15 + 0xec8) + -1;
                                                      *(longlong *)(lVar15 + 0xe38) = lVar34;
                                                      *plVar31 = 1;
                                                    }
                                                    pcVar35 = _PyRuntime_exref;
                                                    *(undefined1 (*) [16])(plVar31 + 4) =
                                                         (undefined1  [16])0x0;
                                                    lVar15 = *(longlong *)(pcVar35 + 0x1f8);
                                                    *(undefined1 (*) [16])(plVar31 + 6) =
                                                         (undefined1  [16])0x0;
                                                    lVar15 = *(longlong *)
                                                              (*(longlong *)(lVar15 + 0x10) + 0x2e8)
                                                    ;
                                                    lVar34 = plVar31[-1];
                                                    puVar27 = *(undefined8 **)(lVar15 + 8);
                                                    *puVar27 = plVar31 + -2;
                                                    plVar31[-2] = lVar15;
                                                    plVar31[-1] = (ulonglong)((uint)lVar34 & 3) |
                                                                  (ulonglong)puVar27;
                                                    *(longlong **)(lVar15 + 8) = plVar31 + -2;
                                                    *plVar28 = *plVar28 + 1;
                                                    plVar31[3] = (longlong)plVar28;
                                                    plVar28 = DAT_23ed6cd28;
                                                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                      plVar33 = (longlong *)
                                                                PyDict_GetItemString
                                                                          (DAT_23ed6ccc0,"format");
                                                      if (plVar33 != (longlong *)0x0) {
                                                        *plVar33 = *plVar33 + 1;
                                                        DAT_23ed6a4c0 = plVar33;
                                                        goto LAB_23e759d0b;
                                                      }
LAB_23e75b151:
                                                      PyErr_PrintEx(0);
                                                      Py_Exit(1);
LAB_23e75b164:
                                                      auStack_388 = *(undefined1 (*) [16])
                                                                     (lVar26 + 0x60);
                                                      pppppppcStack_378 =
                                                           *(code ********)(lVar26 + 0x70);
                                                      uVar40 = 0x38a;
                                                      *(undefined8 *)(lVar26 + 0x70) = 0;
                                                      plStack_3e0 = (longlong *)0x0;
                                                      plStack_3c8 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      goto LAB_23e758dff;
                                                    }
LAB_23e759d0b:
                                                    plStack_398 = plStack_3f0;
                                                    plStack_390 = plVar28;
                                                    lVar15 = FUN_23e94ed00(lVar26,DAT_23ed6a4c0,
                                                                           &plStack_398);
                                                    if (lVar15 != 0) {
                                                      plVar31[4] = lVar15;
                                                      plVar28 = DAT_23eed9280;
                                                      *DAT_23eed9280 = *DAT_23eed9280 + 1;
                                                      plVar31[5] = (longlong)plVar28;
                                                      plVar28 = DAT_23ed6cd28;
                                                      if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                        plVar33 = (longlong *)
                                                                  PyDict_GetItemString
                                                                            (DAT_23ed6ccc0,"format")
                                                        ;
                                                        if (plVar33 == (longlong *)0x0)
                                                        goto LAB_23e75b151;
                                                        *plVar33 = *plVar33 + 1;
                                                        DAT_23ed6a4c0 = plVar33;
                                                      }
                                                      plStack_398 = plStack_3d8;
                                                      plStack_390 = plVar28;
                                                      lVar15 = FUN_23e94ed00(lVar26,DAT_23ed6a4c0,
                                                                             &plStack_398);
                                                      if (lVar15 != 0) {
                                                        plVar31[6] = lVar15;
                                                        plVar28 = DAT_23eed9288;
                                                        *DAT_23eed9288 = *DAT_23eed9288 + 1;
                                                        plVar31[7] = (longlong)plVar28;
                                                        plVar28 = (longlong *)
                                                                  PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar31);
                                                        *plVar31 = *plVar31 + -1;
                                                        if (*plVar31 == 0) {
                                                          FUN_23a334bc0(plVar31);
                                                        }
                                                        if (plVar28 == (longlong *)0x0) {
                                                          auStack_388 = *(undefined1 (*) [16])
                                                                         (lVar26 + 0x60);
                                                          pppppppcStack_378 =
                                                               *(code ********)(lVar26 + 0x70);
                                                          *(undefined8 *)(lVar26 + 0x70) = 0;
                                                          lVar15 = *plVar38;
                                                          *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar38 = lVar15 + -1;
                                                          plStack_3c8 = (longlong *)0x0;
                                                          if (lVar15 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                            uVar40 = 0x38a;
                                                            plStack_3e0 = (longlong *)0x0;
                                                          }
                                                          else {
                                                            uVar40 = 0x38a;
                                                            plStack_3e0 = (longlong *)0x0;
                                                          }
                                                        }
                                                        else {
                                                          *(undefined4 *)(ppppppcVar4 + 5) = 0x38a;
                                                          plVar31 = (longlong *)
                                                                    FUN_23e914090(lVar26,plVar38);
                                                          lVar15 = *plVar38;
                                                          *plVar38 = lVar15 + -1;
                                                          if (lVar15 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          lVar15 = *plVar28;
                                                          *plVar28 = lVar15 + -1;
                                                          if (lVar15 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          if (plVar31 == (longlong *)0x0)
                                                          goto LAB_23e75b164;
                                                          *plVar31 = *plVar31 + -1;
                                                          if (*plVar31 == 0) {
                                                            FUN_23a334bc0(plVar31);
                                                          }
                                                          plStack_3c8 = (longlong *)
                                                                        FUN_23e8bc2f0(plVar13,
                                                  DAT_23eed8a60);
                                                  if (plStack_3c8 == (longlong *)0x0) {
                                                    auStack_388 = *(undefined1 (*) [16])
                                                                   (lVar26 + 0x60);
                                                    pppppppcStack_378 =
                                                         *(code ********)(lVar26 + 0x70);
                                                    uVar40 = 0x38d;
                                                    *(undefined8 *)(lVar26 + 0x70) = 0;
                                                    plStack_3e0 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plStack_3c8 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    plStack_398 = plStack_3c8;
                                                    cVar11 = FUN_23e8c72f0(&plStack_398,
                                                                           DAT_23ed6ccf8);
                                                    plVar28 = plStack_398;
                                                    if (cVar11 != '\0') {
                                                      plStack_3c8 = plStack_398;
                                                      cVar11 = FUN_23e8d9ac0(plVar13,DAT_23eed8a60);
                                                      if (cVar11 != '\0') {
                                                        lVar15 = *plVar28;
                                                        *plVar28 = lVar15 + -1;
                                                        if (lVar15 + -1 == 0) {
                                                          FUN_23a334bc0(plVar28);
                                                        }
                                                        *(undefined4 *)(ppppppcVar4 + 5) = 0x38e;
                                                        plStack_3c8 = (longlong *)
                                                                      FUN_23e91bfe0(lVar26,plVar13,
                                                                                    DAT_23eed9290);
                                                        if (plStack_3c8 == (longlong *)0x0) {
                                                          auStack_388 = *(undefined1 (*) [16])
                                                                         (lVar26 + 0x60);
                                                          pppppppcStack_378 =
                                                               *(code ********)(lVar26 + 0x70);
                                                          uVar40 = 0x38e;
                                                          *(undefined8 *)(lVar26 + 0x70) = 0;
                                                          plStack_3e0 = (longlong *)0x0;
                                                          *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                        }
                                                        else {
                                                          lVar15 = FUN_23e8e07b0();
                                                          if (lVar15 == 0) {
                                                            FUN_23e915740(lVar26,auStack_388,
                                                                          DAT_23eed8f68);
                                                            uVar40 = 0x38f;
                                                            plStack_3e0 = (longlong *)0x0;
                                                          }
                                                          else {
                                                            *(undefined4 *)(ppppppcVar4 + 5) = 0x38f
                                                            ;
                                                            plStack_3e0 = (longlong *)
                                                                          FUN_23e91a870(lVar26,
                                                  lVar15);
                                                  if (plStack_3e0 == (longlong *)0x0) {
                                                    auStack_388 = *(undefined1 (*) [16])
                                                                   (lVar26 + 0x60);
                                                    pppppppcStack_378 =
                                                         *(code ********)(lVar26 + 0x70);
                                                    uVar40 = 0x38f;
                                                    *(undefined8 *)(lVar26 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    plVar28 = (longlong *)
                                                              FUN_23e8bc2f0(plStack_3e0,
                                                                            DAT_23eed9298);
                                                    if (plVar28 == (longlong *)0x0) {
LAB_23e75b0b3:
                                                      auStack_388 = *(undefined1 (*) [16])
                                                                     (lVar26 + 0x60);
                                                      pppppppcStack_378 =
                                                           *(code ********)(lVar26 + 0x70);
                                                      uVar40 = 0x390;
                                                      *(undefined8 *)(lVar26 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      lVar15 = FUN_23e94f9d0(lVar26,plStack_3f0,
                                                                             DAT_23ed6cd28);
                                                      if (lVar15 == 0) {
LAB_23e75b057:
                                                        auStack_388 = *(undefined1 (*) [16])
                                                                       (lVar26 + 0x60);
                                                        pppppppcStack_378 =
                                                             *(code ********)(lVar26 + 0x70);
                                                        uVar40 = 0x390;
                                                        uVar41 = 0x390;
                                                        *(undefined8 *)(lVar26 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar28 = *plVar28 + -1;
                                                        lVar15 = *plVar28;
joined_r0x00023e75b088:
                                                        if (lVar15 == 0) {
LAB_23e75b08e:
                                                          FUN_23a334bc0(plVar28);
                                                          uVar40 = uVar41;
                                                        }
                                                      }
                                                      else {
                                                        plVar31 = (longlong *)
                                                                  FUN_23e916ad0(*(undefined8 *)
                                                                                 (lVar26 + 0x10),4);
                                                        plVar31[3] = lVar15;
                                                        plVar38 = DAT_23eed92a0;
                                                        *DAT_23eed92a0 = *DAT_23eed92a0 + 1;
                                                        plVar31[4] = (longlong)plVar38;
                                                        lVar15 = FUN_23e94f9d0(lVar26,plStack_3d8,
                                                                               DAT_23ed6cd28);
                                                        if (lVar15 == 0) {
                                                          auStack_388 = *(undefined1 (*) [16])
                                                                         (lVar26 + 0x60);
                                                          pppppppcStack_378 =
                                                               *(code ********)(lVar26 + 0x70);
                                                          *(undefined8 *)(lVar26 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar28 = *plVar28 + -1;
                                                          if (*plVar28 == 0) {
                                                            FUN_23a334bc0(plVar28);
                                                          }
                                                          *plVar31 = *plVar31 + -1;
                                                          if (*plVar31 == 0) {
                                                            FUN_23a334bc0(plVar31);
                                                          }
                                                          uVar40 = 0x390;
                                                        }
                                                        else {
                                                          plVar31[5] = lVar15;
                                                          plVar38 = DAT_23eed92a8;
                                                          *DAT_23eed92a8 = *DAT_23eed92a8 + 1;
                                                          plVar31[6] = (longlong)plVar38;
                                                          plVar38 = (longlong *)
                                                                    PyUnicode_Join(DAT_23ed6cd28,
                                                                                   plVar31);
                                                          *plVar31 = *plVar31 + -1;
                                                          if (*plVar31 == 0) {
                                                            FUN_23a334bc0(plVar31);
                                                          }
                                                          if (plVar38 == (longlong *)0x0)
                                                          goto LAB_23e75b057;
                                                          *(undefined4 *)(ppppppcVar4 + 5) = 0x390;
                                                          plStack_398 = plVar38;
                                                          plStack_390 = plStack_3c8;
                                                          plVar31 = (longlong *)
                                                                    FUN_23e94ed00(lVar26,plVar28);
                                                          *plVar28 = *plVar28 + -1;
                                                          if (*plVar28 == 0) {
                                                            FUN_23a334bc0(plVar28);
                                                          }
                                                          *plVar38 = *plVar38 + -1;
                                                          if (*plVar38 == 0) {
                                                            FUN_23a334bc0(plVar38);
                                                          }
                                                          if (plVar31 == (longlong *)0x0)
                                                          goto LAB_23e75b0b3;
                                                          *plVar31 = *plVar31 + -1;
                                                          if (*plVar31 == 0) {
                                                            FUN_23a334bc0(plVar31);
                                                          }
                                                          iVar12 = PySequence_Contains(plVar25,
                                                  plVar37);
                                                  if (iVar12 == -1) {
LAB_23e75b2bb:
                                                    auStack_388 = *(undefined1 (*) [16])
                                                                   (lVar26 + 0x60);
                                                    pppppppcStack_378 =
                                                         *(code ********)(lVar26 + 0x70);
                                                    uVar40 = 0x393;
                                                    *(undefined8 *)(lVar26 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e758dff;
                                                  }
                                                  if (iVar12 == 1) {
LAB_23e75a1db:
                                                    plVar28 = (longlong *)
                                                              FUN_23e8bc2f0(plVar13,DAT_23eed8b40);
                                                    plVar38 = DAT_23eed92b0;
                                                    if (plVar28 == (longlong *)0x0) {
LAB_23e75b349:
                                                      auStack_388 = *(undefined1 (*) [16])
                                                                     (lVar26 + 0x60);
                                                      pppppppcStack_378 =
                                                           *(code ********)(lVar26 + 0x70);
                                                      *(undefined8 *)(lVar26 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      uVar40 = 0x394;
                                                    }
                                                    else {
                                                      plVar31 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (lVar26 + 0x10),3);
                                                      *plVar38 = *plVar38 + 1;
                                                      plVar31[3] = (longlong)plVar38;
                                                      lVar15 = FUN_23e94f9d0(lVar26,plStack_3f0,
                                                                             DAT_23ed6cd28);
                                                      if (lVar15 == 0) {
                                                        auStack_388 = *(undefined1 (*) [16])
                                                                       (lVar26 + 0x60);
                                                        pppppppcStack_378 =
                                                             *(code ********)(lVar26 + 0x70);
                                                        *(undefined8 *)(lVar26 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar28 = *plVar28 + -1;
                                                        if (*plVar28 == 0) {
                                                          FUN_23a334bc0(plVar28);
                                                        }
                                                        *plVar31 = *plVar31 + -1;
                                                        if (*plVar31 == 0) {
                                                          FUN_23a334bc0(plVar31);
                                                        }
                                                        uVar40 = 0x394;
                                                      }
                                                      else {
                                                        plVar31[4] = lVar15;
                                                        plVar38 = DAT_23eed92b8;
                                                        *DAT_23eed92b8 = *DAT_23eed92b8 + 1;
                                                        plVar31[5] = (longlong)plVar38;
                                                        plVar38 = (longlong *)
                                                                  PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar31);
                                                        *plVar31 = *plVar31 + -1;
                                                        if (*plVar31 == 0) {
                                                          FUN_23a334bc0(plVar31);
                                                        }
                                                        if (plVar38 == (longlong *)0x0) {
                                                          auStack_388 = *(undefined1 (*) [16])
                                                                         (lVar26 + 0x60);
                                                          pppppppcStack_378 =
                                                               *(code ********)(lVar26 + 0x70);
                                                          *(undefined8 *)(lVar26 + 0x70) = 0;
                                                          uVar41 = 0x394;
                                                          *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar28 = *plVar28 + -1;
                                                          uVar40 = 0x394;
                                                          if (*plVar28 != 0) goto LAB_23e758dff;
                                                          goto LAB_23e75b08e;
                                                        }
                                                        *(undefined4 *)(ppppppcVar4 + 5) = 0x394;
                                                        plVar31 = (longlong *)
                                                                  FUN_23e914090(lVar26,plVar28);
                                                        *plVar28 = *plVar28 + -1;
                                                        if (*plVar28 == 0) {
                                                          FUN_23a334bc0(plVar28);
                                                        }
                                                        *plVar38 = *plVar38 + -1;
                                                        if (*plVar38 == 0) {
                                                          FUN_23a334bc0(plVar38);
                                                        }
                                                        if (plVar31 == (longlong *)0x0)
                                                        goto LAB_23e75b349;
                                                        *plVar31 = *plVar31 + -1;
                                                        if (*plVar31 == 0) {
                                                          FUN_23a334bc0(plVar31);
                                                        }
                                                        plVar28 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar13,
                                                  DAT_23eed8a98);
                                                  if (plVar28 != (longlong *)0x0) {
                                                    plVar38 = (longlong *)
                                                              FUN_23e8bc2f0(plVar28,DAT_23eed92c0);
                                                    *plVar28 = *plVar28 + -1;
                                                    if (*plVar28 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar38 != (longlong *)0x0) {
                                                      *plStack_3d0 = *plStack_3d0 + 1;
                                                      plStack_398 = plVar38;
                                                      plStack_390 = plStack_3d0;
                                                      plVar28 = (longlong *)
                                                                FUN_23ab01810(lVar26,&plStack_398);
                                                      if (plVar28 != (longlong *)0x0) {
LAB_23e75a40e:
                                                        *plVar28 = *plVar28 + -1;
                                                        if (*plVar28 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        lVar34 = FUN_23e8e0ba0();
                                                        lVar15 = DAT_23eed8ce0;
                                                        if (lVar34 == 0) {
                                                          FUN_23e915740(lVar26,auStack_388,
                                                                        DAT_23eed8c70);
                                                          uVar40 = 0x39a;
                                                        }
                                                        else {
                                                          *(undefined4 *)(ppppppcVar4 + 5) = 0x39a;
                                                          plVar28 = (longlong *)
                                                                    FUN_23e915840(lVar26,lVar34,
                                                                                  DAT_23eed8d40,
                                                                                  *(undefined8 *)
                                                                                   (lVar15 + 0x18));
                                                          if (plVar28 != (longlong *)0x0) {
                                                            *plVar28 = *plVar28 + -1;
                                                            if (*plVar28 == 0) {
                                                              FUN_23a334bc0(plVar28);
                                                            }
                                                            goto LAB_23e758917;
                                                          }
                                                          auStack_388 = *(undefined1 (*) [16])
                                                                         (lVar26 + 0x60);
                                                          pppppppcStack_378 =
                                                               *(code ********)(lVar26 + 0x70);
                                                          *(undefined8 *)(lVar26 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          uVar40 = 0x39a;
                                                        }
                                                        goto LAB_23e758dff;
                                                      }
                                                    }
                                                  }
                                                  auStack_388 = *(undefined1 (*) [16])
                                                                 (lVar26 + 0x60);
                                                  pppppppcStack_378 =
                                                       *(code ********)(lVar26 + 0x70);
                                                  *(undefined8 *)(lVar26 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  uVar40 = 0x395;
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar12 = FUN_23a35f020(pcVar43);
                                                    if (iVar12 == -1) goto LAB_23e75b2bb;
                                                    if (iVar12 != 0) {
                                                      iVar12 = PySequence_Contains(plVar17,plVar37);
                                                      if (iVar12 == -1) goto LAB_23e75b2bb;
                                                      if (iVar12 == 0) goto LAB_23e75a1db;
                                                    }
                                                    plVar28 = (longlong *)
                                                              FUN_23e8bc2f0(plVar13,DAT_23eed8b40);
                                                    plVar38 = DAT_23eed92b0;
                                                    if (plVar28 == (longlong *)0x0) {
LAB_23e75b41e:
                                                      auStack_388 = *(undefined1 (*) [16])
                                                                     (lVar26 + 0x60);
                                                      pppppppcStack_378 =
                                                           *(code ********)(lVar26 + 0x70);
                                                      uVar40 = 0x397;
                                                      *(undefined8 *)(lVar26 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      plVar31 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (lVar26 + 0x10),3);
                                                      *plVar38 = *plVar38 + 1;
                                                      plVar31[3] = (longlong)plVar38;
                                                      lVar15 = FUN_23e94f9d0(lVar26,plStack_3f0,
                                                                             DAT_23ed6cd28);
                                                      if (lVar15 == 0) {
                                                        auStack_388 = *(undefined1 (*) [16])
                                                                       (lVar26 + 0x60);
                                                        pppppppcStack_378 =
                                                             *(code ********)(lVar26 + 0x70);
                                                        *(undefined8 *)(lVar26 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar28 = *plVar28 + -1;
                                                        if (*plVar28 == 0) {
                                                          FUN_23a334bc0(plVar28);
                                                        }
                                                        *plVar31 = *plVar31 + -1;
                                                        if (*plVar31 == 0) {
                                                          FUN_23a334bc0(plVar31);
                                                        }
                                                        uVar40 = 0x397;
                                                      }
                                                      else {
                                                        plVar31[4] = lVar15;
                                                        plVar38 = DAT_23eed92c8;
                                                        *DAT_23eed92c8 = *DAT_23eed92c8 + 1;
                                                        plVar31[5] = (longlong)plVar38;
                                                        plVar38 = (longlong *)
                                                                  PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar31);
                                                        *plVar31 = *plVar31 + -1;
                                                        if (*plVar31 == 0) {
                                                          FUN_23a334bc0(plVar31);
                                                        }
                                                        if (plVar38 == (longlong *)0x0) {
                                                          auStack_388 = *(undefined1 (*) [16])
                                                                         (lVar26 + 0x60);
                                                          pppppppcStack_378 =
                                                               *(code ********)(lVar26 + 0x70);
                                                          uVar40 = 0x397;
                                                          uVar41 = 0x397;
                                                          *(undefined8 *)(lVar26 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar28 = *plVar28 + -1;
                                                          lVar15 = *plVar28;
                                                          goto joined_r0x00023e75b088;
                                                        }
                                                        *(undefined4 *)(ppppppcVar4 + 5) = 0x397;
                                                        plVar31 = (longlong *)
                                                                  FUN_23e914090(lVar26,plVar28);
                                                        *plVar28 = *plVar28 + -1;
                                                        if (*plVar28 == 0) {
                                                          FUN_23a334bc0(plVar28);
                                                        }
                                                        *plVar38 = *plVar38 + -1;
                                                        if (*plVar38 == 0) {
                                                          FUN_23a334bc0(plVar38);
                                                        }
                                                        if (plVar31 == (longlong *)0x0)
                                                        goto LAB_23e75b41e;
                                                        *plVar31 = *plVar31 + -1;
                                                        if (*plVar31 == 0) {
                                                          FUN_23a334bc0(plVar31);
                                                        }
                                                        plVar28 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar13,
                                                  DAT_23eed8a98);
                                                  if (plVar28 != (longlong *)0x0) {
                                                    plVar38 = (longlong *)
                                                              FUN_23e8bc2f0(plVar28,DAT_23eed92c0);
                                                    *plVar28 = *plVar28 + -1;
                                                    if (*plVar28 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar38 != (longlong *)0x0) {
                                                      *plStack_3e8 = *plStack_3e8 + 1;
                                                      plStack_398 = plVar38;
                                                      plStack_390 = plStack_3e8;
                                                      plVar28 = (longlong *)
                                                                FUN_23ab01810(lVar26,&plStack_398);
                                                      if (plVar28 != (longlong *)0x0)
                                                      goto LAB_23e75a40e;
                                                    }
                                                  }
                                                  auStack_388 = *(undefined1 (*) [16])
                                                                 (lVar26 + 0x60);
                                                  pppppppcStack_378 =
                                                       *(code ********)(lVar26 + 0x70);
                                                  uVar40 = 0x398;
                                                  *(undefined8 *)(lVar26 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_23e758dff;
                                                  }
                                                  }
                                                  auVar9 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                                  *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  pppppppcVar36 = *(code ********)(lVar26 + 0x70);
                                                  pppppppcStack_378 = (code *******)0x0;
                                                  lVar15 = *plStack_3c8;
                                                  *(undefined8 *)(lVar26 + 0x70) = 0;
                                                  auStack_388 = (undefined1  [16])0x0;
                                                  *plStack_3c8 = lVar15 + -1;
                                                  if (lVar15 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  uVar40 = 0x38d;
                                                  plStack_3e0 = (longlong *)0x0;
                                                  plStack_3c8 = (longlong *)0x0;
                                                  auStack_388 = auVar9;
                                                  pppppppcStack_378 = pppppppcVar36;
                                                  }
                                                  }
                                                  goto LAB_23e758dff;
                                                  }
                                                  }
                                                  pppppppcStack_378 =
                                                       *(code ********)(lVar26 + 0x70);
                                                  auStack_388 = *(undefined1 (*) [16])
                                                                 (lVar26 + 0x60);
                                                  *(undefined8 *)(lVar26 + 0x70) = 0;
                                                  lVar15 = *plVar38;
                                                  *(undefined1 (*) [16])(lVar26 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar38 = lVar15 + -1;
                                                  if (lVar15 + -1 == 0) {
                                                    FUN_23a334bc0(plVar38);
                                                  }
                                                  *plVar31 = *plVar31 + -1;
                                                  if (*plVar31 == 0) {
                                                    FUN_23a334bc0(plVar31);
                                                  }
                                                  uVar40 = 0x38a;
                                                  plStack_3e0 = (longlong *)0x0;
                                                  plStack_3c8 = (longlong *)0x0;
                                                  goto LAB_23e758dff;
                                                  }
                                                }
                                              }
                                              pppppppcVar36 = pppppppcStack_378;
                                              uVar45 = auStack_388._0_8_;
                                              uVar46 = auStack_388._8_8_;
                                              pppppppcStack_378 = (code *******)0x0;
                                              auStack_388 = (undefined1  [16])0x0;
                                              *plVar28 = *plVar28 + -1;
                                              if (*plVar28 == 0) {
                                                (**(code **)(plVar28[1] + 0x30))(plVar28);
                                              }
                                              pppppppcStack_378 = (code *******)0x0;
                                              auStack_388 = (undefined1  [16])0x0;
                                              if ((plVar37 != (longlong *)0x0) &&
                                                 (*plVar37 = *plVar37 + -1, *plVar37 == 0)) {
                                                (**(code **)(plVar37[1] + 0x30))(plVar37);
                                              }
                                              if ((plStack_3f0 != (longlong *)0x0) &&
                                                 (lVar15 = *plStack_3f0, *plStack_3f0 = lVar15 + -1,
                                                 lVar15 + -1 == 0)) {
                                                (**(code **)(plStack_3f0[1] + 0x30))();
                                              }
                                              if ((plStack_3d8 != (longlong *)0x0) &&
                                                 (lVar15 = *plStack_3d8, *plStack_3d8 = lVar15 + -1,
                                                 lVar15 + -1 == 0)) {
                                                (**(code **)(plStack_3d8[1] + 0x30))();
                                              }
                                            }
                                            uVar40 = 0x389;
                                            auStack_388._8_8_ = uVar46;
                                            auStack_388._0_8_ = uVar45;
                                            pppppppcStack_378 = pppppppcVar36;
                                            goto LAB_23e75a63c;
                                          }
                                          auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
                                          pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
                                          plStack_3e0 = (longlong *)0x0;
                                          plVar37 = (longlong *)0x0;
                                          *(undefined8 *)(lVar26 + 0x70) = 0;
                                          uVar40 = 0x388;
                                          plStack_3c8 = (longlong *)0x0;
                                          plStack_3d8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(lVar26 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_3f0 = (longlong *)0x0;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
LAB_23e758dff:
              if (pppppppcStack_378 == (code *******)0x0) {
LAB_23e758c00:
                pppppppcVar36 = DAT_23ed6a4f8;
                if (DAT_23ed6a4f8 == (code *******)0x0) {
                  pppppppcVar36 = (code *******)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  pppppppcVar14 = (code *******)*DAT_23ed6a4f8;
                  *DAT_23ed6a4f8 = (code ******)0x1;
                  DAT_23ed6a4f8 = pppppppcVar14;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                pcVar35 = _PyRuntime_exref;
                pppppppcVar36[2] = (code ******)0x0;
                pppppppcVar36[3] = ppppppcVar4;
                *ppppppcVar4 = (code *****)((longlong)*ppppppcVar4 + 1);
                lVar15 = *(longlong *)(pcVar35 + 0x1f8);
                *(undefined4 *)((longlong)pppppppcVar36 + 0x24) = uVar40;
                lVar15 = *(longlong *)(lVar15 + 0x10);
                *(undefined4 *)(pppppppcVar36 + 4) = 0xffffffff;
                ppppppcVar24 = *(code *******)(lVar15 + 0x2e8);
                ppppppcVar5 = pppppppcVar36[-1];
                pppppcVar44 = ppppppcVar24[1];
                *pppppcVar44 = (code ****)(pppppppcVar36 + -2);
                pppppppcVar36[-2] = ppppppcVar24;
                pppppppcVar36[-1] =
                     (code ******)((ulonglong)((uint)ppppppcVar5 & 3) | (ulonglong)pppppcVar44);
                ppppppcVar24[1] = (code *****)(pppppppcVar36 + -2);
                if ((pppppppcStack_378 != (code *******)0x0) &&
                   (*pppppppcStack_378 = (code ******)((longlong)*pppppppcStack_378 + -1),
                   *pppppppcStack_378 == (code ******)0x0)) {
                  (*(code *)pppppppcStack_378[1][6])(pppppppcStack_378);
                }
                goto LAB_23e758ecb;
              }
            }
            else {
              if (plVar25 != (longlong *)0x0) goto LAB_23e7583ea;
LAB_23e758b73:
              auStack_388 = *(undefined1 (*) [16])(lVar26 + 0x60);
              pppppppcStack_378 = *(code ********)(lVar26 + 0x70);
              plVar37 = (longlong *)0x0;
              plVar29 = (longlong *)0x0;
              *(undefined8 *)(lVar26 + 0x70) = 0;
              pcVar43 = (code *)0x0;
              plVar17 = (longlong *)0x0;
              uVar40 = 0x378;
              plStack_3e0 = (longlong *)0x0;
              plStack_3c8 = (longlong *)0x0;
              plStack_3d8 = (longlong *)0x0;
              plStack_3f0 = (longlong *)0x0;
              plStack_3d0 = (longlong *)0x0;
              plStack_3e8 = (longlong *)0x0;
              *(undefined1 (*) [16])(lVar26 + 0x60) = (undefined1  [16])0x0;
              if (pppppppcStack_378 == (code *******)0x0) {
                pppppppcStack_378 = (code *******)0x0;
                goto LAB_23e758c00;
              }
            }
            pppppppcVar36 = pppppppcStack_378;
            pppppppcVar14 = DAT_23ed6a4f8;
            if (pppppppcStack_378[3] != ppppppcVar4) {
              if (DAT_23ed6a4f8 == (code *******)0x0) {
                pppppppcVar14 = (code *******)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pppppppcVar39 = (code *******)*DAT_23ed6a4f8;
                *DAT_23ed6a4f8 = (code ******)0x1;
                DAT_23ed6a4f8 = pppppppcVar39;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar35 = _PyRuntime_exref;
              pppppppcVar14[3] = ppppppcVar4;
              *ppppppcVar4 = (code *****)((longlong)*ppppppcVar4 + 1);
              lVar15 = *(longlong *)(pcVar35 + 0x1f8);
              *(undefined4 *)((longlong)pppppppcVar14 + 0x24) = uVar40;
              *(undefined4 *)(pppppppcVar14 + 4) = 0xffffffff;
              ppppppcVar24 = *(code *******)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
              ppppppcVar5 = pppppppcVar14[-1];
              pppppcVar44 = ppppppcVar24[1];
              *pppppcVar44 = (code ****)(pppppppcVar14 + -2);
              pppppppcVar14[-2] = ppppppcVar24;
              pppppppcVar14[-1] =
                   (code ******)((ulonglong)((uint)ppppppcVar5 & 3) | (ulonglong)pppppcVar44);
              ppppppcVar24[1] = (code *****)(pppppppcVar14 + -2);
              pppppppcVar14[2] = (code ******)pppppppcVar36;
              *pppppppcVar36 = (code ******)((longlong)*pppppppcVar36 + 1);
              pppppppcVar36 = pppppppcVar14;
              if ((pppppppcStack_378 != (code *******)0x0) &&
                 (*pppppppcStack_378 = (code ******)((longlong)*pppppppcStack_378 + -1),
                 *pppppppcStack_378 == (code ******)0x0)) {
                (*(code *)pppppppcStack_378[1][6])(pppppppcStack_378);
              }
            }
LAB_23e758ecb:
            pppppppcStack_378 = pppppppcVar36;
            FUN_23e8bba40(ppppppcVar4,"oooooooooooo",plVar13,plVar17,plVar25,pcVar43,plStack_3e8,
                          plStack_3d0,plVar29,plVar37,plStack_3f0,plStack_3d8,plStack_3c8,
                          plStack_3e0);
            if (DAT_23eedade8 == ppppppcVar4) {
              *ppppppcVar4 = (code *****)((longlong)*ppppppcVar4 + -1);
              if (*ppppppcVar4 == (code *****)0x0) {
                (*(code *)ppppppcVar4[1][6])(ppppppcVar4);
              }
              DAT_23eedade8 = (code ******)0x0;
            }
            lVar15 = *(longlong *)(*(longlong *)(lVar26 + 0x38) + 8);
            plVar28 = *(longlong **)(lVar15 + 0x28);
            plVar38 = (longlong *)plVar28[2];
            *(undefined8 *)(*(longlong *)(lVar26 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
            *(undefined4 *)(plVar28 + 8) = 0xffffffff;
            if (plVar38 != (longlong *)0x0) {
              plVar28[2] = 0;
              *plVar38 = *plVar38 + -1;
              if (*plVar38 == 0) {
                (**(code **)(plVar38[1] + 0x30))();
              }
            }
            *plVar28 = *plVar28 + -1;
            if (*plVar28 == 0) {
              (**(code **)(plVar28[1] + 0x30))(plVar28);
            }
            pppppppcVar36 = pppppppcStack_378;
            plVar28[0xf] = 0;
            uVar45 = auStack_388._0_8_;
            uVar46 = auStack_388._8_8_;
            auStack_388 = (undefined1  [16])0x0;
            pppppppcStack_378 = (code *******)0x0;
            if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
            if ((plVar25 != (longlong *)0x0) && (*plVar25 = *plVar25 + -1, *plVar25 == 0)) {
              (**(code **)(plVar25[1] + 0x30))(plVar25);
            }
            if ((pcVar43 != (code *)0x0) &&
               (*(longlong *)pcVar43 = *(longlong *)pcVar43 + -1, *(longlong *)pcVar43 == 0)) {
              (**(code **)(*(longlong *)(pcVar43 + 8) + 0x30))(pcVar43);
            }
            if ((plStack_3e8 != (longlong *)0x0) &&
               (lVar15 = *plStack_3e8, *plStack_3e8 = lVar15 + -1, lVar15 + -1 == 0)) {
              (**(code **)(plStack_3e8[1] + 0x30))(plStack_3e8);
            }
            if ((plStack_3d0 != (longlong *)0x0) &&
               (lVar15 = *plStack_3d0, *plStack_3d0 = lVar15 + -1, lVar15 + -1 == 0)) {
              (**(code **)(plStack_3d0[1] + 0x30))(plStack_3d0);
            }
            if ((plVar29 != (longlong *)0x0) && (*plVar29 = *plVar29 + -1, *plVar29 == 0)) {
              (**(code **)(plVar29[1] + 0x30))(plVar29);
            }
            if ((plVar37 != (longlong *)0x0) && (*plVar37 = *plVar37 + -1, *plVar37 == 0)) {
              (**(code **)(plVar37[1] + 0x30))(plVar37);
            }
            if ((plStack_3f0 != (longlong *)0x0) &&
               (lVar15 = *plStack_3f0, *plStack_3f0 = lVar15 + -1, lVar15 + -1 == 0)) {
              (**(code **)(plStack_3f0[1] + 0x30))(plStack_3f0);
            }
            if ((plStack_3d8 != (longlong *)0x0) &&
               (lVar15 = *plStack_3d8, *plStack_3d8 = lVar15 + -1, lVar15 + -1 == 0)) {
              (**(code **)(plStack_3d8[1] + 0x30))(plStack_3d8);
            }
            if ((plStack_3c8 != (longlong *)0x0) &&
               (lVar15 = *plStack_3c8, *plStack_3c8 = lVar15 + -1, lVar15 + -1 == 0)) {
              (**(code **)(plStack_3c8[1] + 0x30))(plStack_3c8);
            }
            if ((plStack_3e0 != (longlong *)0x0) &&
               (lVar15 = *plStack_3e0, *plStack_3e0 = lVar15 + -1, lVar15 + -1 == 0)) {
              (**(code **)(plStack_3e0[1] + 0x30))(plStack_3e0);
            }
            *plVar13 = *plVar13 + -1;
            pppppppcStack_378 = pppppppcVar36;
            auStack_388._0_8_ = uVar45;
            auStack_388._8_8_ = uVar46;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            FUN_23a33aa70(lVar26,auStack_388._0_8_,auStack_388._8_8_,pppppppcStack_378);
            return (code *******)0x0;
          }
          *plVar31 = *plVar31 + 1;
          DAT_23ed6a4c0 = plVar31;
        }
        plStack_1b0 = plVar38;
        plStack_1a8 = plVar29;
        pppppppcStack_318 = (code *******)0x23e757ead;
        lVar26 = FUN_23e94ed00(lVar15,DAT_23ed6a4c0,pplStack_1e0);
        if (lVar26 == 0) {
          auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
          auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
          apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
          *(undefined8 *)(lVar15 + 0x70) = 0;
          *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
          *plVar37 = *plVar37 + -1;
          if (*plVar37 == 0) {
            pppppppcStack_318 = (code *******)0x23e758212;
            FUN_23a334bc0(plVar37);
          }
          *plVar28 = *plVar28 + -1;
          if (*plVar28 == 0) {
            pppppppcStack_318 = (code *******)0x23e758221;
            FUN_23a334bc0(plVar28);
          }
        }
        else {
          plVar28[4] = lVar26;
          plVar29 = _DAT_23eed9170;
          *_DAT_23eed9170 = *_DAT_23eed9170 + 1;
          plVar28[5] = (longlong)plVar29;
          pppppppcStack_318 = (code *******)0x23e757edf;
          plVar29 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar28);
          *plVar28 = *plVar28 + -1;
          if (*plVar28 == 0) {
            pppppppcStack_318 = (code *******)0x23e757ef9;
            plStack_278 = plVar29;
            FUN_23a334bc0(plVar28);
            plVar29 = plStack_278;
          }
          if (plVar29 != (longlong *)0x0) {
            *(undefined4 *)(ppppppcVar4 + 5) = 0x371;
            pppppppcStack_318 = (code *******)0x23e757f24;
            plStack_278 = plVar29;
            plVar29 = (longlong *)FUN_23e914090(lVar15,plVar37);
            *plVar37 = *plVar37 + -1;
            if (*plVar37 == 0) {
              pppppppcStack_318 = (code *******)0x23e757f3e;
              FUN_23a334bc0(plVar37);
            }
            *plStack_278 = *plStack_278 + -1;
            if (*plStack_278 == 0) {
              pppppppcStack_318 = (code *******)0x23e757f54;
              FUN_23a334bc0(plStack_278);
            }
            if (plVar29 != (longlong *)0x0) {
              *plVar29 = *plVar29 + -1;
              if (*plVar29 == 0) {
                pppppppcStack_318 = (code *******)0x23e757f6c;
                FUN_23a334bc0(plVar29);
              }
              plStack_270 = plStack_218;
              plStack_248 = plStack_220;
              plStack_260 = plStack_228;
              plStack_250 = plStack_200;
              plStack_268 = plStack_210;
              plStack_278 = plStack_1f0;
              pcVar43 = pcStack_280;
              plVar29 = plStack_1d8;
LAB_23e7578e2:
              plVar38 = plStack_208;
              lVar26 = *(longlong *)(*(longlong *)(lVar15 + 0x38) + 8);
              plVar37 = *(longlong **)(lVar26 + 0x28);
              *(undefined8 *)(*(longlong *)(lVar15 + 0x38) + 8) = *(undefined8 *)(lVar26 + 0x30);
              plVar28 = (longlong *)plVar37[2];
              *(undefined4 *)(plVar37 + 8) = 0xffffffff;
              pcStack_280 = pcVar43;
              if (plVar28 != (longlong *)0x0) {
                plVar37[2] = 0;
                *plVar28 = *plVar28 + -1;
                if (*plVar28 == 0) {
                  pppppppcStack_318 = (code *******)0x23e757923;
                  (**(code **)(plVar28[1] + 0x30))();
                }
              }
              *plVar37 = *plVar37 + -1;
              if (*plVar37 == 0) {
                pppppppcStack_318 = (code *******)0x23e757943;
                (**(code **)(plVar37[1] + 0x30))(plVar37);
              }
              plVar37[0xf] = 0;
              *pppppppcStack_238 = (code ******)((longlong)*pppppppcStack_238 + 1);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                pppppppcStack_318 = (code *******)0x23e757c04;
                (**(code **)(plVar13[1] + 0x30))(plVar13);
                *plVar17 = *plVar17 + -1;
                lVar15 = *plVar17;
              }
              else {
                *plVar17 = *plVar17 + -1;
                lVar15 = *plVar17;
              }
              if (lVar15 == 0) {
                pppppppcStack_318 = (code *******)0x23e757982;
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              lVar15 = *plStack_258;
              *plStack_258 = lVar15 + -1;
              if (lVar15 + -1 == 0) {
                pppppppcStack_318 = (code *******)0x23e7579bb;
                (**(code **)(plStack_258[1] + 0x30))(plStack_258);
              }
              *plVar25 = *plVar25 + -1;
              if (*plVar25 == 0) {
                pppppppcStack_318 = (code *******)0x23e7579db;
                (**(code **)(plVar25[1] + 0x30))(plVar25);
              }
              pcVar35 = (code *)*plStack_240;
              pcVar43 = pcVar35 + -1;
              *plStack_240 = (longlong)pcVar43;
              pcVar42 = pcStack_280;
              if (pcVar43 == (code *)0x0) {
                pppppppcStack_318 = (code *******)0x23e757a11;
                (**(code **)(plStack_240[1] + 0x30))();
                pcVar42 = pcStack_280;
                pcVar35 = pcStack_280;
              }
              pcStack_280 = pcVar35;
              if ((pcVar42 != (code *)0x0) &&
                 (*(longlong *)pcVar42 = *(longlong *)pcVar42 + -1, *(longlong *)pcVar42 == 0)) {
                pppppppcStack_318 = (code *******)0x23e757a2e;
                (**(code **)(*(longlong *)(pcVar42 + 8) + 0x30))(pcVar42);
              }
              if ((plVar29 != (longlong *)0x0) && (*plVar29 = *plVar29 + -1, *plVar29 == 0)) {
                pppppppcStack_318 = (code *******)0x23e757a44;
                (**(code **)(plVar29[1] + 0x30))(plVar29);
              }
              if (plStack_278 != (longlong *)0x0) {
                pcStack_280 = (code *)*plStack_278;
                *plStack_278 = (longlong)(pcStack_280 + -1);
                if (pcStack_280 + -1 == (code *)0x0) {
                  pppppppcStack_318 = (code *******)0x23e757a75;
                  (**(code **)(plStack_278[1] + 0x30))(plStack_278);
                }
              }
              if (plStack_268 != (longlong *)0x0) {
                pcStack_280 = (code *)*plStack_268;
                *plStack_268 = (longlong)(pcStack_280 + -1);
                if (pcStack_280 + -1 == (code *)0x0) {
                  pppppppcStack_318 = (code *******)0x23e757aa3;
                  (**(code **)(plStack_268[1] + 0x30))();
                }
              }
              if (plStack_250 != (longlong *)0x0) {
                pcStack_280 = (code *)*plStack_250;
                *plStack_250 = (longlong)(pcStack_280 + -1);
                if (pcStack_280 + -1 == (code *)0x0) {
                  pppppppcStack_318 = (code *******)0x23e757ace;
                  (**(code **)(plStack_250[1] + 0x30))(plStack_250);
                }
              }
              if ((plVar38 != (longlong *)0x0) && (*plVar38 = *plVar38 + -1, *plVar38 == 0)) {
                pppppppcStack_318 = (code *******)0x23e757ae5;
                (**(code **)(plVar38[1] + 0x30))(plVar38);
              }
              if (plStack_260 != (longlong *)0x0) {
                pcStack_280 = (code *)*plStack_260;
                *plStack_260 = (longlong)(pcStack_280 + -1);
                if (pcStack_280 + -1 == (code *)0x0) {
                  pppppppcStack_318 = (code *******)0x23e757b10;
                  (**(code **)(plStack_260[1] + 0x30))(plStack_260);
                }
              }
              if (plStack_248 != (longlong *)0x0) {
                pcStack_280 = (code *)*plStack_248;
                *plStack_248 = (longlong)(pcStack_280 + -1);
                if (pcStack_280 + -1 == (code *)0x0) {
                  pppppppcStack_318 = (code *******)0x23e757b3b;
                  (**(code **)(plStack_248[1] + 0x30))(plStack_248);
                }
              }
              if (plStack_270 != (longlong *)0x0) {
                pcStack_280 = (code *)*plStack_270;
                *plStack_270 = (longlong)(pcStack_280 + -1);
                if (pcStack_280 + -1 == (code *)0x0) {
                  pppppppcStack_318 = (code *******)0x23e757b6e;
                  (**(code **)(plStack_270[1] + 0x30))(plStack_270);
                }
              }
LAB_23e754e8e:
              *pppppppcVar22 = (code ******)((longlong)*pppppppcVar22 + -1);
              if (*pppppppcVar22 == (code ******)0x0) {
                pppppppcStack_318 = (code *******)0x23e755a3a;
                (*(code *)pppppppcVar22[1][6])(pppppppcVar22);
                return pppppppcStack_238;
              }
              return pppppppcStack_238;
            }
            goto LAB_23e758138;
          }
          auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
          auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
          apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
          *(undefined8 *)(lVar15 + 0x70) = 0;
          *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
          *plVar37 = *plVar37 + -1;
          if (*plVar37 == 0) {
            pppppppcStack_318 = (code *******)0x23e75829b;
            FUN_23a334bc0(plVar37);
          }
        }
      }
      uVar40 = 0x371;
      plStack_270 = plStack_218;
      plStack_248 = plStack_220;
      plStack_260 = plStack_228;
      plStack_250 = plStack_200;
      plStack_268 = plStack_210;
      plStack_278 = plStack_1f0;
      plVar37 = plStack_208;
      plVar29 = plStack_1d8;
      goto LAB_23e755c16;
    }
    pppppppcStack_318 = (code *******)0x23e755914;
    lVar34 = FUN_23e8e0ba0();
    plVar17 = plStack_1e8;
    plVar13 = plStack_1f0;
    plVar25 = plStack_1f8;
    pppppppcVar22 = pppppppcStack_230;
    lVar26 = _DAT_23eed9178;
    if (lVar34 == 0) {
      pppppppcStack_318 = (code *******)0x23e7573bb;
      plStack_210 = plVar31;
      plStack_1f0 = plVar30;
      plStack_1d8 = plVar29;
      FUN_23e915740(lVar15,plStack_200,DAT_23eed8c70);
LAB_23e7573f6:
      uVar40 = 0x374;
      plStack_268 = plStack_210;
      plStack_278 = plStack_1f0;
      plVar29 = plStack_1d8;
      plStack_270 = plStack_218;
      plStack_260 = plStack_228;
      plStack_250 = plVar32;
      plStack_248 = plStack_220;
      goto LAB_23e755c16;
    }
    *(undefined4 *)(ppppppcVar4 + 5) = 0x374;
    pppppppcStack_318 = (code *******)0x23e755942;
    plVar13 = (longlong *)FUN_23e915840(lVar15,lVar34,DAT_23eed8d40,*(undefined8 *)(lVar26 + 0x18));
    if (plVar13 == (longlong *)0x0) {
      auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
      auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
      apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
      *(undefined8 *)(lVar15 + 0x70) = 0;
      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
      plVar17 = plStack_1e8;
      plVar13 = plStack_1f0;
      plVar25 = plStack_1f8;
      pppppppcVar22 = pppppppcStack_230;
      plStack_210 = plVar31;
      plStack_208 = plVar33;
      plStack_200 = plVar32;
      plStack_1f0 = plVar30;
      plStack_1d8 = plVar29;
      goto LAB_23e7573f6;
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      pppppppcStack_318 = (code *******)0x23e7564c7;
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    lVar26 = *(longlong *)(lVar15 + 0x10);
    if ((*(int *)(*(longlong *)(lVar26 + 0x28) + 0x160) != 0) || (*(int *)(lVar26 + 0x78) != 0)) {
      pppppppcStack_318 = (code *******)0x23e756086;
      iVar12 = Py_MakePendingCalls();
      if ((-1 < iVar12) ||
         (plVar17 = plStack_1e8, plVar13 = plStack_1f0, plVar25 = plStack_1f8,
         pppppppcVar22 = pppppppcStack_230, *(longlong *)(lVar15 + 0x60) == 0)) goto LAB_23e75597a;
LAB_23e7560f0:
      plStack_1d8 = plVar29;
      plStack_1f0 = plVar30;
      plStack_200 = plVar32;
      plStack_208 = plVar33;
      plStack_210 = plVar31;
      auStack_1d0._0_8_ = *(undefined8 *)(lVar15 + 0x60);
      plStack_270 = plStack_218;
      uVar40 = 0x369;
      apppppppcStack_1c0[0] = *(code ********)(lVar15 + 0x70);
      *(undefined8 *)(lVar15 + 0x70) = 0;
      plStack_248 = plStack_220;
      plStack_260 = plStack_228;
      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
      plVar37 = plStack_208;
      plVar29 = plStack_1d8;
      plStack_278 = plStack_1f0;
      plStack_268 = plStack_210;
      plStack_250 = plStack_200;
      auStack_1d0._8_8_ = *(undefined8 *)(lVar15 + 0x68);
      goto LAB_23e755c16;
    }
LAB_23e75597a:
    if (*(int *)(lVar26 + 0x68) != 0) {
      pppppppcStack_318 = (code *******)0x23e75673e;
      PyEval_SaveThread();
      pppppppcStack_318 = (code *******)0x23e756747;
      PyEval_AcquireThread(lVar15);
    }
    plVar17 = plStack_1e8;
    plVar13 = plStack_1f0;
    plVar25 = plStack_1f8;
    pppppppcVar22 = pppppppcStack_230;
    plVar37 = *(longlong **)(lVar15 + 0x90);
    if (plVar37 != (longlong *)0x0) {
      plVar28 = *(longlong **)(lVar15 + 0x60);
      plVar38 = *(longlong **)(lVar15 + 0x68);
      plVar7 = *(longlong **)(lVar15 + 0x70);
      *(longlong **)(lVar15 + 0x60) = plVar37;
      *(undefined8 *)(lVar15 + 0x90) = 0;
      *plVar37 = *plVar37 + 1;
      *(undefined8 *)(lVar15 + 0x68) = 0;
      *(undefined8 *)(lVar15 + 0x70) = 0;
      plStack_210 = plVar31;
      plStack_208 = plVar33;
      plStack_200 = plVar32;
      plStack_1f0 = plVar30;
      plStack_1d8 = plVar29;
      if ((plVar28 != (longlong *)0x0) && (*plVar28 = *plVar28 + -1, *plVar28 == 0)) {
        pppppppcStack_318 = (code *******)0x23e757558;
        (**(code **)(plVar28[1] + 0x30))();
      }
      if ((plVar38 != (longlong *)0x0) && (*plVar38 = *plVar38 + -1, *plVar38 == 0)) {
        pppppppcStack_318 = (code *******)0x23e75756e;
        (**(code **)(plVar38[1] + 0x30))(plVar38);
      }
      plVar31 = plStack_210;
      plVar33 = plStack_208;
      plVar32 = plStack_200;
      plVar30 = plStack_1f0;
      plVar29 = plStack_1d8;
      if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
        pppppppcStack_318 = (code *******)0x23e75758d;
        (**(code **)(plVar7[1] + 0x30))(plVar7);
        plVar31 = plStack_210;
        plVar33 = plStack_208;
        plVar32 = plStack_200;
        plVar30 = plStack_1f0;
        plVar29 = plStack_1d8;
      }
      goto LAB_23e7560f0;
    }
    plStack_270 = plStack_218;
    plStack_248 = plStack_220;
    plStack_260 = plStack_228;
    pcVar43 = pcStack_280;
    plStack_278 = plVar30;
    plStack_268 = plVar31;
    plStack_250 = plVar32;
    plStack_210 = plVar29;
    plStack_208 = plVar33;
  }
  goto LAB_23e755363;
}
