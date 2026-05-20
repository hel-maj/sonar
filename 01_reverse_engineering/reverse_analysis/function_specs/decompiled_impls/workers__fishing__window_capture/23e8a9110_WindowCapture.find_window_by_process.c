/* ===== 23e8a9110 workers.fishing.window_capture:59 ===== */
/* ghidra_name=FUN_23e8a9110 entry=23e8a9110 size=10196 */

code * FUN_23e8a9110(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  code *pcVar18;
  code *pcVar19;
  longlong lVar20;
  undefined4 uVar21;
  code *pcVar22;
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
  
  plVar9 = DAT_23eede2b8;
  plVar1 = (longlong *)*param_3;
  local_a8 = (code *)0x0;
  local_b8 = (undefined1  [8])0x0;
  uStack_b0 = (code *)0x0;
  if (DAT_23eede2b8 == (longlong *)0x0) {
LAB_23e8a9175:
    DAT_23eede2b8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede2b0,DAT_23eede308,0x70);
  }
  else {
    lVar10 = *DAT_23eede2b8;
    if (1 < lVar10) {
      *DAT_23eede2b8 = lVar10 + -1;
      goto LAB_23e8a9175;
    }
    if (DAT_23eede2b8[2] != 0) {
      *DAT_23eede2b8 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e8a9175;
    }
  }
  plVar3 = DAT_23eede2b8;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar9 = DAT_23eede2b8 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  DAT_23eede2b8[0xf] = lVar2;
  *(longlong **)(lVar10 + 8) = plVar9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar24 = DAT_23eedb788;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar24);
  if (plVar9 == (longlong *)0x0) {
LAB_23e8a95c0:
    local_a8 = *(code **)(param_1 + 0x70);
    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    uStack_b0 = *(code **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e8a95e9:
    uVar21 = 0x3e;
LAB_23e8a95ef:
    local_120 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    local_128 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_110 = (code *)0x0;
    local_100 = (longlong *)0x0;
    local_f0 = (code *)0x0;
    local_f8 = (longlong *)0x0;
    local_130 = (longlong *)0x0;
    pcVar17 = (code *)0x0;
LAB_23e8a9666:
    pcVar19 = local_a8;
    local_98._8_8_ = uStack_b0;
    local_98._0_8_ = local_b8;
    local_a8 = (code *)0x0;
    local_b8 = (undefined1  [8])0x0;
    uStack_b0 = (code *)0x0;
    local_88 = pcVar19;
    plVar13 = *(longlong **)(param_1 + 0x138);
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
    }
    pcVar18 = DAT_23ed6a4f8;
    if (pcVar19 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar19 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar19;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      local_e0 = _PyRuntime_exref;
      *(longlong *)(pcVar18 + 0x10) = 0;
      *(longlong **)(pcVar18 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(local_e0 + 0x1f8);
      *(undefined4 *)(pcVar18 + 0x24) = uVar21;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x2e8);
      lVar2 = *(longlong *)(pcVar18 + -8);
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = pcVar18 + -0x10;
      *(longlong *)(pcVar18 + -0x10) = lVar10;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(code **)(lVar10 + 8) = pcVar18 + -0x10;
      if ((local_88 != (code *)0x0) &&
         (*(longlong *)local_88 = *(longlong *)local_88 + -1, *(longlong *)local_88 == 0)) {
        (**(code **)(*(longlong *)(local_88 + 8) + 0x30))(local_88);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar22 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar22;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      local_e0 = _PyRuntime_exref;
      *(longlong **)(pcVar18 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(local_e0 + 0x1f8);
      *(undefined4 *)(pcVar18 + 0x24) = uVar21;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x2e8);
      lVar2 = *(longlong *)(pcVar18 + -8);
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = pcVar18 + -0x10;
      *(longlong *)(pcVar18 + -0x10) = lVar10;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(code **)(lVar10 + 8) = pcVar18 + -0x10;
      *(code **)(pcVar18 + 0x10) = pcVar19;
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      if ((local_88 != (code *)0x0) &&
         (*(longlong *)local_88 = *(longlong *)local_88 + -1, *(longlong *)local_88 == 0)) {
        (**(code **)(*(longlong *)(local_88 + 8) + 0x30))();
      }
    }
    pcVar19 = _Py_NoneStruct_exref;
    local_88 = pcVar18;
    if (((code *)local_98._0_8_ != (code *)0x0) && ((code *)local_98._0_8_ != _Py_NoneStruct_exref))
    {
      FUN_23e91b1b0(param_1,local_98,local_98 + 8,&local_88);
    }
    plVar14 = *(longlong **)(local_98._8_8_ + 0x28);
    if (local_88 == pcVar19) {
      pcVar18 = (code *)0x0;
    }
    else {
      pcVar18 = local_88;
      if (local_88 != (code *)0x0) {
        *(longlong *)local_88 = *(longlong *)local_88 + 1;
      }
    }
    *(code **)(local_98._8_8_ + 0x28) = pcVar18;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
    }
    plVar14 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
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
    iVar7 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                          *(undefined8 *)PyExc_Exception_exref);
    if (iVar7 == 0) {
      pcVar18 = *(code **)(param_1 + 0x138);
      uStack_b0 = pcVar18;
      if ((pcVar18 == pcVar19) || (pcVar18 == (code *)0x0)) {
        plVar14 = *(longlong **)PyExc_RuntimeError_exref;
        uStack_b0 = (code *)PyUnicode_FromString("No active exception to reraise");
        pcVar18 = *(code **)(param_1 + 0x138);
        *plVar14 = *plVar14 + 1;
        *(longlong **)(param_1 + 0x138) = plVar13;
        if (pcVar18 != (code *)0x0) {
          iVar7 = 0x3d;
          goto LAB_23e8aac85;
        }
        local_b8 = (undefined1  [8])plVar14;
LAB_23e8a9f1d:
        uVar21 = 0x3d;
      }
      else {
        plVar14 = *(longlong **)(pcVar18 + 8);
        pcVar19 = *(code **)(pcVar18 + 0x28);
        *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
        *plVar14 = *plVar14 + 1;
        iVar7 = 0;
        if (pcVar19 != (code *)0x0) {
          *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
          if (*(longlong **)(pcVar19 + 0x18) == plVar3) {
            *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar19 + 0x24);
          }
          *(longlong **)(param_1 + 0x138) = plVar13;
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
          pcVar22 = pcVar18;
          if (*(longlong *)pcVar18 == 0) {
LAB_23e8aac9a:
            local_a8 = (code *)0x0;
            _local_b8 = (undefined1  [16])0x0;
            (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
            uStack_b0 = pcVar22;
            local_b8 = (undefined1  [8])plVar14;
            if (pcVar19 == (code *)0x0) goto LAB_23e8aad00;
          }
          else {
            local_b8 = (undefined1  [8])plVar14;
          }
          pcVar18 = DAT_23ed6a4f8;
          if (plVar3 != *(longlong **)(pcVar19 + 0x18)) {
            uVar21 = 0x3d;
            if (iVar7 == 0) {
              uVar21 = (undefined4)plVar3[5];
            }
            local_a8 = pcVar19;
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar22 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar22;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            *(longlong **)(pcVar18 + 0x18) = plVar3;
            *plVar3 = *plVar3 + 1;
            lVar10 = *(longlong *)(local_e0 + 0x1f8);
            *(undefined4 *)(pcVar18 + 0x24) = uVar21;
            *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
            lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
            lVar2 = *(longlong *)(pcVar18 + -8);
            puVar4 = *(undefined8 **)(lVar10 + 8);
            *puVar4 = pcVar18 + -0x10;
            *(longlong *)(pcVar18 + -0x10) = lVar10;
            *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
            *(code **)(lVar10 + 8) = pcVar18 + -0x10;
            *(code **)(pcVar18 + 0x10) = pcVar19;
            *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
            pcVar19 = pcVar18;
            if ((local_a8 != (code *)0x0) &&
               (*(longlong *)local_a8 = *(longlong *)local_a8 + -1, *(longlong *)local_a8 == 0)) {
              (**(code **)(*(longlong *)(local_a8 + 8) + 0x30))();
            }
          }
          goto LAB_23e8a9b29;
        }
        *(longlong **)(param_1 + 0x138) = plVar13;
LAB_23e8aac85:
        lVar10 = *(longlong *)pcVar18;
        pcVar19 = (code *)0x0;
        *(longlong *)pcVar18 = lVar10 + -1;
        pcVar22 = uStack_b0;
        if (lVar10 + -1 == 0) goto LAB_23e8aac9a;
        local_b8 = (undefined1  [8])plVar14;
LAB_23e8aad00:
        if (iVar7 != 0) goto LAB_23e8a9f1d;
        uVar21 = (undefined4)plVar3[5];
      }
      pcVar19 = DAT_23ed6a4f8;
      local_a8 = (code *)0x0;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar19 + 0x10) = 0;
      *(longlong **)(pcVar19 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(local_e0 + 0x1f8);
      *(undefined4 *)(pcVar19 + 0x24) = uVar21;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x2e8);
      lVar2 = *(longlong *)(pcVar19 + -8);
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = pcVar19 + -0x10;
      *(longlong *)(pcVar19 + -0x10) = lVar10;
      *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(code **)(lVar10 + 8) = pcVar19 + -0x10;
      if ((local_a8 != (code *)0x0) &&
         (*(longlong *)local_a8 = *(longlong *)local_a8 + -1, *(longlong *)local_a8 == 0)) {
        (**(code **)(*(longlong *)((longlong)local_a8 + 8) + 0x30))();
      }
