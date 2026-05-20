/* ===== 23e89a0c0 workers.fishing.trigger_monitor:86 ===== */
/* ghidra_name=FUN_23e89a0c0 entry=23e89a0c0 size=10343 */

code * FUN_23e89a0c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  code *pcVar16;
  code *pcVar17;
  code *pcVar18;
  longlong *plVar19;
  longlong lVar20;
  code *pcVar21;
  undefined4 uVar22;
  undefined1 auVar23 [8];
  undefined8 uVar24;
  longlong *local_130;
  longlong *local_128;
  longlong *local_120;
  longlong *local_118;
  code *local_110;
  longlong *local_108;
  longlong *local_100;
  longlong *local_f8;
  code *local_f0;
  code *local_e0;
  longlong *local_c0;
  undefined1 local_b8 [8];
  undefined8 uStack_b0;
  code *local_a8;
  undefined1 local_98 [16];
  code *local_88;
  undefined8 uStack_80;
  longlong *local_78;
  
  plVar8 = DAT_23eede550;
  plVar1 = (longlong *)*param_3;
  local_a8 = (code *)0x0;
  local_b8 = (undefined1  [8])0x0;
  uStack_b0 = (code *)0x0;
  if (DAT_23eede550 == (longlong *)0x0) {
LAB_23e89a125:
    DAT_23eede550 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede548,DAT_23eede5a0,0x78);
  }
  else {
    lVar9 = *DAT_23eede550;
    if (1 < lVar9) {
      *DAT_23eede550 = lVar9 + -1;
      goto LAB_23e89a125;
    }
    if (DAT_23eede550[2] != 0) {
      *DAT_23eede550 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e89a125;
    }
  }
  plVar19 = DAT_23eede550;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23eede550 + 9;
  lVar2 = *(longlong *)(lVar9 + 8);
  DAT_23eede550[0xf] = lVar2;
  *(longlong **)(lVar9 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar19[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar19[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar19 = *plVar19 + 1;
  uVar24 = DAT_23eedbec8;
  *(undefined4 *)(plVar19 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar24);
  if (plVar8 == (longlong *)0x0) {
LAB_23e89a570:
    local_a8 = *(code **)(param_1 + 0x70);
    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    uStack_b0 = *(code **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e89a599:
    uVar22 = 0x59;
LAB_23e89a59f:
    local_120 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    local_128 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_110 = (code *)0x0;
    local_100 = (longlong *)0x0;
    local_f0 = (code *)0x0;
    local_f8 = (longlong *)0x0;
    local_130 = (longlong *)0x0;
    pcVar16 = (code *)0x0;
LAB_23e89a616:
    pcVar18 = local_a8;
    local_98._8_8_ = uStack_b0;
    local_98._0_8_ = local_b8;
    local_a8 = (code *)0x0;
    local_b8 = (undefined1  [8])0x0;
    uStack_b0 = (code *)0x0;
    local_88 = pcVar18;
    plVar12 = *(longlong **)(param_1 + 0x138);
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
    pcVar17 = DAT_23ed6a4f8;
    if (pcVar18 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      local_e0 = _PyRuntime_exref;
      *(longlong *)(pcVar17 + 0x10) = 0;
      *(longlong **)(pcVar17 + 0x18) = plVar19;
      *plVar19 = *plVar19 + 1;
      lVar9 = *(longlong *)(*(longlong *)(local_e0 + 0x1f8) + 0x10);
      *(undefined4 *)(pcVar17 + 0x24) = uVar22;
      *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
      lVar9 = *(longlong *)(lVar9 + 0x2e8);
      lVar2 = *(longlong *)(pcVar17 + -8);
      puVar3 = *(undefined8 **)(lVar9 + 8);
      *puVar3 = pcVar17 + -0x10;
      *(longlong *)(pcVar17 + -0x10) = lVar9;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
      *(code **)(lVar9 + 8) = pcVar17 + -0x10;
      if ((local_88 != (code *)0x0) &&
         (*(longlong *)local_88 = *(longlong *)local_88 + -1, *(longlong *)local_88 == 0)) {
        (**(code **)(*(longlong *)(local_88 + 8) + 0x30))(local_88);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar21 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar21;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      local_e0 = _PyRuntime_exref;
      *(longlong **)(pcVar17 + 0x18) = plVar19;
      *plVar19 = *plVar19 + 1;
      lVar9 = *(longlong *)(local_e0 + 0x1f8);
      *(undefined4 *)(pcVar17 + 0x24) = uVar22;
      lVar9 = *(longlong *)(lVar9 + 0x10);
      *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
      lVar9 = *(longlong *)(lVar9 + 0x2e8);
      lVar2 = *(longlong *)(pcVar17 + -8);
      puVar3 = *(undefined8 **)(lVar9 + 8);
      *puVar3 = pcVar17 + -0x10;
      *(longlong *)(pcVar17 + -0x10) = lVar9;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
      *(code **)(lVar9 + 8) = pcVar17 + -0x10;
      *(code **)(pcVar17 + 0x10) = pcVar18;
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
      if ((local_88 != (code *)0x0) &&
         (*(longlong *)local_88 = *(longlong *)local_88 + -1, *(longlong *)local_88 == 0)) {
        (**(code **)(*(longlong *)(local_88 + 8) + 0x30))();
      }
    }
    pcVar18 = _Py_NoneStruct_exref;
    local_88 = pcVar17;
    if (((code *)local_98._0_8_ != (code *)0x0) && ((code *)local_98._0_8_ != _Py_NoneStruct_exref))
    {
      FUN_23e91b1b0(param_1,local_98,local_98 + 8,&local_88);
    }
    plVar13 = *(longlong **)(local_98._8_8_ + 0x28);
    if (local_88 == pcVar18) {
      pcVar17 = (code *)0x0;
    }
    else {
      pcVar17 = local_88;
      if (local_88 != (code *)0x0) {
        *(longlong *)local_88 = *(longlong *)local_88 + 1;
      }
    }
    *(code **)(local_98._8_8_ + 0x28) = pcVar17;
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))();
    }
    plVar13 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))();
    }
    *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
    if (*(longlong *)local_98._0_8_ == 0) {
      (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
    }
    if ((local_88 != (code *)0x0) &&
       (*(longlong *)local_88 = *(longlong *)local_88 + -1, *(longlong *)local_88 == 0)) {
      (**(code **)(*(longlong *)(local_88 + 8) + 0x30))();
    }
    local_88 = (code *)0x0;
    local_98 = (undefined1  [16])0x0;
    iVar6 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                          *(undefined8 *)PyExc_Exception_exref);
    if (iVar6 == 0) {
      pcVar17 = *(code **)(param_1 + 0x138);
      uStack_b0 = pcVar17;
      if ((pcVar17 == pcVar18) || (pcVar17 == (code *)0x0)) {
        plVar13 = *(longlong **)PyExc_RuntimeError_exref;
        uStack_b0 = (code *)PyUnicode_FromString("No active exception to reraise");
        pcVar17 = *(code **)(param_1 + 0x138);
        *plVar13 = *plVar13 + 1;
        *(longlong **)(param_1 + 0x138) = plVar12;
        if (pcVar17 != (code *)0x0) {
          iVar6 = 0x58;
          goto LAB_23e89bd8a;
        }
        local_b8 = (undefined1  [8])plVar13;
LAB_23e89bcbd:
        uVar22 = 0x58;
      }
      else {
        plVar13 = *(longlong **)(pcVar17 + 8);
        pcVar18 = *(code **)(pcVar17 + 0x28);
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        *plVar13 = *plVar13 + 1;
        iVar6 = 0;
        if (pcVar18 != (code *)0x0) {
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
          if (*(longlong **)(pcVar18 + 0x18) == plVar19) {
            *(undefined4 *)(plVar19 + 5) = *(undefined4 *)(pcVar18 + 0x24);
          }
          *(longlong **)(param_1 + 0x138) = plVar12;
          *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
          pcVar21 = pcVar17;
          if (*(longlong *)pcVar17 == 0) {
LAB_23e89bd9f:
            local_a8 = (code *)0x0;
            _local_b8 = (undefined1  [16])0x0;
            (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
            uStack_b0 = pcVar21;
            local_b8 = (undefined1  [8])plVar13;
            if (pcVar18 == (code *)0x0) goto LAB_23e89be00;
          }
          else {
            local_b8 = (undefined1  [8])plVar13;
          }
          pcVar17 = DAT_23ed6a4f8;
          if (plVar19 != *(longlong **)(pcVar18 + 0x18)) {
            uVar22 = 0x58;
            if (iVar6 == 0) {
              uVar22 = (undefined4)plVar19[5];
            }
            local_a8 = pcVar18;
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar21 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar21;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            *(longlong **)(pcVar17 + 0x18) = plVar19;
            *plVar19 = *plVar19 + 1;
            lVar9 = *(longlong *)(local_e0 + 0x1f8);
            *(undefined4 *)(pcVar17 + 0x24) = uVar22;
            *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
            lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
            lVar2 = *(longlong *)(pcVar17 + -8);
            puVar3 = *(undefined8 **)(lVar9 + 8);
            *puVar3 = pcVar17 + -0x10;
            *(longlong *)(pcVar17 + -0x10) = lVar9;
            *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
            *(code **)(lVar9 + 8) = pcVar17 + -0x10;
            *(code **)(pcVar17 + 0x10) = pcVar18;
            *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
            pcVar18 = pcVar17;
            if ((local_a8 != (code *)0x0) &&
               (*(longlong *)local_a8 = *(longlong *)local_a8 + -1, *(longlong *)local_a8 == 0)) {
              (**(code **)(*(longlong *)(local_a8 + 8) + 0x30))();
            }
          }
          goto LAB_23e89ab7c;
        }
        *(longlong **)(param_1 + 0x138) = plVar12;
LAB_23e89bd8a:
        lVar9 = *(longlong *)pcVar17;
        pcVar18 = (code *)0x0;
        *(longlong *)pcVar17 = lVar9 + -1;
        pcVar21 = uStack_b0;
        if (lVar9 + -1 == 0) goto LAB_23e89bd9f;
        local_b8 = (undefined1  [8])plVar13;
LAB_23e89be00:
        if (iVar6 != 0) goto LAB_23e89bcbd;
        uVar22 = (undefined4)plVar19[5];
      }
      pcVar18 = DAT_23ed6a4f8;
      local_a8 = (code *)0x0;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar17 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar18 + 0x10) = 0;
      *(longlong **)(pcVar18 + 0x18) = plVar19;
      *plVar19 = *plVar19 + 1;
      lVar9 = *(longlong *)(local_e0 + 0x1f8);
      *(undefined4 *)(pcVar18 + 0x24) = uVar22;
      lVar9 = *(longlong *)(lVar9 + 0x10);
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar9 = *(longlong *)(lVar9 + 0x2e8);
      lVar2 = *(longlong *)(pcVar18 + -8);
      puVar3 = *(undefined8 **)(lVar9 + 8);
      *puVar3 = pcVar18 + -0x10;
      *(longlong *)(pcVar18 + -0x10) = lVar9;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
      *(code **)(lVar9 + 8) = pcVar18 + -0x10;
      if ((local_a8 != (code *)0x0) &&
         (*(longlong *)local_a8 = *(longlong *)local_a8 + -1, *(longlong *)local_a8 == 0)) {
        (**(code **)(*(longlong *)((longlong)local_a8 + 8) + 0x30))();
      }
LAB_23e89ab7c:
      local_a8 = pcVar18;
      FUN_23e8bba40(plVar19,"ooooooooooooooo",plVar1,plVar8,local_130,plVar10,plVar11,local_f8,
                    local_f0,local_100,local_110,local_108,local_118,local_128,local_120,pcVar16,0);
      if (DAT_23eede550 == plVar19) {
        *plVar19 = *plVar19 + -1;
        if (*plVar19 == 0) {
          (**(code **)(plVar19[1] + 0x30))(plVar19);
        }
        DAT_23eede550 = (longlong *)0x0;
      }
      lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar19 = *(longlong **)(lVar9 + 0x28);
      plVar12 = (longlong *)plVar19[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
      *(undefined4 *)(plVar19 + 8) = 0xffffffff;
      if (plVar12 != (longlong *)0x0) {
        plVar19[2] = 0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
        }
      }
      *plVar19 = *plVar19 + -1;
      if (*plVar19 == 0) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
      pcVar18 = local_a8;
      plVar19[0xf] = 0;
      auVar23 = local_b8;
      uVar24 = uStack_b0;
      _local_b8 = (undefined1  [16])0x0;
      local_a8 = (code *)0x0;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if ((local_130 != (longlong *)0x0) &&
         (lVar9 = *local_130, *local_130 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_130[1] + 0x30))();
      }
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if ((local_f8 != (longlong *)0x0) &&
         (lVar9 = *local_f8, *local_f8 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_f8[1] + 0x30))();
      }
      if ((local_f0 != (code *)0x0) &&
         (lVar9 = *(longlong *)local_f0, *(longlong *)local_f0 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(*(longlong *)(local_f0 + 8) + 0x30))(local_f0);
      }
      if ((local_100 != (longlong *)0x0) &&
         (lVar9 = *local_100, *local_100 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_100[1] + 0x30))();
      }
      if ((local_110 != (code *)0x0) &&
         (lVar9 = *(longlong *)local_110, *(longlong *)local_110 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(*(longlong *)(local_110 + 8) + 0x30))(local_110);
      }
      if ((local_108 != (longlong *)0x0) &&
         (lVar9 = *local_108, *local_108 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_108[1] + 0x30))(local_108);
      }
      if ((local_118 != (longlong *)0x0) &&
         (lVar9 = *local_118, *local_118 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_118[1] + 0x30))();
      }
      if ((local_128 != (longlong *)0x0) &&
         (lVar9 = *local_128, *local_128 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_128[1] + 0x30))(local_128);
      }
      if ((local_120 != (longlong *)0x0) &&
         (lVar9 = *local_120, *local_120 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_120[1] + 0x30))(local_120);
      }
      if ((pcVar16 != (code *)0x0) &&
         (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
        (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
      }
      *plVar1 = *plVar1 + -1;
      local_a8 = pcVar18;
      local_b8 = auVar23;
      uStack_b0 = (code *)uVar24;
      if (*plVar1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      FUN_23a33aa70(param_1,local_b8,uStack_b0,local_a8);
      return (code *)0x0;
    }
    plVar19 = *(longlong **)(param_1 + 0x138);
    *plVar19 = *plVar19 + 1;
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
    lVar9 = *plVar19 + -1;
    *plVar19 = lVar9;
    pcVar17 = pcVar16;
    if (lVar9 == 0) {
      (**(code **)(plVar19[1] + 0x30))();
      plVar19 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar12;
      if (plVar19 == (longlong *)0x0) goto LAB_23e89a26b;
      lVar9 = *plVar19;
    }
    else {
      *(longlong **)(param_1 + 0x138) = plVar12;
    }
    *plVar19 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar19[1] + 0x30))();
    }
