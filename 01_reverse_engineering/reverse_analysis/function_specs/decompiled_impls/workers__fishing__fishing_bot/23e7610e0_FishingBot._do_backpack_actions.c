/* ===== 23e7610e0 workers.fishing.fishing_bot:FishingBot._do_backpack_actions ===== */
/* ghidra_name=FUN_23e7610e0 entry=23e7610e0 size=15534 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7610e0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  code *pcVar21;
  code *pcVar22;
  undefined4 uVar23;
  undefined8 uVar24;
  longlong *local_150;
  longlong *local_148;
  code *local_140;
  longlong *local_138;
  longlong *local_130;
  longlong *local_128;
  int local_120;
  longlong *local_118;
  code *local_110;
  undefined1 local_f8 [16];
  code *local_e8 [2];
  undefined1 local_d8 [16];
  code *local_c8 [2];
  longlong *local_b8;
  undefined8 uStack_b0;
  code *local_a8;
  undefined8 local_a0;
  longlong *local_98;
  longlong *local_88;
  undefined8 uStack_80;
  code *local_78;
  undefined8 local_70;
  longlong *local_68;
  
  plVar10 = _DAT_23eedadb0;
  plVar1 = (longlong *)*param_3;
  local_c8[0] = (code *)0x0;
  local_d8._0_8_ = (code *)0x0;
  local_d8._8_8_ = 0;
  if (_DAT_23eedadb0 == (longlong *)0x0) {
LAB_23e76113d:
    _DAT_23eedadb0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedafb8,DAT_23eedaeb8,100);
  }
  else {
    lVar12 = *_DAT_23eedadb0;
    if (1 < lVar12) {
      *_DAT_23eedadb0 = lVar12 + -1;
      goto LAB_23e76113d;
    }
    if (_DAT_23eedadb0[2] != 0) {
      *_DAT_23eedadb0 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e76113d;
    }
  }
  plVar3 = _DAT_23eedadb0;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedadb0 + 9;
  lVar2 = *(longlong *)(lVar12 + 8);
  _DAT_23eedadb0[0xf] = lVar2;
  *(longlong **)(lVar12 + 8) = plVar10;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar24 = DAT_23eed89b0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar24);
  if (plVar10 == (longlong *)0x0) {
    local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
    local_c8[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_c8[0] == (code *)0x0) {
LAB_23e761f30:
      local_148 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      local_150 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      local_120 = 2;
      iVar9 = 0x430;
      local_130 = (longlong *)0x0;
      local_138 = (longlong *)0x0;
      local_140 = (code *)0x0;
      local_128 = (longlong *)0x0;
      goto LAB_23e761f8d;
    }
    if (*(longlong **)(local_c8[0] + 0x18) != plVar3) {
      local_148 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      local_150 = (longlong *)0x0;
      local_120 = 2;
      iVar9 = 0x430;
      local_130 = (longlong *)0x0;
      local_138 = (longlong *)0x0;
      local_140 = (code *)0x0;
      local_128 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      goto LAB_23e761a50;
    }
LAB_23e761e00:
    local_148 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    local_150 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    local_120 = 2;
    local_130 = (longlong *)0x0;
    local_138 = (longlong *)0x0;
    local_140 = (code *)0x0;
    local_128 = (longlong *)0x0;
    pcVar14 = local_c8[0];
    goto LAB_23e761b15;
  }
  *(undefined4 *)(plVar3 + 5) = 0x430;
  plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8d38);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (plVar11 == (longlong *)0x0) {
    local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
    local_c8[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_c8[0] == (code *)0x0) goto LAB_23e761f30;
    if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e761e00;
    local_148 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    local_150 = (longlong *)0x0;
    local_120 = 2;
    iVar9 = 0x430;
    local_130 = (longlong *)0x0;
    local_138 = (longlong *)0x0;
    local_140 = (code *)0x0;
    local_128 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
  }
  else {
    iVar9 = FUN_23a35f020(plVar11);
    lVar12 = *plVar11 + -1;
    if (iVar9 != -1) {
      *plVar11 = lVar12;
      if (lVar12 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (iVar9 != 0) {
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        local_128 = (longlong *)0x0;
        lVar12 = *(longlong *)_Py_NoneStruct_exref;
        pcVar14 = _Py_NoneStruct_exref;
LAB_23e76126c:
        *(longlong *)pcVar14 = lVar12 + 1;
        lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar3 = *(longlong **)(lVar12 + 0x28);
        plVar13 = (longlong *)plVar3[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
        if (plVar13 != (longlong *)0x0) {
          plVar3[2] = 0;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
        }
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
        }
        plVar3[0xf] = 0;
        if (plVar10 == (longlong *)0x0) {
          if (plVar11 == (longlong *)0x0) {
            if ((local_128 != (longlong *)0x0) &&
               (lVar12 = *local_128, *local_128 = lVar12 + -1, lVar12 + -1 == 0)) {
              (**(code **)(local_128[1] + 0x30))(local_128);
            }
            goto LAB_23e76143c;
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            local_148 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            local_150 = (longlong *)0x0;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
            goto LAB_23e7619a5;
          }
          if ((local_128 == (longlong *)0x0) ||
             (lVar12 = *local_128, *local_128 = lVar12 + -1, lVar12 + -1 != 0)) goto LAB_23e76143c;
          plVar15 = (longlong *)0x0;
          (**(code **)(local_128[1] + 0x30))(local_128);
          local_148 = (longlong *)0x0;
          local_150 = (longlong *)0x0;
        }
        else {
          local_148 = (longlong *)0x0;
          plVar15 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          local_150 = (longlong *)0x0;
          local_130 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          local_140 = (code *)0x0;
LAB_23e761308:
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
LAB_23e7619a5:
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if ((local_128 != (longlong *)0x0) &&
             (lVar12 = *local_128, *local_128 = lVar12 + -1, lVar12 + -1 == 0)) {
            (**(code **)(local_128[1] + 0x30))(local_128);
          }
          if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if ((local_140 != (code *)0x0) &&
             (lVar12 = *(longlong *)local_140, *(longlong *)local_140 = lVar12 + -1,
             lVar12 + -1 == 0)) {
            (**(code **)(*(longlong *)(local_140 + 8) + 0x30))(local_140);
          }
          if ((local_138 != (longlong *)0x0) &&
             (lVar12 = *local_138, *local_138 = lVar12 + -1, lVar12 + -1 == 0)) {
            (**(code **)(local_138[1] + 0x30))(local_138);
          }
          if ((local_130 != (longlong *)0x0) &&
             (lVar12 = *local_130, *local_130 = lVar12 + -1, lVar12 + -1 == 0)) {
            (**(code **)(local_130[1] + 0x30))(local_130);
          }
        }
        if ((local_150 != (longlong *)0x0) &&
           (lVar12 = *local_150, *local_150 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_150[1] + 0x30))(local_150);
        }
        if ((local_148 != (longlong *)0x0) &&
           (lVar12 = *local_148, *local_148 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_148[1] + 0x30))(local_148);
        }
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
LAB_23e76143c:
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar14;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar14;
      }
      lVar12 = FUN_23e8dfe80();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,local_d8,DAT_23eed9460);
        plVar10 = (longlong *)0x0;
joined_r0x00023e7620e2:
        if (local_c8[0] != (code *)0x0) {
          if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e761e00;
          local_148 = (longlong *)0x0;
          plVar15 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          local_150 = (longlong *)0x0;
          local_120 = 2;
          iVar9 = 0x434;
          local_130 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          local_140 = (code *)0x0;
          local_128 = (longlong *)0x0;
          goto LAB_23e761a50;
        }
        local_148 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar15 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        local_120 = 2;
        iVar9 = 0x434;
        local_130 = (longlong *)0x0;
        local_138 = (longlong *)0x0;
        local_140 = (code *)0x0;
        local_128 = (longlong *)0x0;
        local_c8[0] = (code *)0x0;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0x434;
        plVar10 = (longlong *)FUN_23e91a870(param_1,lVar12);
        if (plVar10 == (longlong *)0x0) {
          local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_c8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto joined_r0x00023e7620e2;
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
        if (plVar11 == (longlong *)0x0) {
          local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_c8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] == (code *)0x0) goto LAB_23e762990;
          if (*(longlong **)(local_c8[0] + 0x18) != plVar3) {
            local_148 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            local_120 = 2;
            local_150 = (longlong *)0x0;
            iVar9 = 0x437;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
            local_128 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            goto LAB_23e761a50;
          }
LAB_23e762520:
          local_148 = (longlong *)0x0;
          plVar15 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          local_120 = 2;
          local_150 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          local_130 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          local_140 = (code *)0x0;
          local_128 = (longlong *)0x0;
          pcVar14 = local_c8[0];
          goto LAB_23e761b15;
        }
        cVar8 = FUN_23e8d9ac0(plVar10,DAT_23eed8a98,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (cVar8 == '\0') {
          local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_c8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] != (code *)0x0) {
            if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e762520;
            local_148 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            local_120 = 2;
            local_150 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            iVar9 = 0x437;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
            local_128 = (longlong *)0x0;
            goto LAB_23e761a50;
          }
LAB_23e762990:
          local_148 = (longlong *)0x0;
          plVar15 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          local_120 = 2;
          local_150 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          iVar9 = 0x437;
          local_130 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          local_140 = (code *)0x0;
          local_128 = (longlong *)0x0;
          goto LAB_23e761f8d;
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
        if (plVar11 == (longlong *)0x0) {
          local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_c8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] != (code *)0x0) {
            if (plVar3 == *(longlong **)(local_c8[0] + 0x18)) goto LAB_23e762520;
            local_148 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            local_120 = 2;
            local_150 = (longlong *)0x0;
            iVar9 = 0x438;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
            local_128 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            goto LAB_23e761a50;
          }
LAB_23e762b4b:
          local_148 = (longlong *)0x0;
          plVar15 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          local_120 = 2;
          local_150 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          iVar9 = 0x438;
          local_130 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          local_140 = (code *)0x0;
          local_128 = (longlong *)0x0;
          goto LAB_23e761f8d;
        }
        iVar9 = FUN_23e913250(plVar11,DAT_23eed90d8);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (iVar9 == -1) {
          local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_c8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] == (code *)0x0) goto LAB_23e762b4b;
          plVar11 = *(longlong **)(local_c8[0] + 0x18);
joined_r0x00023e76251a:
          if (plVar11 != plVar3) {
            local_148 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            local_120 = 2;
            local_150 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            iVar9 = 0x438;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
            local_128 = (longlong *)0x0;
            goto LAB_23e761a50;
          }
          goto LAB_23e762520;
        }
        cVar8 = FUN_23e8d9ac0(plVar10,DAT_23eed9390);
        if (cVar8 == '\0') {
          local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_c8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] == (code *)0x0) goto LAB_23e762b4b;
          plVar11 = *(longlong **)(local_c8[0] + 0x18);
          goto joined_r0x00023e76251a;
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
        if (plVar11 == (longlong *)0x0) {
          local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_c8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] == (code *)0x0) {
LAB_23e763bed:
            plVar15 = (longlong *)0x0;
            local_120 = 2;
            local_148 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            iVar9 = 0x43b;
            local_150 = (longlong *)0x0;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
            local_128 = (longlong *)0x0;
            goto LAB_23e761f8d;
          }
          if (plVar3 == *(longlong **)(local_c8[0] + 0x18)) goto LAB_23e762520;
          local_148 = (longlong *)0x0;
          plVar15 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          local_120 = 2;
          local_150 = (longlong *)0x0;
          iVar9 = 0x43b;
          local_130 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          local_140 = (code *)0x0;
          local_128 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          goto LAB_23e761a50;
        }
        iVar9 = FUN_23e913250(plVar11,DAT_23eed90d8);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))();
        }
        pcVar14 = _Py_NoneStruct_exref;
        uVar6 = DAT_23eed9498;
        uVar5 = DAT_23eed9470;
        plVar15 = DAT_23eed9468;
        uVar24 = DAT_23eed8950;
        plVar13 = DAT_23ed6ccf0;
        plVar11 = DAT_23ed6a498;
        if (iVar9 == -1) {
          local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_c8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] == (code *)0x0) goto LAB_23e763bed;
          if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e762520;
          local_148 = (longlong *)0x0;
          plVar15 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          local_120 = 2;
          local_150 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          iVar9 = 0x43b;
          local_130 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          local_140 = (code *)0x0;
          local_128 = (longlong *)0x0;
          goto LAB_23e761a50;
        }
        if (iVar9 == 1) {
          *(undefined4 *)(plVar3 + 5) = 0x43c;
          local_98 = plVar13;
          local_a8 = pcVar14;
          local_a0 = uVar5;
          local_b8 = plVar15;
          uStack_b0 = uVar24;
          if (plVar11 != (longlong *)0x0) {
LAB_23e7627b6:
            plVar13 = (longlong *)FUN_23e95b390(param_1,plVar11,&local_b8);
            if (plVar13 != (longlong *)0x0) {
              if (((code *)plVar13[1] == PyModule_Type_exref) ||
                 (iVar9 = PyType_IsSubtype(), uVar24 = DAT_23eed9478, iVar9 != 0)) {
                uVar5 = DAT_23eed9478;
                uVar24 = DAT_23eed8950;
                plVar15 = DAT_23ed6ccf0;
                plVar11 = (longlong *)PyObject_GetAttr(plVar13,DAT_23eed9478);
                if (plVar11 == (longlong *)0x0) {
                  plVar11 = (longlong *)FUN_23e970390(param_1,plVar13,uVar24,uVar5,plVar15);
                  goto LAB_23e763ac6;
                }
                lVar12 = *plVar13;
                *plVar13 = lVar12 + -1;
                if (lVar12 + -1 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
              }
              else {
                plVar11 = (longlong *)PyObject_GetAttr(plVar13,DAT_23eed9478);
                if (plVar11 == (longlong *)0x0) {
                  plVar11 = (longlong *)FUN_23e8d2cf0(param_1,plVar13,uVar24);
LAB_23e763ac6:
                  lVar12 = *plVar13;
                  *plVar13 = lVar12 + -1;
                  if (lVar12 + -1 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  if (plVar11 == (longlong *)0x0) {
                    local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    local_c8[0] = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (local_c8[0] != (code *)0x0) {
                      if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e762520;
                      plVar15 = (longlong *)0x0;
                      plVar13 = (longlong *)0x0;
                      local_148 = (longlong *)0x0;
                      local_120 = 2;
                      local_150 = (longlong *)0x0;
                      local_130 = (longlong *)0x0;
                      local_138 = (longlong *)0x0;
                      local_140 = (code *)0x0;
                      iVar9 = 0x43c;
                      local_128 = (longlong *)0x0;
                      goto LAB_23e761a50;
                    }
                    goto LAB_23e7641ec;
                  }
                }
                else {
                  lVar12 = *plVar13;
                  *plVar13 = lVar12 + -1;
                  if (lVar12 + -1 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                }
              }
              cVar8 = FUN_23e8d9ac0(plVar10,DAT_23eed9480);
              if (cVar8 == '\0') {
                local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                local_c8[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (local_c8[0] == (code *)0x0) {
                  plVar15 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  local_148 = (longlong *)0x0;
                  local_120 = 2;
                  iVar9 = 0x43d;
                  local_150 = (longlong *)0x0;
                  local_130 = (longlong *)0x0;
                  local_138 = (longlong *)0x0;
                  local_140 = (code *)0x0;
                  local_128 = (longlong *)0x0;
                  local_c8[0] = (code *)0x0;
                  goto LAB_23e761f8d;
                }
                if (*(longlong **)(local_c8[0] + 0x18) == plVar3) {
LAB_23e763978:
                  local_148 = (longlong *)0x0;
                  plVar15 = (longlong *)0x0;
                  local_120 = 2;
                  plVar13 = (longlong *)0x0;
                  local_150 = (longlong *)0x0;
                  local_130 = (longlong *)0x0;
                  local_138 = (longlong *)0x0;
                  local_140 = (code *)0x0;
                  local_128 = (longlong *)0x0;
                  pcVar14 = local_c8[0];
                  goto LAB_23e761b15;
                }
                local_148 = (longlong *)0x0;
                plVar15 = (longlong *)0x0;
                local_120 = 2;
                plVar13 = (longlong *)0x0;
                local_150 = (longlong *)0x0;
                iVar9 = 0x43d;
                local_130 = (longlong *)0x0;
                local_138 = (longlong *)0x0;
                local_140 = (code *)0x0;
                local_128 = (longlong *)0x0;
              }
              else {
                cVar8 = FUN_23e8d9ac0(plVar10,DAT_23eed9490);
                local_128 = (longlong *)0x0;
                if (cVar8 != '\0') goto LAB_23e761797;
                local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                local_c8[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (local_c8[0] == (code *)0x0) {
                  plVar15 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  local_120 = 2;
                  local_148 = (longlong *)0x0;
                  iVar9 = 0x43e;
                  local_150 = (longlong *)0x0;
                  local_130 = (longlong *)0x0;
                  local_138 = (longlong *)0x0;
                  local_140 = (code *)0x0;
                  local_128 = (longlong *)0x0;
                  local_c8[0] = (code *)0x0;
                  goto LAB_23e761f8d;
                }
                if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e763978;
                plVar15 = (longlong *)0x0;
                local_120 = 2;
                local_148 = (longlong *)0x0;
                plVar13 = (longlong *)0x0;
                iVar9 = 0x43e;
                local_150 = (longlong *)0x0;
                local_130 = (longlong *)0x0;
                local_138 = (longlong *)0x0;
                local_140 = (code *)0x0;
                local_128 = (longlong *)0x0;
              }
              goto LAB_23e761a50;
            }
            local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_c8[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] != (code *)0x0) {
              if (plVar3 == *(longlong **)(local_c8[0] + 0x18)) goto LAB_23e762520;
              plVar15 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              local_148 = (longlong *)0x0;
              local_120 = 2;
              iVar9 = 0x43c;
              local_150 = (longlong *)0x0;
              local_130 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_140 = (code *)0x0;
              local_128 = (longlong *)0x0;
              goto LAB_23e761a50;
            }
LAB_23e7641ec:
            plVar15 = (longlong *)0x0;
            local_120 = 2;
            local_128 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            iVar9 = 0x43c;
            local_148 = (longlong *)0x0;
            local_150 = (longlong *)0x0;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
            goto LAB_23e761f8d;
          }
          plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + 1;
            DAT_23ed6a498 = plVar11;
            goto LAB_23e7627b6;
          }
LAB_23e763cc3:
          PyErr_PrintEx(0);
          Py_Exit(1);
LAB_23e763cd6:
          plVar15 = (longlong *)0x0;
          local_120 = 2;
          plVar13 = (longlong *)0x0;
          local_148 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          iVar9 = 0x440;
          local_150 = (longlong *)0x0;
          local_130 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          local_140 = (code *)0x0;
          local_128 = (longlong *)0x0;
        }
        else {
          *(undefined4 *)(plVar3 + 5) = 0x440;
          local_68 = plVar13;
          local_78 = pcVar14;
          local_70 = uVar6;
          local_88 = plVar15;
          uStack_80 = uVar24;
          if (plVar11 == (longlong *)0x0) {
            plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
            if (plVar11 == (longlong *)0x0) goto LAB_23e763cc3;
            *plVar11 = *plVar11 + 1;
            DAT_23ed6a498 = plVar11;
          }
          plVar11 = (longlong *)FUN_23e95b390(param_1,plVar11,&local_88);
          if (plVar11 == (longlong *)0x0) {
            local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_c8[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] != (code *)0x0) {
              if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e762520;
              plVar15 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              local_120 = 2;
              local_148 = (longlong *)0x0;
              iVar9 = 0x440;
              local_150 = (longlong *)0x0;
              local_130 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_140 = (code *)0x0;
              local_128 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              goto LAB_23e761a50;
            }
            goto LAB_23e763cd6;
          }
          if (((code *)plVar11[1] != PyModule_Type_exref) &&
             (iVar9 = PyType_IsSubtype(), uVar24 = DAT_23eed94a0, iVar9 == 0)) {
            local_128 = (longlong *)PyObject_GetAttr(plVar11,DAT_23eed94a0);
            if (local_128 != (longlong *)0x0) goto LAB_23e761748;
            local_128 = (longlong *)FUN_23e8d2cf0(param_1,plVar11,uVar24);
LAB_23e76261c:
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (local_128 != (longlong *)0x0) goto LAB_23e761758;
            local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_c8[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] == (code *)0x0) goto LAB_23e763cd6;
            plVar15 = (longlong *)0x0;
            plVar16 = *(longlong **)(local_c8[0] + 0x18);
            local_148 = (longlong *)0x0;
            iVar9 = 0x440;
            local_150 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            local_120 = 2;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
            local_128 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            goto joined_r0x00023e7626c7;
          }
          uVar5 = DAT_23eed94a0;
          uVar24 = DAT_23eed8950;
          plVar13 = DAT_23ed6ccf0;
          local_128 = (longlong *)PyObject_GetAttr(plVar11,DAT_23eed94a0);
          if (local_128 == (longlong *)0x0) {
            local_128 = (longlong *)FUN_23e970390(param_1,plVar11,uVar24,uVar5,plVar13);
            goto LAB_23e76261c;
          }
LAB_23e761748:
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
LAB_23e761758:
          cVar8 = FUN_23e8d9ac0(plVar10,DAT_23eed9480,local_128);
          if (cVar8 == '\0') {
            local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_c8[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] != (code *)0x0) {
              if (*(longlong **)(local_c8[0] + 0x18) == plVar3) {
LAB_23e7631ac:
                local_148 = (longlong *)0x0;
                plVar15 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                local_120 = 2;
                local_150 = (longlong *)0x0;
                plVar13 = (longlong *)0x0;
                local_130 = (longlong *)0x0;
                local_138 = (longlong *)0x0;
                local_140 = (code *)0x0;
                pcVar14 = local_c8[0];
                goto LAB_23e761b15;
              }
              local_148 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              local_120 = 2;
              local_150 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              iVar9 = 0x441;
              local_130 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_140 = (code *)0x0;
              goto LAB_23e761a50;
            }
            local_148 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            local_150 = (longlong *)0x0;
            local_120 = 2;
            iVar9 = 0x441;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
            local_c8[0] = (code *)0x0;
            goto LAB_23e761f8d;
          }
          plVar11 = (longlong *)0x0;
          cVar8 = FUN_23e8d9ac0(plVar10,DAT_23eed9490,DAT_23eed94a8);
          if (cVar8 == '\0') {
            local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_c8[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] == (code *)0x0) {
              plVar15 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              local_120 = 2;
              local_148 = (longlong *)0x0;
              local_150 = (longlong *)0x0;
              local_130 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_140 = (code *)0x0;
              iVar9 = 0x442;
              local_c8[0] = (code *)0x0;
              goto LAB_23e761f8d;
            }
            if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e7631ac;
            local_148 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            local_120 = 2;
            plVar13 = (longlong *)0x0;
            local_150 = (longlong *)0x0;
            iVar9 = 0x442;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
            goto LAB_23e761a50;
          }
LAB_23e761797:
          lVar12 = FUN_23e8dffd0();
          if (lVar12 == 0) {
            FUN_23e915740(param_1,local_d8,DAT_23eed9400);
joined_r0x00023e76314d:
            if (local_c8[0] != (code *)0x0) {
              plVar13 = (longlong *)0x0;
              if (*(longlong **)(local_c8[0] + 0x18) != plVar3) {
                local_148 = (longlong *)0x0;
                plVar15 = (longlong *)0x0;
                local_120 = 2;
                iVar9 = 0x445;
                local_150 = (longlong *)0x0;
                local_130 = (longlong *)0x0;
                local_138 = (longlong *)0x0;
                local_140 = (code *)0x0;
                goto LAB_23e761a50;
              }
LAB_23e763017:
              local_148 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
              local_120 = 2;
              plVar13 = (longlong *)0x0;
              local_150 = (longlong *)0x0;
              local_130 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_140 = (code *)0x0;
              pcVar14 = local_c8[0];
              goto LAB_23e761b15;
            }
LAB_23e7632a6:
            plVar15 = (longlong *)0x0;
            local_120 = 2;
            plVar13 = (longlong *)0x0;
            local_148 = (longlong *)0x0;
            iVar9 = 0x445;
            local_150 = (longlong *)0x0;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            local_140 = (code *)0x0;
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x445;
            plVar13 = (longlong *)FUN_23e91a870(param_1,lVar12);
            if (plVar13 == (longlong *)0x0) {
              local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_c8[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto joined_r0x00023e76314d;
            }
            cVar8 = FUN_23e8d9ac0(plVar10,DAT_23eed9410,plVar13);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (cVar8 == '\0') {
              local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_c8[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (local_c8[0] == (code *)0x0) goto LAB_23e7632a6;
              if (*(longlong **)(local_c8[0] + 0x18) != plVar3) {
                local_148 = (longlong *)0x0;
                plVar15 = (longlong *)0x0;
                local_120 = 2;
                plVar13 = (longlong *)0x0;
                local_150 = (longlong *)0x0;
                iVar9 = 0x445;
                local_130 = (longlong *)0x0;
                local_138 = (longlong *)0x0;
                local_140 = (code *)0x0;
                goto LAB_23e761a50;
              }
              goto LAB_23e763017;
            }
            *(undefined4 *)(plVar3 + 5) = 0x448;
            plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed9418);
            if (plVar13 == (longlong *)0x0) {
              local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_c8[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (local_c8[0] == (code *)0x0) {
LAB_23e76499a:
                plVar15 = (longlong *)0x0;
                local_120 = 2;
                plVar13 = (longlong *)0x0;
                local_148 = (longlong *)0x0;
                iVar9 = 0x448;
                local_150 = (longlong *)0x0;
                local_130 = (longlong *)0x0;
                local_138 = (longlong *)0x0;
                local_140 = (code *)0x0;
                goto LAB_23e761f8d;
              }
              if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e763017;
              plVar15 = (longlong *)0x0;
              local_120 = 2;
              iVar9 = 0x448;
              local_148 = (longlong *)0x0;
              local_150 = (longlong *)0x0;
              local_130 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_140 = (code *)0x0;
              plVar13 = (longlong *)0x0;
              goto LAB_23e761a50;
            }
            iVar9 = FUN_23a35f020(plVar13);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            lVar12 = _DAT_23eed94b0;
            if (iVar9 == -1) {
              local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_c8[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (local_c8[0] == (code *)0x0) goto LAB_23e76499a;
              if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e763017;
              plVar15 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              iVar9 = 0x448;
              local_148 = (longlong *)0x0;
              local_150 = (longlong *)0x0;
              local_130 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_140 = (code *)0x0;
              local_120 = 2;
              goto LAB_23e761a50;
            }
            if (iVar9 == 0) {
              *(undefined4 *)(plVar3 + 5) = 0x449;
              plVar13 = (longlong *)
                        FUN_23e915840(param_1,plVar1,DAT_23eed8b40,*(undefined8 *)(lVar12 + 0x18));
              if (plVar13 != (longlong *)0x0) {
                lVar12 = *plVar13;
                *plVar13 = lVar12 + -1;
                if (lVar12 + -1 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                lVar12 = *(longlong *)pcVar14;
                goto LAB_23e76126c;
              }
              local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_c8[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (local_c8[0] == (code *)0x0) {
                plVar15 = (longlong *)0x0;
                local_148 = (longlong *)0x0;
                local_150 = (longlong *)0x0;
                local_130 = (longlong *)0x0;
                local_138 = (longlong *)0x0;
                local_140 = (code *)0x0;
                plVar13 = (longlong *)0x0;
                local_c8[0] = (code *)0x0;
                local_120 = 2;
                iVar9 = 0x449;
                goto LAB_23e761f8d;
              }
              if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e763017;
              plVar15 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              local_148 = (longlong *)0x0;
              local_150 = (longlong *)0x0;
              local_130 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_140 = (code *)0x0;
              local_120 = 2;
              iVar9 = 0x449;
              goto LAB_23e761a50;
            }
            *(undefined4 *)(plVar3 + 5) = 0x44d;
            plVar13 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23eed8c50);
            if (plVar13 == (longlong *)0x0) {
              local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_c8[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (local_c8[0] == (code *)0x0) {
                plVar15 = (longlong *)0x0;
                local_120 = 2;
                iVar9 = 0x44d;
                local_148 = (longlong *)0x0;
                local_150 = (longlong *)0x0;
                local_130 = (longlong *)0x0;
                local_138 = (longlong *)0x0;
                local_140 = (code *)0x0;
                plVar13 = (longlong *)0x0;
                local_c8[0] = (code *)0x0;
                goto LAB_23e761f8d;
              }
              if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e763017;
              plVar15 = (longlong *)0x0;
              iVar9 = 0x44d;
              local_148 = (longlong *)0x0;
              local_120 = 2;
              local_150 = (longlong *)0x0;
              local_130 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              local_140 = (code *)0x0;
              goto LAB_23e761a50;
            }
            lVar12 = *plVar13;
            *plVar13 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            uVar24 = DAT_23eed8a98;
            plVar13 = DAT_23ed6ccf0;
            *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
            plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,uVar24);
            local_120 = 0;
            if (plVar15 == (longlong *)0x0) {
LAB_23e76335f:
              local_c8[0] = *(code **)(param_1 + 0x70);
              plVar15 = (longlong *)0x0;
              local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_148 = (longlong *)0x0;
              uVar23 = 0x453;
              local_150 = (longlong *)0x0;
              local_130 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_140 = (code *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7633cc:
              pcVar22 = local_c8[0];
              local_f8._8_8_ = local_d8._8_8_;
              local_f8._0_8_ = local_d8._0_8_;
              local_c8[0] = (code *)0x0;
              local_d8._0_8_ = (code *)0x0;
              local_d8._8_8_ = 0;
              local_e8[0] = pcVar22;
              plVar16 = *(longlong **)(param_1 + 0x138);
              if (plVar16 != (longlong *)0x0) {
                *plVar16 = *plVar16 + 1;
              }
              pcVar21 = DAT_23ed6a4f8;
              if (pcVar22 == (code *)0x0) {
                pcVar21 = (code *)FUN_23e8d6280(plVar3);
                if ((local_e8[0] != (code *)0x0) &&
                   (*(longlong *)local_e8[0] = *(longlong *)local_e8[0] + -1,
                   *(longlong *)local_e8[0] == 0)) {
                  FUN_23a334bc0();
                }
              }
              else {
                if (DAT_23ed6a4f8 == (code *)0x0) {
                  pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  pcVar7 = *(code **)DAT_23ed6a4f8;
                  *(longlong *)DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = pcVar7;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                pcVar7 = _PyRuntime_exref;
                *(longlong **)(pcVar21 + 0x18) = plVar3;
                *plVar3 = *plVar3 + 1;
                lVar12 = *(longlong *)(pcVar7 + 0x1f8);
                *(undefined4 *)(pcVar21 + 0x24) = uVar23;
                *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
                lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
                lVar2 = *(longlong *)(pcVar21 + -8);
                puVar4 = *(undefined8 **)(lVar12 + 8);
                *puVar4 = pcVar21 + -0x10;
                *(longlong *)(pcVar21 + -0x10) = lVar12;
                *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
                *(code **)(lVar12 + 8) = pcVar21 + -0x10;
                *(code **)(pcVar21 + 0x10) = pcVar22;
                *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                if ((local_e8[0] != (code *)0x0) &&
                   (*(longlong *)local_e8[0] = *(longlong *)local_e8[0] + -1,
                   *(longlong *)local_e8[0] == 0)) {
                  FUN_23a334bc0(local_e8[0]);
                }
              }
              local_e8[0] = pcVar21;
              if (((code *)local_f8._0_8_ != pcVar14) && ((code *)local_f8._0_8_ != (code *)0x0)) {
                FUN_23e91b1b0(param_1,local_f8,local_f8 + 8,local_e8);
              }
              plVar17 = *(longlong **)(local_f8._8_8_ + 0x28);
              if (local_e8[0] == pcVar14) {
                pcVar22 = (code *)0x0;
              }
              else {
                pcVar22 = local_e8[0];
                if (local_e8[0] != (code *)0x0) {
                  *(longlong *)local_e8[0] = *(longlong *)local_e8[0] + 1;
                }
              }
              *(code **)(local_f8._8_8_ + 0x28) = pcVar22;
              if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                (**(code **)(plVar17[1] + 0x30))();
              }
              plVar17 = *(longlong **)(param_1 + 0x138);
              *(undefined8 *)(param_1 + 0x138) = local_f8._8_8_;
              if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                (**(code **)(plVar17[1] + 0x30))();
              }
              *(longlong *)local_f8._0_8_ = *(longlong *)local_f8._0_8_ + -1;
              if (*(longlong *)local_f8._0_8_ == 0) {
                (**(code **)(*(longlong *)(local_f8._0_8_ + 8) + 0x30))();
              }
              if ((local_e8[0] != (code *)0x0) &&
                 (*(longlong *)local_e8[0] = *(longlong *)local_e8[0] + -1,
                 *(longlong *)local_e8[0] == 0)) {
                (**(code **)(*(longlong *)(local_e8[0] + 8) + 0x30))();
              }
              local_e8[0] = (code *)0x0;
              local_f8 = (undefined1  [16])0x0;
              iVar9 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8));
              if (iVar9 == 0) {
                cVar8 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),local_d8);
                iVar9 = 0;
                if (cVar8 == '\0') {
                  iVar9 = 0x452;
                }
                pcVar14 = local_c8[0];
                pcVar22 = (code *)local_d8._0_8_;
                uVar24 = local_d8._8_8_;
                if ((local_c8[0] != (code *)0x0) && (*(longlong **)(local_c8[0] + 0x18) == plVar3))
                {
                  *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(local_c8[0] + 0x24);
                }
              }
              else {
                plVar17 = *(longlong **)(param_1 + 0x138);
                *plVar17 = *plVar17 + 1;
                if (plVar1 == (longlong *)0x0) {
                  FUN_23e8ba2b0(local_d8,DAT_23eed8d30);
                  if (((code *)local_d8._0_8_ != pcVar14) && ((code *)local_d8._0_8_ != (code *)0x0)
                     ) {
                    FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
                  }
                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_d8._8_8_);
                }
                else {
                  plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
                  plVar18 = DAT_23eed94d8;
                  if (plVar19 == (longlong *)0x0) {
                    local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    local_c8[0] = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                  }
                  else {
                    lVar12 = *(longlong *)(param_1 + 0x10);
                    plVar20 = *(longlong **)(lVar12 + 0xe20);
                    if (plVar20 == (longlong *)0x0) {
                      plVar20 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                    }
                    else {
                      lVar2 = plVar20[3];
                      *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
                      *(longlong *)(lVar12 + 0xe20) = lVar2;
                      *plVar20 = 1;
                    }
                    pcVar22 = _PyRuntime_exref;
                    plVar20[4] = 0;
                    lVar12 = *(longlong *)
                              (*(longlong *)(*(longlong *)(pcVar22 + 0x1f8) + 0x10) + 0x2e8);
                    lVar2 = plVar20[-1];
                    puVar4 = *(undefined8 **)(lVar12 + 8);
                    *puVar4 = plVar20 + -2;
                    plVar20[-2] = lVar12;
                    plVar20[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
                    *(longlong **)(lVar12 + 8) = plVar20 + -2;
                    *plVar18 = *plVar18 + 1;
                    plVar20[3] = (longlong)plVar18;
                    uVar24 = DAT_23ed6cd28;
                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                      plVar18 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      if (plVar18 == (longlong *)0x0) goto LAB_23e763cc3;
                      *plVar18 = *plVar18 + 1;
                      DAT_23ed6a4c0 = plVar18;
                    }
                    uStack_80 = uVar24;
                    local_88 = plVar17;
                    lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                    if (lVar12 == 0) {
                      local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      local_c8[0] = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar19 = *plVar19 + -1;
                      if (*plVar19 == 0) {
                        FUN_23a334bc0(plVar19);
                      }
                      *plVar20 = *plVar20 + -1;
                      if (*plVar20 == 0) {
                        FUN_23a334bc0(plVar20);
                      }
                    }
                    else {
                      plVar20[4] = lVar12;
                      plVar18 = (longlong *)PyUnicode_Join(DAT_23ed6cd28);
                      *plVar20 = *plVar20 + -1;
                      if (*plVar20 == 0) {
                        FUN_23a334bc0(plVar20);
                      }
                      if (plVar18 == (longlong *)0x0) {
                        local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        local_c8[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar19 = *plVar19 + -1;
                        if (*plVar19 == 0) {
                          FUN_23a334bc0(plVar19);
                        }
                      }
                      else {
                        *(undefined4 *)(plVar3 + 5) = 0x46c;
                        plVar20 = (longlong *)FUN_23e914090(param_1,plVar19);
                        *plVar19 = *plVar19 + -1;
                        if (*plVar19 == 0) {
                          FUN_23a334bc0(plVar19);
                        }
                        *plVar18 = *plVar18 + -1;
                        if (*plVar18 == 0) {
                          FUN_23a334bc0(plVar18);
                        }
                        if (plVar20 != (longlong *)0x0) {
                          *plVar20 = *plVar20 + -1;
                          if (*plVar20 == 0) {
                            FUN_23a334bc0(plVar20);
                          }
                          lVar12 = *plVar17;
                          *plVar17 = lVar12 + -1;
                          if (lVar12 + -1 == 0) {
                            FUN_23a334bc0(plVar17);
                          }
                          FUN_23ebf6ae0(param_1,plVar16);
                          goto LAB_23e76385a;
                        }
                        local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        local_c8[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                    }
                  }
                }
                pcVar14 = local_c8[0];
                uVar24 = local_d8._8_8_;
                pcVar22 = (code *)local_d8._0_8_;
                local_d8 = (undefined1  [16])0x0;
                local_c8[0] = (code *)0x0;
                lVar12 = *plVar17;
                *plVar17 = lVar12 + -1;
                if (lVar12 + -1 == 0) {
                  FUN_23a334bc0(plVar17);
                }
                iVar9 = 0x46c;
              }
              plVar17 = *(longlong **)(param_1 + 0x138);
              local_c8[0] = (code *)0x0;
              local_d8 = (undefined1  [16])0x0;
              *(longlong **)(param_1 + 0x138) = plVar16;
              if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                (**(code **)(plVar17[1] + 0x30))();
              }
              local_120 = iVar9;
              local_d8._0_8_ = pcVar22;
              local_d8._8_8_ = uVar24;
              if (pcVar14 == (code *)0x0) {
                local_c8[0] = (code *)0x0;
                if (iVar9 == 0) {
                  iVar9 = (int)plVar3[5];
                }
                else {
                  local_120 = 0;
                }
                goto LAB_23e761f8d;
              }
              if (*(longlong **)(pcVar14 + 0x18) == plVar3) {
                local_120 = 0;
                goto LAB_23e761b15;
              }
              local_c8[0] = pcVar14;
              if (iVar9 == 0) {
                iVar9 = (int)plVar3[5];
              }
              else {
                local_120 = 0;
              }
              goto LAB_23e761a50;
            }
            *(undefined4 *)(plVar3 + 5) = 0x453;
            local_140 = (code *)FUN_23e91bfe0(param_1,plVar15,DAT_23eed8a98);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (local_140 == (code *)0x0) goto LAB_23e76335f;
            if (local_140 != pcVar14) {
              *(undefined4 *)(plVar3 + 5) = 0x456;
              local_138 = (longlong *)FUN_23e915840(param_1,plVar10);
              if (local_138 == (longlong *)0x0) {
                local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                local_c8[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar15 = (longlong *)0x0;
                uVar23 = 0x456;
                local_148 = (longlong *)0x0;
                local_150 = (longlong *)0x0;
                local_130 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                local_130 = (longlong *)FUN_23e8bd600(param_1,local_138);
                if (local_130 == (longlong *)0x0) {
                  local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  local_c8[0] = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plVar15 = (longlong *)0x0;
                  uVar23 = 0x459;
                  local_148 = (longlong *)0x0;
                  local_150 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  cVar8 = FUN_23e8d1960(local_130);
                  local_150 = (longlong *)0x0;
                  if (cVar8 == '\0') {
LAB_23e762d7d:
                    plVar16 = (longlong *)FUN_23ebf7180(local_138);
                    if (plVar16 == (longlong *)0x0) {
                      local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      local_c8[0] = *(code **)(param_1 + 0x70);
                      uVar23 = 0x45e;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar15 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_148 = (longlong *)0x0;
                    }
                    else {
                      if (plVar1 == (longlong *)0x0) {
                        plVar15 = (longlong *)0x0;
                        plVar17 = (longlong *)0x0;
                        if (*(code **)(plVar16[1] + 0xe0) != (code *)0x0) {
                          local_118 = (longlong *)(**(code **)(plVar16[1] + 0xe0))(plVar16);
                          if (local_118 == (longlong *)0x0) {
                            plVar15 = (longlong *)0x0;
                            cVar8 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                            if (cVar8 == '\0') goto LAB_23e764882;
                            goto LAB_23e764808;
                          }
                          *local_118 = *local_118 + 1;
                          FUN_23e8ba2b0(local_d8,DAT_23eed8d30);
                          if (((code *)local_d8._0_8_ != pcVar14) &&
                             ((code *)local_d8._0_8_ != (code *)0x0)) {
                            FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
                          }
                          plVar15 = (longlong *)0x0;
                          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_d8._8_8_);
                          uVar23 = 0x45f;
                          goto LAB_23e763ff8;
                        }
LAB_23e7647aa:
                        PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                                     "\'%s\' object is not an iterator");
LAB_23e7647d5:
                        local_118 = plVar17;
                        cVar8 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                        if (cVar8 != '\0') {
                          if (local_118 != (longlong *)0x0) {
LAB_23e764a2f:
                            *local_118 = *local_118 + -1;
                            if (*local_118 == 0) {
                              FUN_23a334bc0(local_118);
                            }
                          }
LAB_23e764808:
                          lVar12 = *plVar16;
                          *plVar16 = lVar12 + -1;
                          local_148 = local_118;
                          if (lVar12 + -1 == 0) {
                            FUN_23a334bc0(plVar16);
                          }
                          goto LAB_23e76385a;
                        }
LAB_23e764882:
                        local_110 = *(code **)(param_1 + 0x70);
                        pcVar22 = *(code **)(param_1 + 0x60);
                        uVar24 = *(undefined8 *)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar23 = 0x45e;
                        local_c8[0] = (code *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        local_d8 = (undefined1  [16])0x0;
                        if (local_118 != (longlong *)0x0) goto LAB_23e76402f;
                      }
                      else {
                        plVar15 = (longlong *)0x0;
                        plVar17 = (longlong *)0x0;
                        do {
                          if (*(code **)(plVar16[1] + 0xe0) == (code *)0x0) goto LAB_23e7647aa;
                          local_118 = (longlong *)(**(code **)(plVar16[1] + 0xe0))();
                          if (local_118 == (longlong *)0x0) goto LAB_23e7647d5;
                          if (plVar17 == (longlong *)0x0) {
                            *local_118 = *local_118 + 1;
                          }
                          else {
                            *plVar17 = *plVar17 + -1;
                            if (*plVar17 == 0) {
                              FUN_23a334bc0(plVar17);
                            }
                            *local_118 = *local_118 + 1;
                            *plVar17 = *plVar17 + -1;
                            if (*plVar17 == 0) {
                              FUN_23a334bc0(plVar17);
                            }
                          }
                          plVar17 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89b0);
                          if (plVar17 == (longlong *)0x0) {
LAB_23e7645f5:
                            local_c8[0] = *(code **)(param_1 + 0x70);
                            local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e764634:
                            uVar23 = 0x45f;
                            goto LAB_23e763ff8;
                          }
                          *(undefined4 *)(plVar3 + 5) = 0x45f;
                          plVar18 = (longlong *)FUN_23e91bfe0(param_1,plVar17,DAT_23eed8d38);
                          *plVar17 = *plVar17 + -1;
                          if (*plVar17 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plVar18 == (longlong *)0x0) goto LAB_23e7645f5;
                          iVar9 = FUN_23a35f020(plVar18);
                          lVar12 = *plVar18 + -1;
                          if (iVar9 == -1) {
                            local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            local_c8[0] = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar18 = lVar12;
                            if (lVar12 == 0) {
                              FUN_23a334bc0(plVar18);
                            }
                            goto LAB_23e764634;
                          }
                          *plVar18 = lVar12;
                          if (lVar12 == 0) {
                            FUN_23a334bc0(plVar18);
                          }
                          if (iVar9 != 0) goto LAB_23e764a2f;
                          *(undefined4 *)(plVar3 + 5) = 0x463;
                          plVar17 = (longlong *)FUN_23e915840(param_1,plVar10);
                          if (plVar17 == (longlong *)0x0) {
                            local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            local_c8[0] = *(code **)(param_1 + 0x70);
                            uVar23 = 0x463;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23e763ff8;
                          }
                          if ((plVar15 != (longlong *)0x0) &&
                             (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                            FUN_23a334bc0(plVar15);
                          }
                          iVar9 = FUN_23a35f020(plVar17);
                          plVar15 = plVar17;
                          if (iVar9 == -1) {
                            local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            local_c8[0] = *(code **)(param_1 + 0x70);
                            uVar23 = 0x464;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23e763ff8;
                          }
                          if (iVar9 == 0) {
                            local_120 = 1;
                            goto LAB_23e764a2f;
                          }
                          if (plVar13 == (longlong *)0x0) {
                            FUN_23e8ba2b0(local_d8,DAT_23eed94d0);
                            if (((code *)local_d8._0_8_ != pcVar14) &&
                               ((code *)local_d8._0_8_ != (code *)0x0)) {
                              FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
                            }
                            FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_d8._8_8_);
                            uVar23 = 0x465;
                            goto LAB_23e763ff8;
                          }
                          local_88 = plVar13;
                          FUN_23e8d34a0(&local_88);
                          plVar13 = local_88;
                          lVar12 = *(longlong *)(param_1 + 0x10);
                          if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) != 0) ||
                               (*(int *)(lVar12 + 0x78) != 0)) &&
                              (iVar9 = Py_MakePendingCalls(), iVar9 < 0)) &&
                             (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e763fc3;
                          if (*(int *)(lVar12 + 0x68) == 0) {
                            plVar18 = *(longlong **)(param_1 + 0x90);
                          }
                          else {
                            PyEval_SaveThread();
                            PyEval_AcquireThread(param_1);
                            plVar18 = *(longlong **)(param_1 + 0x90);
                          }
                          plVar17 = local_118;
                        } while (plVar18 == (longlong *)0x0);
                        plVar17 = *(longlong **)(param_1 + 0x60);
                        plVar19 = *(longlong **)(param_1 + 0x68);
                        plVar20 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x90) = 0;
                        *(longlong **)(param_1 + 0x60) = plVar18;
                        *plVar18 = *plVar18 + 1;
                        *(undefined8 *)(param_1 + 0x68) = 0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        if ((plVar17 != (longlong *)0x0) &&
                           (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                          (**(code **)(plVar17[1] + 0x30))();
                        }
                        if ((plVar19 != (longlong *)0x0) &&
                           (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                          (**(code **)(plVar19[1] + 0x30))(plVar19);
                        }
                        if ((plVar20 != (longlong *)0x0) &&
                           (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
                          (**(code **)(plVar20[1] + 0x30))(plVar20);
                        }
LAB_23e763fc3:
                        local_c8[0] = *(code **)(param_1 + 0x70);
                        local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        uVar23 = 0x45e;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e763ff8:
                        local_110 = local_c8[0];
                        pcVar22 = (code *)local_d8._0_8_;
                        uVar24 = local_d8._8_8_;
LAB_23e76402f:
                        local_c8[0] = (code *)0x0;
                        local_d8 = (undefined1  [16])0x0;
                        *local_118 = *local_118 + -1;
                        if (*local_118 == 0) {
                          FUN_23a334bc0(local_118);
                        }
                      }
                      lVar12 = *plVar16;
                      *plVar16 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        FUN_23a334bc0();
                      }
                      local_c8[0] = local_110;
                      local_148 = local_118;
                      local_d8._0_8_ = pcVar22;
                      local_d8._8_8_ = uVar24;
                    }
                  }
                  else {
                    lVar12 = FUN_23e8e07b0();
                    if (lVar12 == 0) {
                      plVar15 = (longlong *)0x0;
                      FUN_23e915740(param_1,local_d8,DAT_23eed8f68);
                      uVar23 = 0x45b;
                      local_148 = (longlong *)0x0;
                      local_150 = (longlong *)0x0;
                    }
                    else {
                      *(undefined4 *)(plVar3 + 5) = 0x45b;
                      local_150 = (longlong *)FUN_23e91a870(param_1,lVar12);
                      if (local_150 == (longlong *)0x0) {
                        local_c8[0] = *(code **)(param_1 + 0x70);
                        local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        plVar15 = (longlong *)0x0;
                        uVar23 = 0x45b;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        local_148 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        *(undefined4 *)(plVar3 + 5) = 0x45c;
                        plVar15 = (longlong *)FUN_23e915840(param_1,local_150);
                        if (plVar15 != (longlong *)0x0) {
                          lVar12 = *plVar15;
                          *plVar15 = lVar12 + -1;
                          if (lVar12 + -1 == 0) {
                            FUN_23a334bc0(plVar15);
                          }
                          goto LAB_23e762d7d;
                        }
                        local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        local_c8[0] = *(code **)(param_1 + 0x70);
                        plVar15 = (longlong *)0x0;
                        uVar23 = 0x45c;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        local_148 = (longlong *)0x0;
                      }
                    }
                  }
                }
              }
              goto LAB_23e7633cc;
            }
            plVar15 = (longlong *)0x0;
            local_150 = (longlong *)0x0;
            local_148 = (longlong *)0x0;
            local_130 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
LAB_23e76385a:
            lVar12 = FUN_23e8e07b0();
            if (lVar12 == 0) {
              FUN_23e915740(param_1,local_d8,DAT_23eed8f68);
joined_r0x00023e7644f8:
              if (local_c8[0] != (code *)0x0) {
                plVar16 = *(longlong **)(local_c8[0] + 0x18);
                iVar9 = 0x46f;
joined_r0x00023e7626c7:
                pcVar14 = local_c8[0];
                if (plVar16 == plVar3) goto LAB_23e761b15;
                goto LAB_23e761a50;
              }
              local_c8[0] = (code *)0x0;
              iVar9 = 0x46f;
            }
            else {
              *(undefined4 *)(plVar3 + 5) = 0x46f;
              plVar16 = (longlong *)FUN_23e91a870(param_1,lVar12);
              if (plVar16 == (longlong *)0x0) {
                local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                local_c8[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto joined_r0x00023e7644f8;
              }
              if ((local_150 != (longlong *)0x0) && (*local_150 = *local_150 + -1, *local_150 == 0))
              {
                FUN_23a334bc0(local_150);
              }
              local_150 = plVar16;
              if (local_120 == 1) {
                *(undefined4 *)(plVar3 + 5) = 0x471;
                plVar16 = (longlong *)FUN_23e91bfe0(param_1,plVar16,DAT_23eed94e0);
                if (plVar16 != (longlong *)0x0) {
LAB_23e7642c2:
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0();
                  }
LAB_23e76391f:
                  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar3 = *(longlong **)(lVar12 + 0x28);
                  plVar16 = (longlong *)plVar3[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                       *(undefined8 *)(lVar12 + 0x30);
                  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                  if (plVar16 != (longlong *)0x0) {
                    plVar3[2] = 0;
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))();
                    }
                  }
                  *plVar3 = *plVar3 + -1;
                  if (*plVar3 == 0) {
                    (**(code **)(plVar3[1] + 0x30))(plVar3);
                  }
                  *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
                  plVar3[0xf] = 0;
                  goto LAB_23e761308;
                }
                local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                local_c8[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (local_c8[0] == (code *)0x0) {
                  local_c8[0] = (code *)0x0;
                  iVar9 = 0x471;
                  goto LAB_23e761f8d;
                }
                iVar9 = 0x471;
                plVar16 = *(longlong **)(local_c8[0] + 0x18);
                goto joined_r0x00023e7626c7;
              }
              if (plVar13 == (longlong *)0x0) {
                FUN_23e8ba2b0(local_d8,DAT_23eed94d0);
                if (((code *)local_d8._0_8_ != pcVar14) && ((code *)local_d8._0_8_ != (code *)0x0))
                {
                  FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
                }
                FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_d8._8_8_);
                if (local_c8[0] != (code *)0x0) {
                  iVar9 = 0x472;
                  plVar16 = *(longlong **)(local_c8[0] + 0x18);
                  goto joined_r0x00023e7626c7;
                }
                plVar13 = (longlong *)0x0;
                iVar9 = 0x472;
              }
              else {
                cVar8 = FUN_23e8d2220(plVar13,0);
                if (cVar8 == '\0') goto LAB_23e76391f;
                *(undefined4 *)(plVar3 + 5) = 0x473;
                plVar16 = (longlong *)FUN_23e91bfe0(param_1,plVar16,DAT_23eed94e8);
                if (plVar16 != (longlong *)0x0) goto LAB_23e7642c2;
                local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                local_c8[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (local_c8[0] != (code *)0x0) {
                  iVar9 = 0x473;
                  plVar16 = *(longlong **)(local_c8[0] + 0x18);
                  goto joined_r0x00023e7626c7;
                }
                local_c8[0] = (code *)0x0;
                iVar9 = 0x473;
              }
            }
          }
        }
      }
LAB_23e761f8d:
      pcVar14 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        pcVar22 = local_c8[0];
      }
      else {
        pcVar22 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar22;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        pcVar22 = (code *)0x0;
      }
      pcVar21 = _PyRuntime_exref;
      *(longlong *)(pcVar14 + 0x10) = 0;
      *(longlong **)(pcVar14 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar12 = *(longlong *)(pcVar21 + 0x1f8);
      *(int *)(pcVar14 + 0x24) = iVar9;
      lVar12 = *(longlong *)(lVar12 + 0x10);
      *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
      lVar12 = *(longlong *)(lVar12 + 0x2e8);
      lVar2 = *(longlong *)(pcVar14 + -8);
      puVar4 = *(undefined8 **)(lVar12 + 8);
      *puVar4 = pcVar14 + -0x10;
      *(longlong *)(pcVar14 + -0x10) = lVar12;
      *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(code **)(lVar12 + 8) = pcVar14 + -0x10;
      if ((pcVar22 != (code *)0x0) &&
         (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
        (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))();
      }
      goto LAB_23e761b15;
    }
    local_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
    local_c8[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar11 = lVar12;
    if (lVar12 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (local_c8[0] == (code *)0x0) goto LAB_23e761f30;
    if (*(longlong **)(local_c8[0] + 0x18) == plVar3) goto LAB_23e761e00;
    local_148 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    local_150 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    local_120 = 2;
    iVar9 = 0x430;
    local_130 = (longlong *)0x0;
    local_138 = (longlong *)0x0;
    local_140 = (code *)0x0;
    local_128 = (longlong *)0x0;
  }
LAB_23e761a50:
  pcVar22 = local_c8[0];
  pcVar14 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar21 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar21;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar14 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  *(int *)(pcVar14 + 0x24) = iVar9;
  pcVar21 = _PyRuntime_exref;
  *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
  lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar21 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = *(longlong *)(pcVar14 + -8);
  puVar4 = *(undefined8 **)(lVar12 + 8);
  *puVar4 = pcVar14 + -0x10;
  *(longlong *)(pcVar14 + -0x10) = lVar12;
  *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
  *(code **)(lVar12 + 8) = pcVar14 + -0x10;
  *(code **)(pcVar14 + 0x10) = pcVar22;
  *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
  if ((local_c8[0] != (code *)0x0) &&
     (*(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1, *(longlong *)local_c8[0] == 0)) {
    (**(code **)(*(longlong *)(local_c8[0] + 8) + 0x30))();
  }
LAB_23e761b15:
  local_c8[0] = pcVar14;
  FUN_23e8bba40(plVar3,"ooooobooooooo",plVar1,plVar10,plVar11,local_128,plVar13,local_120,local_140,
                local_138,local_130,local_150,local_148,plVar15,0);
  if (_DAT_23eedadb0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedadb0 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar12 + 0x28);
  plVar16 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar16 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar14 = local_c8[0];
  uVar5 = local_d8._8_8_;
  uVar24 = local_d8._0_8_;
  plVar3[0xf] = 0;
  local_d8 = (undefined1  [16])0x0;
  local_c8[0] = (code *)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((local_128 != (longlong *)0x0) &&
     (lVar12 = *local_128, *local_128 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_128[1] + 0x30))(local_128);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((local_140 != (code *)0x0) &&
     (lVar12 = *(longlong *)local_140, *(longlong *)local_140 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_140 + 8) + 0x30))(local_140);
  }
  if ((local_138 != (longlong *)0x0) &&
     (lVar12 = *local_138, *local_138 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_138[1] + 0x30))(local_138);
  }
  if ((local_130 != (longlong *)0x0) &&
     (lVar12 = *local_130, *local_130 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_130[1] + 0x30))(local_130);
  }
  if ((local_150 != (longlong *)0x0) &&
     (lVar12 = *local_150, *local_150 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_150[1] + 0x30))(local_150);
  }
  if ((local_148 != (longlong *)0x0) &&
     (lVar12 = *local_148, *local_148 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_148[1] + 0x30))(local_148);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  *plVar1 = *plVar1 + -1;
  local_c8[0] = pcVar14;
  local_d8._0_8_ = uVar24;
  local_d8._8_8_ = uVar5;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_d8._0_8_,local_d8._8_8_,local_c8[0]);
  return (code *)0x0;
}