LAB_23e8a9b29:
      local_a8 = pcVar19;
      FUN_23e8bba40(plVar3,"oooooooooooooo",plVar1,plVar9,local_130,plVar11,plVar12,local_f8,
                    local_f0,local_100,local_110,local_108,local_118,local_128,local_120,pcVar17);
      if (DAT_23eede2b8 == plVar3) {
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
        }
        DAT_23eede2b8 = (longlong *)0x0;
      }
      lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar3 = *(longlong **)(lVar10 + 0x28);
      plVar13 = (longlong *)plVar3[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
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
      pcVar19 = local_a8;
      plVar3[0xf] = 0;
      auVar23 = local_b8;
      uVar24 = uStack_b0;
      _local_b8 = (undefined1  [16])0x0;
      local_a8 = (code *)0x0;
      if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if ((local_130 != (longlong *)0x0) &&
         (lVar10 = *local_130, *local_130 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(local_130[1] + 0x30))();
      }
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if ((local_f8 != (longlong *)0x0) &&
         (lVar10 = *local_f8, *local_f8 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(local_f8[1] + 0x30))(local_f8);
      }
      if ((local_f0 != (code *)0x0) &&
         (lVar10 = *(longlong *)local_f0, *(longlong *)local_f0 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(*(longlong *)(local_f0 + 8) + 0x30))(local_f0);
      }
      if ((local_100 != (longlong *)0x0) &&
         (lVar10 = *local_100, *local_100 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(local_100[1] + 0x30))();
      }
      if ((local_110 != (code *)0x0) &&
         (lVar10 = *(longlong *)local_110, *(longlong *)local_110 = lVar10 + -1, lVar10 + -1 == 0))
      {
        (**(code **)(*(longlong *)(local_110 + 8) + 0x30))(local_110);
      }
      if ((local_108 != (longlong *)0x0) &&
         (lVar10 = *local_108, *local_108 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(local_108[1] + 0x30))(local_108);
      }
      if ((local_118 != (longlong *)0x0) &&
         (lVar10 = *local_118, *local_118 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(local_118[1] + 0x30))();
      }
      if ((local_128 != (longlong *)0x0) &&
         (lVar10 = *local_128, *local_128 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(local_128[1] + 0x30))(local_128);
      }
      if ((local_120 != (longlong *)0x0) &&
         (lVar10 = *local_120, *local_120 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(local_120[1] + 0x30))(local_120);
      }
      if ((pcVar17 != (code *)0x0) &&
         (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
      }
      *plVar1 = *plVar1 + -1;
      local_a8 = pcVar19;
      local_b8 = auVar23;
      uStack_b0 = (code *)uVar24;
      if (*plVar1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      FUN_23a33aa70(param_1,local_b8,uStack_b0,local_a8);
      return (code *)0x0;
    }
    plVar3 = *(longlong **)(param_1 + 0x138);
    *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
    *(longlong **)(param_1 + 0x138) = plVar13;
    pcVar18 = pcVar17;
    if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
      (**(code **)(plVar3[1] + 0x30))();
    }
LAB_23e8a92bb:
    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar3 = *(longlong **)(lVar10 + 0x28);
    plVar13 = (longlong *)plVar3[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
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
    if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (local_130 != (longlong *)0x0) {
LAB_23e8a932c:
      lVar10 = *local_130;
      *local_130 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
LAB_23e8a934b:
        (**(code **)(local_130[1] + 0x30))();
      }
    }
    if (plVar11 == (longlong *)0x0) goto LAB_23e8a9369;
  }
  else {
    iVar7 = FUN_23a35f020(plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (iVar7 == -1) goto LAB_23e8a95c0;
    if (iVar7 == 0) {
LAB_23e8a9239:
      pcVar19 = _Py_NoneStruct_exref;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (code *)0x0;
      local_100 = (longlong *)0x0;
      local_f0 = (code *)0x0;
      local_f8 = (longlong *)0x0;
      local_130 = (longlong *)0x0;
      pcVar18 = (code *)0x0;
      goto LAB_23e8a92bb;
    }
    lVar10 = FUN_23e8da870();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedb7b8);
      goto LAB_23e8a95e9;
    }
    plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eedb810);
    if (plVar9 == (longlong *)0x0) goto LAB_23e8a95c0;
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedb788);
    if (plVar11 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e8a95e9;
    }
    *(undefined4 *)(plVar3 + 5) = 0x3e;
    plVar12 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23e8a95c0;
    uVar8 = FUN_23a35f020(plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (uVar8 == 0xffffffff) goto LAB_23e8a95c0;
    if ((uVar8 & 1) == 0) goto LAB_23e8a9239;
    lVar10 = FUN_23e8da870();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedb7b8);
      pcVar19 = local_a8;
      auVar23 = local_b8;
      uVar24 = uStack_b0;