LAB_23e89a26b:
    lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar19 = *(longlong **)(lVar9 + 0x28);
    plVar12 = (longlong *)plVar19[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
    *(undefined4 *)(plVar19 + 8) = 0xffffffff;
    if (plVar12 != (longlong *)0x0) {
      plVar19[2] = 0;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))();
      }
    }
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    plVar19[0xf] = 0;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (local_130 != (longlong *)0x0) {
LAB_23e89a2dc:
      lVar9 = *local_130;
      *local_130 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
LAB_23e89a2f8:
        (**(code **)(local_130[1] + 0x30))();
      }
    }
    if (plVar10 == (longlong *)0x0) goto LAB_23e89a315;
  }
  else {
    iVar6 = FUN_23a35f020(plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (iVar6 == -1) goto LAB_23e89a570;
    if (iVar6 == 0) {
LAB_23e89a1e9:
      pcVar18 = _Py_NoneStruct_exref;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (code *)0x0;
      local_100 = (longlong *)0x0;
      local_f0 = (code *)0x0;
      local_f8 = (longlong *)0x0;
      local_130 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      goto LAB_23e89a26b;
    }
    lVar9 = FUN_23e8db7b0();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedbee0);
      goto LAB_23e89a599;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbf38);
    if (plVar8 == (longlong *)0x0) goto LAB_23e89a570;
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedbec8);
    if (plVar10 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e89a599;
    }
    *(undefined4 *)(plVar19 + 5) = 0x59;
    plVar11 = (longlong *)FUN_23e914090(param_1,plVar8,plVar10);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 == (longlong *)0x0) goto LAB_23e89a570;
    uVar7 = FUN_23a35f020(plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (uVar7 == 0xffffffff) goto LAB_23e89a570;
    if ((uVar7 & 1) == 0) goto LAB_23e89a1e9;
    lVar9 = FUN_23e8db7b0();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedbee0);
      pcVar18 = local_a8;
      auVar23 = local_b8;
      uVar24 = uStack_b0;