LAB_23e8aad31:
      uVar21 = 0x41;
      local_a8 = pcVar19;
      local_b8 = auVar23;
      uStack_b0 = (code *)uVar24;
      goto LAB_23e8a95ef;
    }
    plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eedb820);
    if (plVar9 == (longlong *)0x0) goto LAB_23e8aad18;
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedb788);
    if (plVar11 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar9 = *plVar9 + -1;
      pcVar19 = local_a8;
      auVar23 = local_b8;
      uVar24 = uStack_b0;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
        pcVar19 = local_a8;
        auVar23 = local_b8;
        uVar24 = uStack_b0;
      }
      goto LAB_23e8aad31;
    }
    *(undefined4 *)(plVar3 + 5) = 0x41;
    plVar12 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar12 == (longlong *)0x0) {
LAB_23e8aad18:
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      auVar23 = *(undefined1 (*) [8])(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar24 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e8aad31;
    }
    plVar13 = (longlong *)FUN_23a388310(plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) goto LAB_23e8aad18;
    plVar9 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
    if ((plVar9 == (longlong *)0x0) &&
       (plVar9 = (longlong *)FUN_23a3c1b70(param_1,local_b8,0,4), plVar9 == (longlong *)0x0)) {
      local_130 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
LAB_23e8aae5e:
      pcVar19 = local_a8;
      uVar24 = uStack_b0;
      auVar23 = local_b8;
      local_a8 = (code *)0x0;
      _local_b8 = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      local_a8 = (code *)0x0;
      local_b8 = (undefined1  [8])0x0;
      uStack_b0 = (code *)0x0;
      if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if ((local_130 != (longlong *)0x0) &&
         (lVar10 = *local_130, *local_130 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(local_130[1] + 0x30))();
      }
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e8aad31;
    }
    local_130 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
    if (local_130 == (longlong *)0x0) {
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      local_130 = (longlong *)FUN_23a3c1b70(param_1,local_b8,1,4);
      if (local_130 == (longlong *)0x0) goto LAB_23e8aae5e;
    }
    plVar11 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
    if (plVar11 == (longlong *)0x0) {
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)FUN_23a3c1b70(param_1,local_b8,2,4);
      if (plVar11 == (longlong *)0x0) goto LAB_23e8aae5e;
    }
    plVar12 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
    if (((plVar12 == (longlong *)0x0) &&
        (plVar12 = (longlong *)FUN_23a3c1b70(param_1,local_b8,3,4), plVar12 == (longlong *)0x0)) ||
       (cVar6 = FUN_23a3884a0(param_1,local_b8,plVar13), cVar6 == '\0')) goto LAB_23e8aae5e;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (*local_130 == 0) {
      (**(code **)(local_130[1] + 0x30))();
    }
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    local_f8 = (longlong *)FUN_23e8c6640(plVar11);
    if (local_f8 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      pcVar17 = (code *)0x0;
      local_120 = (longlong *)0x0;
      uVar21 = 0x42;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (code *)0x0;
      local_100 = (longlong *)0x0;
      local_f0 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a9666;
    }
    local_f0 = (code *)FUN_23e8c6640(plVar12,local_130);
    if (local_f0 == (code *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      pcVar17 = (code *)0x0;
      uVar21 = 0x43;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (code *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a9666;
    }
    lVar10 = FUN_23e8da870();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedb7b8);
      goto LAB_23e8ab202;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eedb830);
    if (plVar13 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      uVar21 = 0x45;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar17 = (code *)0x0;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_110 = (code *)0x0;
      goto LAB_23e8a9666;
    }
    plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedb788);
    if (plVar14 == (longlong *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      lVar10 = *plVar13;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        FUN_23a334bc0(plVar13);
      }
LAB_23e8ab202:
      uVar21 = 0x45;
      pcVar17 = (code *)0x0;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (code *)0x0;
      local_100 = (longlong *)0x0;
      goto LAB_23e8a9666;
    }
    *(undefined4 *)(plVar3 + 5) = 0x45;
    local_100 = (longlong *)FUN_23e914090(param_1,plVar13,plVar14);
    lVar10 = *plVar13;
    *plVar13 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0(plVar13);
    }
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      FUN_23a334bc0(plVar14);
    }
    if (local_100 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8ab202;
    }
    lVar10 = FUN_23e8da5d0();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedb838);
      local_110 = (code *)0x0;