LAB_23e89bbb9:
      uVar22 = 0x5c;
      local_a8 = pcVar18;
      local_b8 = auVar23;
      uStack_b0 = (code *)uVar24;
      goto LAB_23e89a59f;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbf48);
    if (plVar8 == (longlong *)0x0) goto LAB_23e89bba0;
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedbec8);
    if (plVar10 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      pcVar18 = local_a8;
      auVar23 = local_b8;
      uVar24 = uStack_b0;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
        pcVar18 = local_a8;
        auVar23 = local_b8;
        uVar24 = uStack_b0;
      }
      goto LAB_23e89bbb9;
    }
    *(undefined4 *)(plVar19 + 5) = 0x5c;
    plVar11 = (longlong *)FUN_23e914090(param_1,plVar8,plVar10);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 == (longlong *)0x0) {
LAB_23e89bba0:
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      auVar23 = *(undefined1 (*) [8])(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar24 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e89bbb9;
    }
    plVar12 = (longlong *)FUN_23a388310(plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23e89bba0;
    plVar8 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
    if ((plVar8 == (longlong *)0x0) &&
       (plVar8 = (longlong *)FUN_23a3c1b70(param_1,local_b8,0,4), plVar8 == (longlong *)0x0)) {
      local_130 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
LAB_23e89beb6:
      pcVar18 = local_a8;
      uVar24 = uStack_b0;
      auVar23 = local_b8;
      local_a8 = (code *)0x0;
      _local_b8 = (undefined1  [16])0x0;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      local_a8 = (code *)0x0;
      local_b8 = (undefined1  [8])0x0;
      uStack_b0 = (code *)0x0;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if ((local_130 != (longlong *)0x0) &&
         (lVar9 = *local_130, *local_130 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_130[1] + 0x30))();
      }
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e89bbb9;
    }
    local_130 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
    if (local_130 == (longlong *)0x0) {
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_130 = (longlong *)FUN_23a3c1b70(param_1,local_b8,1,4);
      if (local_130 == (longlong *)0x0) goto LAB_23e89beb6;
    }
    plVar10 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
    if (plVar10 == (longlong *)0x0) {
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)FUN_23a3c1b70(param_1,local_b8,2,4);
      if (plVar10 == (longlong *)0x0) goto LAB_23e89beb6;
    }
    plVar11 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
    if (((plVar11 == (longlong *)0x0) &&
        (plVar11 = (longlong *)FUN_23a3c1b70(param_1,local_b8,3,4), plVar11 == (longlong *)0x0)) ||
       (cVar5 = FUN_23a3884a0(param_1,local_b8,plVar12), cVar5 == '\0')) goto LAB_23e89beb6;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (*local_130 == 0) {
      (**(code **)(local_130[1] + 0x30))();
    }
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    local_f8 = (longlong *)FUN_23e8c6640(plVar10);
    if (local_f8 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      local_120 = (longlong *)0x0;
      uVar22 = 0x5d;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (code *)0x0;
      local_100 = (longlong *)0x0;
      local_f0 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89a616;
    }
    local_f0 = (code *)FUN_23e8c6640(plVar11,local_130);
    if (local_f0 == (code *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      pcVar16 = (code *)0x0;
      uVar22 = 0x5e;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (code *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89a616;
    }
    lVar9 = FUN_23e8db7b0();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedbee0);
      goto LAB_23e89c258;
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbf58);
    if (plVar12 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      uVar22 = 0x60;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar16 = (code *)0x0;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_110 = (code *)0x0;
      goto LAB_23e89a616;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedbec8);
    if (plVar13 == (longlong *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      lVar9 = *plVar12;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        FUN_23a334bc0(plVar12);
      }
LAB_23e89c258:
      uVar22 = 0x60;
      pcVar16 = (code *)0x0;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (code *)0x0;
      local_100 = (longlong *)0x0;
      goto LAB_23e89a616;
    }
    *(undefined4 *)(plVar19 + 5) = 0x60;
    local_100 = (longlong *)FUN_23e914090(param_1,plVar12,plVar13);
    lVar9 = *plVar12;
    *plVar12 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (local_100 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89c258;
    }
    lVar9 = FUN_23e8db660();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedbf60);
      local_110 = (code *)0x0;
LAB_23e89c392:
      pcVar16 = (code *)0x0;
      uVar22 = 0x61;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      goto LAB_23e89a616;
    }
    *(undefined4 *)(plVar19 + 5) = 0x61;
    local_110 = (code *)FUN_23e915840(param_1,lVar9,DAT_23eedbf68);
    if (local_110 == (code *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89c392;
    }
    *(undefined4 *)(plVar19 + 5) = 0x62;
    local_108 = (longlong *)FUN_23e91bfe0(param_1,local_110);
    if (local_108 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      local_120 = (longlong *)0x0;
      pcVar16 = (code *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      uVar22 = 0x62;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89a616;
    }
    lVar9 = FUN_23e8db660();
    if (lVar9 == 0) {
      pcVar16 = (code *)0x0;
      FUN_23e915740(param_1,local_b8,DAT_23eedbf60);
      uVar22 = 100;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      goto LAB_23e89a616;
    }
    *(undefined4 *)(plVar19 + 5) = 100;
    local_118 = (longlong *)FUN_23e91bfe0(param_1,lVar9,DAT_23eedbf78);
    if (local_118 == (longlong *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      pcVar16 = (code *)0x0;
      uVar22 = 100;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89a616;
    }
    *(undefined4 *)(plVar19 + 5) = 0x65;
    local_98._8_8_ = local_f8;
    local_98._0_8_ = local_110;
    local_88 = local_f0;
    plVar12 = (longlong *)FUN_23e9578c0(param_1,local_118,DAT_23eedbf80,local_98);
    if (plVar12 == (longlong *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      pcVar16 = (code *)0x0;
      uVar22 = 0x65;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_120 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_128 = (longlong *)0x0;
      goto LAB_23e89a616;
    }
    lVar9 = *plVar12;
    *plVar12 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *(undefined4 *)(plVar19 + 5) = 0x66;
    plVar12 = (longlong *)FUN_23e915840(param_1,local_108,DAT_23eedbf88);
    if (plVar12 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar22 = 0x66;
      local_120 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_128 = (longlong *)0x0;
      goto LAB_23e89a616;
    }
    lVar9 = *plVar12;
    *plVar12 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      FUN_23a334bc0(plVar12);
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(local_108,DAT_23eedbf90);
    uVar24 = DAT_23eedbf40;
    if (plVar12 == (longlong *)0x0) {
LAB_23e89c4e0:
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e89c4c0:
      uVar22 = 0x68;
      pcVar16 = (code *)0x0;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      goto LAB_23e89a616;
    }
    plVar13 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
    uVar4 = DAT_23eedbf40;
    lVar2 = DAT_23eedbeb8;
    *local_f8 = *local_f8 + 1;
    lVar9 = *(longlong *)(lVar2 + 0x20);
    plVar13[3] = (longlong)local_f8;
    *(longlong *)local_f0 = *(longlong *)local_f0 + 1;
    plVar13[4] = (longlong)local_f0;
    if (*(char *)(lVar9 + 10) != '\0') {
      iVar6 = *(int *)(lVar9 + 0xc);
      if (*(int *)(lVar9 + 0xc) == 0) {
        *(int *)(lVar9 + 0xc) = DAT_23ec1552c;
        iVar6 = DAT_23ec1552c;
        DAT_23ec1552c = DAT_23ec1552c + 1;
      }
      if (DAT_23ec15524 != iVar6) {
        DAT_23ec15524 = iVar6;
        DAT_23eede540 = FUN_23e8cbd60(lVar9,DAT_23eedbf98,*(undefined8 *)(DAT_23eedbf98 + 0x18));
      }
      if (-1 < DAT_23eede540) {
        lVar2 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
        lVar20 = *(longlong *)(lVar2 + 8 + DAT_23eede540 * 0x10);
        if (lVar20 != 0) goto LAB_23e89b4f7;
        DAT_23eede540 = FUN_23e8cbd60(lVar9,DAT_23eedbf98,*(undefined8 *)(DAT_23eedbf98 + 0x18));
        if (-1 < DAT_23eede540) {
          lVar20 = *(longlong *)(lVar2 + 8 + DAT_23eede540 * 0x10);
          goto LAB_23e89c44b;
        }
      }
LAB_23e89c454:
      plVar14 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedbf98);
      if ((plVar14 != (longlong *)0x0) && (lVar20 = *plVar14, lVar20 != 0)) goto LAB_23e89b4f7;
      FUN_23e915740(param_1,local_b8,DAT_23eedbf98);
      *plVar12 = *plVar12 + -1;
      lVar9 = *plVar12;
joined_r0x00023e89c492:
      if (lVar9 == 0) {
        FUN_23a334bc0(plVar12);
      }
      lVar9 = *plVar13;
      *plVar13 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        FUN_23a334bc0(plVar13);
      }
      goto LAB_23e89c4c0;
    }
    plVar14 = (longlong *)FUN_23a37a020(lVar2,DAT_23eedbf98);
    if (plVar14 == (longlong *)0x0) goto LAB_23e89c454;
    lVar20 = *plVar14;
LAB_23e89c44b:
    if (lVar20 == 0) goto LAB_23e89c454;
LAB_23e89b4f7:
    plVar14 = (longlong *)FUN_23e8bc2f0(lVar20,DAT_23eedbfa0);
    if (plVar14 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = *plVar12 + -1;
      lVar9 = *plVar12;
      goto joined_r0x00023e89c492;
    }
    *(undefined4 *)(plVar19 + 5) = 0x68;
    local_98._8_8_ = plVar13;
    local_98._0_8_ = uVar24;
    uStack_80 = uVar4;
    local_88 = local_110;
    local_78 = plVar14;
    plVar15 = (longlong *)FUN_23e95b390(param_1,plVar12,local_98);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    lVar9 = *plVar13;
    *plVar13 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      FUN_23a334bc0(plVar13);
    }
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      FUN_23a334bc0(plVar14);
    }
    if (plVar15 == (longlong *)0x0) goto LAB_23e89c4e0;
    lVar9 = *plVar15;
    *plVar15 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      FUN_23a334bc0(plVar15);
    }
    *(undefined4 *)(plVar19 + 5) = 0x6a;
    local_128 = (longlong *)FUN_23e91bfe0(param_1,local_118);
    lVar9 = DAT_23eedbfb8;
    if (local_128 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      local_120 = (longlong *)0x0;
      pcVar16 = (code *)0x0;
      uVar22 = 0x6a;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89a616;
    }
    *(undefined4 *)(plVar19 + 5) = 0x6b;
    local_120 = (longlong *)
                FUN_23e915840(param_1,local_118,DAT_23eedbfb0,*(undefined8 *)(lVar9 + 0x18));
    if (local_120 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar22 = 0x6b;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89a616;
    }
    lVar9 = FUN_23e8db120();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedbfc0);