LAB_23e8ab2a7:
      pcVar17 = (code *)0x0;
      uVar21 = 0x46;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      goto LAB_23e8a9666;
    }
    *(undefined4 *)(plVar3 + 5) = 0x46;
    local_110 = (code *)FUN_23e915840(param_1,lVar10,DAT_23eedb840);
    if (local_110 == (code *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8ab2a7;
    }
    *(undefined4 *)(plVar3 + 5) = 0x47;
    local_108 = (longlong *)FUN_23e91bfe0(param_1,local_110);
    if (local_108 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      local_120 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      uVar21 = 0x47;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a9666;
    }
    lVar10 = FUN_23e8da5d0();
    if (lVar10 == 0) {
      pcVar17 = (code *)0x0;
      FUN_23e915740(param_1,local_b8,DAT_23eedb838);
      uVar21 = 0x49;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      goto LAB_23e8a9666;
    }
    *(undefined4 *)(plVar3 + 5) = 0x49;
    local_118 = (longlong *)FUN_23e91bfe0(param_1,lVar10,DAT_23eedb850);
    if (local_118 == (longlong *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      pcVar17 = (code *)0x0;
      uVar21 = 0x49;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a9666;
    }
    *(undefined4 *)(plVar3 + 5) = 0x4a;
    local_98._8_8_ = local_f8;
    local_98._0_8_ = local_110;
    local_88 = local_f0;
    plVar13 = (longlong *)FUN_23e9578c0(param_1,local_118,DAT_23eedb858,local_98);
    if (plVar13 == (longlong *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      pcVar17 = (code *)0x0;
      uVar21 = 0x4a;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_120 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_128 = (longlong *)0x0;
      goto LAB_23e8a9666;
    }
    lVar10 = *plVar13;
    *plVar13 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0(plVar13);
    }
    *(undefined4 *)(plVar3 + 5) = 0x4b;
    plVar13 = (longlong *)FUN_23e915840(param_1,local_108,DAT_23eedb860);
    if (plVar13 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      pcVar17 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar21 = 0x4b;
      local_120 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_128 = (longlong *)0x0;
      goto LAB_23e8a9666;
    }
    lVar10 = *plVar13;
    *plVar13 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0(plVar13);
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(local_108,DAT_23eedb868);
    uVar24 = DAT_23eedb818;
    if (plVar13 == (longlong *)0x0) {
LAB_23e8ab902:
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e8ab842:
      uVar21 = 0x4d;
      pcVar17 = (code *)0x0;
      local_120 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      goto LAB_23e8a9666;
    }
    plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
    uVar5 = DAT_23eedb818;
    lVar2 = DAT_23eedb778;
    *local_f8 = *local_f8 + 1;
    lVar10 = *(longlong *)(lVar2 + 0x20);
    plVar14[3] = (longlong)local_f8;
    *(longlong *)local_f0 = *(longlong *)local_f0 + 1;
    plVar14[4] = (longlong)local_f0;
    if (*(char *)(lVar10 + 10) != '\0') {
      iVar7 = *(int *)(lVar10 + 0xc);
      if (*(int *)(lVar10 + 0xc) == 0) {
        *(int *)(lVar10 + 0xc) = DAT_23ec154d4;
        iVar7 = DAT_23ec154d4;
        DAT_23ec154d4 = DAT_23ec154d4 + 1;
      }
      if (DAT_23ec154cc != iVar7) {
        DAT_23ec154cc = iVar7;
        DAT_23eede2a8 = FUN_23e8cbd60(lVar10,DAT_23eedb870,*(undefined8 *)(DAT_23eedb870 + 0x18));
      }
      if (-1 < DAT_23eede2a8) {
        lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
        lVar20 = *(longlong *)(lVar2 + 8 + DAT_23eede2a8 * 0x10);
        if (lVar20 != 0) goto LAB_23e8aa5a7;
        DAT_23eede2a8 = FUN_23e8cbd60(lVar10,DAT_23eedb870,*(undefined8 *)(DAT_23eedb870 + 0x18));
        if (-1 < DAT_23eede2a8) {
          lVar20 = *(longlong *)(lVar2 + 8 + DAT_23eede2a8 * 0x10);
          goto LAB_23e8ab89a;
        }
      }
LAB_23e8ab8a3:
      plVar15 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedb870);
      if ((plVar15 != (longlong *)0x0) && (lVar20 = *plVar15, lVar20 != 0)) goto LAB_23e8aa5a7;
      FUN_23e915740(param_1,local_b8,DAT_23eedb870);
      *plVar13 = *plVar13 + -1;
      lVar10 = *plVar13;
joined_r0x00023e8ab8e1:
      if (lVar10 == 0) {
        FUN_23a334bc0(plVar13);
      }
      lVar10 = *plVar14;
      *plVar14 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        FUN_23a334bc0(plVar14);
      }
      goto LAB_23e8ab842;
    }
    plVar15 = (longlong *)FUN_23a37a020(lVar2,DAT_23eedb870);
    if (plVar15 == (longlong *)0x0) goto LAB_23e8ab8a3;
    lVar20 = *plVar15;
LAB_23e8ab89a:
    if (lVar20 == 0) goto LAB_23e8ab8a3;
LAB_23e8aa5a7:
    plVar15 = (longlong *)FUN_23e8bc2f0(lVar20,DAT_23eedb878);
    if (plVar15 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      lVar10 = *plVar13;
      goto joined_r0x00023e8ab8e1;
    }
    *(undefined4 *)(plVar3 + 5) = 0x4d;
    local_98._8_8_ = plVar14;
    local_98._0_8_ = uVar24;
    uStack_80 = uVar5;
    local_88 = local_110;
    local_78 = plVar15;
    plVar16 = (longlong *)FUN_23e95b390(param_1,plVar13,local_98);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    lVar10 = *plVar14;
    *plVar14 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0(plVar14);
    }
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      FUN_23a334bc0(plVar15);
    }
    if (plVar16 == (longlong *)0x0) goto LAB_23e8ab902;
    lVar10 = *plVar16;
    *plVar16 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0(plVar16);
    }
    *(undefined4 *)(plVar3 + 5) = 0x4f;
    local_128 = (longlong *)FUN_23e91bfe0(param_1,local_118);
    lVar10 = DAT_23eedb890;
    if (local_128 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      local_120 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      uVar21 = 0x4f;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a9666;
    }
    *(undefined4 *)(plVar3 + 5) = 0x50;
    local_120 = (longlong *)
                FUN_23e915840(param_1,local_118,DAT_23eedb888,*(undefined8 *)(lVar10 + 0x18));
    if (local_120 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      pcVar17 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar21 = 0x50;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a9666;
    }
    lVar10 = FUN_23e8da720();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedb898);