LAB_23e89c82f:
      uVar22 = 0x6d;
      pcVar16 = (code *)0x0;
      goto LAB_23e89a616;
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbfc8);
    if (plVar12 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      uVar22 = 0x6d;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar16 = (code *)0x0;
      goto LAB_23e89a616;
    }
    lVar9 = FUN_23e8db120();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedbfc0);
      *plVar12 = *plVar12 + -1;
      lVar9 = *plVar12;
joined_r0x00023e89c88b:
      if (lVar9 == 0) {
        FUN_23a334bc0(plVar12);
      }
      goto LAB_23e89c82f;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbfd0);
    if (plVar13 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = *plVar12 + -1;
      lVar9 = *plVar12;
      goto joined_r0x00023e89c88b;
    }
    *(undefined4 *)(plVar19 + 5) = 0x6d;
    local_98._0_8_ = local_120;
    local_c0 = plVar13;
    pcVar16 = (code *)FUN_23e939900(param_1,plVar12,local_98,&local_c0,DAT_23eedbfd8);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (pcVar16 == (code *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89c82f;
    }
    lVar9 = FUN_23a38cc10(param_1,local_128,DAT_23eedbfe0);
    if (lVar9 == 0) {
LAB_23e89c7df:
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e89c7cc:
      uVar22 = 0x6e;
      goto LAB_23e89a616;
    }
    plVar12 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
    plVar12[3] = lVar9;
    lVar9 = FUN_23a38cc10(param_1,local_128,DAT_23eedbfe8);
    if (lVar9 == 0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        FUN_23a334bc0(plVar12);
      }
      goto LAB_23e89c7cc;
    }
    plVar12[4] = lVar9;
    uVar24 = DAT_23eedbff8;
    plVar13 = DAT_23eedbff0;
    *DAT_23eedbff0 = *DAT_23eedbff0 + 1;
    plVar12[5] = (longlong)plVar13;
    cVar5 = FUN_23e8d9ac0(pcVar16,uVar24,plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    if (cVar5 == '\0') goto LAB_23e89c7df;
    lVar9 = FUN_23e8db510();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedc000);