LAB_23e8ab6cb:
      uVar21 = 0x52;
      pcVar17 = (code *)0x0;
      goto LAB_23e8a9666;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eedb8a0);
    if (plVar13 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      uVar21 = 0x52;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar17 = (code *)0x0;
      goto LAB_23e8a9666;
    }
    lVar10 = FUN_23e8da720();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedb898);
      *plVar13 = *plVar13 + -1;
      lVar10 = *plVar13;
joined_r0x00023e8ab727:
      if (lVar10 == 0) {
        FUN_23a334bc0(plVar13);
      }
      goto LAB_23e8ab6cb;
    }
    plVar14 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eedb8a8);
    if (plVar14 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      lVar10 = *plVar13;
      goto joined_r0x00023e8ab727;
    }
    *(undefined4 *)(plVar3 + 5) = 0x52;
    local_98._0_8_ = local_120;
    local_c0 = plVar14;
    pcVar17 = (code *)FUN_23e939900(param_1,plVar13,local_98,&local_c0,DAT_23eedb8b0);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      FUN_23a334bc0(plVar14);
    }
    if (pcVar17 == (code *)0x0) {
      local_a8 = *(code **)(param_1 + 0x70);
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8ab6cb;
    }
    lVar10 = FUN_23a38cc10(param_1,local_128,DAT_23eedb8b8);
    if (lVar10 == 0) {
LAB_23e8ab67b:
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e8ab668:
      uVar21 = 0x53;
      goto LAB_23e8a9666;
    }
    plVar13 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
    plVar13[3] = lVar10;
    lVar10 = FUN_23a38cc10(param_1,local_128,DAT_23eedb8c0);
    if (lVar10 == 0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0(plVar13);
      }
      goto LAB_23e8ab668;
    }
    plVar13[4] = lVar10;
    uVar24 = DAT_23eedb8d0;
    plVar14 = DAT_23eedb8c8;
    *DAT_23eedb8c8 = *DAT_23eedb8c8 + 1;
    plVar13[5] = (longlong)plVar14;
    cVar6 = FUN_23e8d9ac0(pcVar17,uVar24,plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (cVar6 == '\0') goto LAB_23e8ab67b;
    lVar10 = FUN_23e8da480();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedb8d8);
LAB_23e8ab5b8:
      uVar21 = 0x54;
      goto LAB_23e8a9666;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eedb8e0);
    if (plVar13 == (longlong *)0x0) {
LAB_23e8ab5f5:
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8ab5b8;
    }
    lVar10 = FUN_23e8da480();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedb8d8);
      *plVar13 = *plVar13 + -1;
      lVar10 = *plVar13;
joined_r0x00023e8ab5f1:
      if (lVar10 == 0) {
        FUN_23a334bc0(plVar13);
      }
      goto LAB_23e8ab5b8;
    }
    plVar14 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eedb8e8);
    if (plVar14 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      lVar10 = *plVar13;
      goto joined_r0x00023e8ab5f1;
    }
    *(undefined4 *)(plVar3 + 5) = 0x54;
    local_98._8_8_ = plVar14;
    local_98._0_8_ = pcVar17;
    pcVar18 = (code *)FUN_23e94ed00(param_1,plVar13,local_98);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      FUN_23a334bc0(plVar14);
    }
    if (pcVar18 == (code *)0x0) goto LAB_23e8ab5f5;
    lVar10 = *(longlong *)pcVar17;
    *(longlong *)pcVar17 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0(pcVar17);
    }
    lVar10 = FUN_23e8da870();
    pcVar17 = pcVar18;
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedb7b8);
LAB_23e8ab53a:
      uVar21 = 0x56;
      goto LAB_23e8a9666;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eedb8f0);
    if (plVar13 == (longlong *)0x0) {
LAB_23e8ab545:
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8ab53a;
    }
    *(undefined4 *)(plVar3 + 5) = 0x56;
    plVar14 = (longlong *)FUN_23e91bfe0(param_1,local_118,DAT_23eedb8f8);
    if (plVar14 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0(plVar13);
      }
      goto LAB_23e8ab53a;
    }
    *(undefined4 *)(plVar3 + 5) = 0x56;
    plVar15 = (longlong *)FUN_23e914090(param_1,plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      FUN_23a334bc0(plVar14);
    }
    if (plVar15 == (longlong *)0x0) goto LAB_23e8ab545;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      FUN_23a334bc0(plVar15);
    }
    *(undefined4 *)(plVar3 + 5) = 0x57;
    plVar13 = (longlong *)FUN_23e91bfe0(param_1,local_108);
    if (plVar13 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar21 = 0x57;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a9666;
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    *(undefined4 *)(plVar3 + 5) = 0x58;
    plVar13 = (longlong *)FUN_23e91bfe0(param_1,local_110,DAT_23eedb900);
    if (plVar13 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      uVar21 = 0x58;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a9666;
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0();
    }
    lVar10 = FUN_23e8da870();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedb7b8);