LAB_23e89c71c:
      uVar22 = 0x6f;
      goto LAB_23e89a616;
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedc008);
    if (plVar12 == (longlong *)0x0) {
LAB_23e89c759:
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89c71c;
    }
    lVar9 = FUN_23e8db510();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedc000);
      *plVar12 = *plVar12 + -1;
      lVar9 = *plVar12;
joined_r0x00023e89c755:
      if (lVar9 == 0) {
        FUN_23a334bc0(plVar12);
      }
      goto LAB_23e89c71c;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedc010);
    if (plVar13 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = *plVar12 + -1;
      lVar9 = *plVar12;
      goto joined_r0x00023e89c755;
    }
    *(undefined4 *)(plVar19 + 5) = 0x6f;
    local_98._8_8_ = plVar13;
    local_98._0_8_ = pcVar16;
    pcVar17 = (code *)FUN_23e94ed00(param_1,plVar12,local_98);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (pcVar17 == (code *)0x0) goto LAB_23e89c759;
    lVar9 = *(longlong *)pcVar16;
    *(longlong *)pcVar16 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      FUN_23a334bc0(pcVar16);
    }
    lVar9 = FUN_23e8db7b0();
    pcVar16 = pcVar17;
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedbee0);
LAB_23e89c69e:
      uVar22 = 0x71;
      goto LAB_23e89a616;
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedc018);
    if (plVar12 == (longlong *)0x0) {
LAB_23e89c6a9:
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89c69e;
    }
    *(undefined4 *)(plVar19 + 5) = 0x71;
    plVar13 = (longlong *)FUN_23e91bfe0(param_1,local_118,DAT_23eedc020);
    if (plVar13 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        FUN_23a334bc0(plVar12);
      }
      goto LAB_23e89c69e;
    }
    *(undefined4 *)(plVar19 + 5) = 0x71;
    plVar14 = (longlong *)FUN_23e914090(param_1,plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (plVar14 == (longlong *)0x0) goto LAB_23e89c6a9;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      FUN_23a334bc0(plVar14);
    }
    *(undefined4 *)(plVar19 + 5) = 0x72;
    plVar12 = (longlong *)FUN_23e91bfe0(param_1,local_108);
    if (plVar12 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar22 = 0x72;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89a616;
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *(undefined4 *)(plVar19 + 5) = 0x73;
    plVar12 = (longlong *)FUN_23e91bfe0(param_1,local_110,DAT_23eedc028);
    if (plVar12 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      uVar22 = 0x73;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89a616;
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0();
    }
    lVar9 = FUN_23e8db7b0();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedbee0);