LAB_23e8ab457:
      uVar21 = 0x59;
      goto LAB_23e8a9666;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(lVar10);
    if (plVar13 == (longlong *)0x0) {
LAB_23e8ab462:
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8ab457;
    }
    plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedb788);
    if (plVar14 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_b0 = *(code **)(param_1 + 0x68);
      local_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0(plVar13);
      }
      goto LAB_23e8ab457;
    }
    *(undefined4 *)(plVar3 + 5) = 0x59;
    local_98._8_8_ = local_100;
    local_98._0_8_ = plVar14;
    plVar15 = (longlong *)FUN_23e94ed00(param_1,plVar13,local_98);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      FUN_23a334bc0(plVar14);
    }
    if (plVar15 == (longlong *)0x0) goto LAB_23e8ab462;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      FUN_23a334bc0(plVar15);
    }
    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
    *plVar9 = *plVar9 + -1;
    pcVar19 = pcVar18;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      goto LAB_23e8a932c;
    }
    lVar10 = *local_130;
    *local_130 = lVar10 + -1;
    if (lVar10 + -1 == 0) goto LAB_23e8a934b;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
LAB_23e8a9369:
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((local_f8 != (longlong *)0x0) &&
     (lVar10 = *local_f8, *local_f8 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(local_f8[1] + 0x30))(local_f8);
  }
  if ((local_f0 != (code *)0x0) &&
     (lVar10 = *(longlong *)local_f0, *(longlong *)local_f0 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_f0 + 8) + 0x30))(local_f0);
  }
  if ((local_100 != (longlong *)0x0) &&
     (lVar10 = *local_100, *local_100 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(local_100[1] + 0x30))(local_100);
  }
  if ((local_110 != (code *)0x0) &&
     (lVar10 = *(longlong *)local_110, *(longlong *)local_110 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_110 + 8) + 0x30))(local_110);
  }
  if ((local_108 != (longlong *)0x0) &&
     (lVar10 = *local_108, *local_108 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(local_108[1] + 0x30))(local_108);
  }
  if ((local_118 != (longlong *)0x0) &&
     (lVar10 = *local_118, *local_118 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(local_118[1] + 0x30))(local_118);
  }
  if ((local_128 != (longlong *)0x0) &&
     (lVar10 = *local_128, *local_128 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(local_128[1] + 0x30))();
  }
  if ((local_120 != (longlong *)0x0) &&
     (lVar10 = *local_120, *local_120 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(local_120[1] + 0x30))(local_120);
  }
  if ((pcVar18 != (code *)0x0) &&
     (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  return pcVar19;
}