LAB_23e89c5bb:
      uVar22 = 0x74;
      goto LAB_23e89a616;
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(lVar9);
    if (plVar12 == (longlong *)0x0) {
LAB_23e89c5c6:
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e89c5bb;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedbec8);
    if (plVar13 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        FUN_23a334bc0(plVar12);
      }
      goto LAB_23e89c5bb;
    }
    *(undefined4 *)(plVar19 + 5) = 0x74;
    local_98._8_8_ = local_100;
    local_98._0_8_ = plVar13;
    plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar12,local_98);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (plVar14 == (longlong *)0x0) goto LAB_23e89c5c6;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      FUN_23a334bc0(plVar14);
    }
    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
    *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
    *plVar8 = *plVar8 + -1;
    pcVar18 = pcVar17;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      goto LAB_23e89a2dc;
    }
    lVar9 = *local_130;
    *local_130 = lVar9 + -1;
    if (lVar9 + -1 == 0) goto LAB_23e89a2f8;
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
LAB_23e89a315:
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((local_f8 != (longlong *)0x0) && (lVar9 = *local_f8, *local_f8 = lVar9 + -1, lVar9 + -1 == 0))
  {
    (**(code **)(local_f8[1] + 0x30))(local_f8);
  }
  if ((local_f0 != (code *)0x0) &&
     (lVar9 = *(longlong *)local_f0, *(longlong *)local_f0 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_f0 + 8) + 0x30))(local_f0);
  }
  if ((local_100 != (longlong *)0x0) &&
     (lVar9 = *local_100, *local_100 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_100[1] + 0x30))(local_100);
  }
  if ((local_110 != (code *)0x0) &&
     (lVar9 = *(longlong *)local_110, *(longlong *)local_110 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_110 + 8) + 0x30))(local_110);
  }
  if ((local_108 != (longlong *)0x0) &&
     (lVar9 = *local_108, *local_108 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_108[1] + 0x30))(local_108);
  }
  if ((local_118 != (longlong *)0x0) &&
     (lVar9 = *local_118, *local_118 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_118[1] + 0x30))(local_118);
  }
  if ((local_128 != (longlong *)0x0) &&
     (lVar9 = *local_128, *local_128 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_128[1] + 0x30))(local_128);
  }
  if ((local_120 != (longlong *)0x0) &&
     (lVar9 = *local_120, *local_120 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_120[1] + 0x30))(local_120);
  }
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  return pcVar18;
}
