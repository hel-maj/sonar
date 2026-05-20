/* ===== 23e7c8c60 workers.fishing.garbage_disposal:356 ===== */
/* ghidra_name=FUN_23e7c8c60 entry=23e7c8c60 size=13247 */

/* WARNING: Type propagation algorithm not settling */

longlong * FUN_23e7c8c60(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  code *pcVar16;
  longlong *plVar17;
  undefined8 uVar18;
  longlong lVar19;
  longlong *plVar20;
  longlong *plVar21;
  longlong *plVar22;
  code *pcVar23;
  longlong *plVar24;
  undefined4 uVar25;
  longlong *local_130;
  longlong *local_128;
  longlong *local_118;
  longlong *local_110;
  longlong *local_108;
  longlong *local_100;
  longlong *local_f8;
  longlong *local_d0;
  code *local_c8;
  longlong *local_c0;
  longlong *local_b8;
  undefined1 local_a8 [16];
  longlong *local_98 [2];
  longlong *local_88;
  code *pcStack_80;
  longlong *local_78;
  
  plVar1 = (longlong *)*param_3;
  lVar19 = *(longlong *)(param_1 + 0x10);
  plVar2 = (longlong *)param_3[1];
  local_98[0] = (longlong *)0x0;
  local_a8 = (undefined1  [16])0x0;
  if (*(int *)(lVar19 + 0x1188) == 0) {
    plVar13 = (longlong *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    iVar6 = *(int *)(lVar19 + 0x1188) + -1;
    *(int *)(lVar19 + 0x1188) = iVar6;
    plVar13 = *(longlong **)(lVar19 + 0xf08 + (longlong)iVar6 * 8);
    *plVar13 = 1;
  }
  pcVar16 = _PyRuntime_exref;
  plVar13[2] = 0;
  plVar13[4] = 0;
  plVar7 = DAT_23eedabf0;
  lVar19 = *(longlong *)(pcVar16 + 0x1f8);
  plVar13[3] = 0;
  lVar19 = *(longlong *)(*(longlong *)(lVar19 + 0x10) + 0x2e8);
  lVar3 = plVar13[-1];
  puVar4 = *(undefined8 **)(lVar19 + 8);
  *puVar4 = plVar13 + -2;
  plVar13[-2] = lVar19;
  plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
  *(longlong **)(lVar19 + 8) = plVar13 + -2;
  if (plVar7 == (longlong *)0x0) {
LAB_23e7c8d62:
    plVar7 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedabe8,DAT_23eedacf8);
    DAT_23eedabf0 = plVar7;
  }
  else {
    lVar19 = *plVar7;
    if (1 < lVar19) {
      *plVar7 = lVar19 + -1;
      goto LAB_23e7c8d62;
    }
    if (plVar7[2] != 0) {
      *plVar7 = lVar19 + -1;
      if (lVar19 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e7c8d62;
    }
  }
  lVar19 = *(longlong *)(param_1 + 0x38);
  lVar3 = *(longlong *)(lVar19 + 8);
  plVar7[0xf] = lVar3;
  *(longlong **)(lVar19 + 8) = plVar7 + 9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  *(undefined4 *)(plVar7 + 8) = 0;
  uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
  uVar18 = DAT_23eed84e0;
  *(undefined4 *)(plVar7 + 5) = 0x16b;
  plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar8,uVar18);
  if (plVar9 == (longlong *)0x0) {
    local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_98[0] = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    uVar25 = 0x16b;
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_118 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_128 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    local_130 = (longlong *)0x0;
    goto LAB_23e7c91dc;
  }
  lVar19 = *plVar9;
  *plVar9 = lVar19 + -1;
  if (lVar19 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
    lVar19 = *(longlong *)(param_1 + 0x10);
    iVar6 = *(int *)(lVar19 + 0x1188);
    if (iVar6 != 0) goto LAB_23e7c8e51;
LAB_23e7c95bc:
    local_130 = (longlong *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    lVar19 = *(longlong *)(param_1 + 0x10);
    iVar6 = *(int *)(lVar19 + 0x1188);
    if (iVar6 == 0) goto LAB_23e7c95bc;
LAB_23e7c8e51:
    *(int *)(lVar19 + 0x1188) = iVar6 + -1;
    local_130 = *(longlong **)(lVar19 + 0xf08 + (longlong)(iVar6 + -1) * 8);
    *local_130 = 1;
  }
  pcVar16 = _PyRuntime_exref;
  local_130[2] = 0;
  local_130[4] = 0;
  lVar19 = *(longlong *)(pcVar16 + 0x1f8);
  local_130[3] = 0;
  lVar19 = *(longlong *)(*(longlong *)(lVar19 + 0x10) + 0x2e8);
  lVar3 = local_130[-1];
  puVar4 = *(undefined8 **)(lVar19 + 8);
  *puVar4 = local_130 + -2;
  local_130[-2] = lVar19;
  local_130[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
  plVar9 = DAT_23eed84e8;
  *(longlong **)(lVar19 + 8) = local_130 + -2;
  if (*(code **)(plVar9[1] + 0xd8) == (code *)0x0) {
    plVar10 = (longlong *)FUN_23a33a530(PySeqIter_Type_exref);
    plVar10[2] = 0;
    *plVar9 = *plVar9 + 1;
    plVar10[3] = (longlong)plVar9;
    lVar19 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = plVar10[-1];
    plVar9 = *(longlong **)(lVar19 + 8);
    *plVar9 = (longlong)(plVar10 + -2);
    plVar10[-2] = lVar19;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar9;
    *(longlong **)(lVar19 + 8) = plVar10 + -2;
  }
  else {
    plVar10 = (longlong *)(**(code **)(plVar9[1] + 0xd8))(plVar9);
  }
  if (plVar1 == (longlong *)0x0) {
    plVar9 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
      local_a8._8_8_ =
           PyUnicode_FromFormat
                     ("cannot access local variable \'%U\' where it is not associated with a value",
                      DAT_23eed80d0);
      local_a8._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
      *(longlong *)local_a8._0_8_ = *(longlong *)local_a8._0_8_ + 1;
      local_98[0] = (longlong *)0x0;
      if ((code *)local_a8._0_8_ != _Py_NoneStruct_exref) {
        FUN_23e91b1b0(param_1,local_a8,local_a8 + 8,local_98);
      }
      uVar25 = 0x170;
      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_a8._8_8_);
      *plVar9 = *plVar9 + -1;
      lVar19 = *plVar9;
      plVar11 = local_98[0];
      pcVar16 = (code *)local_a8._0_8_;
      uVar18 = local_a8._8_8_;
      goto joined_r0x00023e7c967e;
    }
    local_c8 = PyExc_StopIteration_exref;
    cVar5 = FUN_23a3591a0(param_1);
    if (cVar5 == '\0') {
      pcVar16 = *(code **)(param_1 + 0x60);
      uVar18 = *(undefined8 *)(param_1 + 0x68);
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7c9f9b:
      local_98[0] = (longlong *)0x0;
      local_a8 = (undefined1  [16])0x0;
      uVar25 = 0x16f;
      goto LAB_23e7c917a;
    }
LAB_23e7cb108:
    plVar9 = (longlong *)0x0;
LAB_23e7c991c:
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    iVar6 = FUN_23a35f020(local_130);
    if (iVar6 != -1) {
      if (iVar6 == 0) {
        uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
        uVar18 = DAT_23eed84f8;
        *(undefined4 *)(plVar7 + 5) = 0x174;
        plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar8,uVar18);
        if (plVar10 != (longlong *)0x0) {
          lVar19 = *plVar10;
          *plVar10 = lVar19 + -1;
          if (lVar19 + -1 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          local_118 = (longlong *)0x0;
          lVar19 = *plVar13;
          local_f8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_128 = (longlong *)0x0;
LAB_23e7c99ea:
          *plVar13 = lVar19 + 1;
          lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar7 = *(longlong **)(lVar19 + 0x28);
          plVar10 = (longlong *)plVar7[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar19 + 0x30);
          *(undefined4 *)(plVar7 + 8) = 0xffffffff;
          if (plVar10 != (longlong *)0x0) {
            plVar7[2] = 0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))();
            }
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          plVar7[0xf] = 0;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          lVar19 = *local_130;
          *local_130 = lVar19 + -1;
          if (lVar19 + -1 == 0) {
            (**(code **)(local_130[1] + 0x30))(local_130);
          }
          if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if ((local_128 != (longlong *)0x0) &&
             (lVar19 = *local_128, *local_128 = lVar19 + -1, lVar19 + -1 == 0)) {
            (**(code **)(local_128[1] + 0x30))(local_128);
          }
          if ((local_110 != (longlong *)0x0) &&
             (lVar19 = *local_110, *local_110 = lVar19 + -1, lVar19 + -1 == 0)) {
            (**(code **)(local_110[1] + 0x30))(local_110);
          }
          if ((local_108 != (longlong *)0x0) &&
             (lVar19 = *local_108, *local_108 = lVar19 + -1, lVar19 + -1 == 0)) {
            (**(code **)(local_108[1] + 0x30))(local_108);
          }
          if ((local_100 != (longlong *)0x0) &&
             (lVar19 = *local_100, *local_100 = lVar19 + -1, lVar19 + -1 == 0)) {
            (**(code **)(local_100[1] + 0x30))(local_100);
          }
          if ((local_f8 != (longlong *)0x0) &&
             (lVar19 = *local_f8, *local_f8 = lVar19 + -1, lVar19 + -1 == 0)) {
            (**(code **)(local_f8[1] + 0x30))(local_f8);
          }
          if ((local_118 != (longlong *)0x0) &&
             (lVar19 = *local_118, *local_118 = lVar19 + -1, lVar19 + -1 == 0)) {
            (**(code **)(local_118[1] + 0x30))(local_118);
          }
          lVar19 = *plVar1;
          *plVar1 = lVar19 + -1;
          if (lVar19 + -1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          lVar19 = *plVar2;
          *plVar2 = lVar19 + -1;
          if (lVar19 + -1 != 0) {
            return plVar13;
          }
          (**(code **)(plVar2[1] + 0x30))(plVar2);
          return plVar13;
        }
        local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_98[0] = *(longlong **)(param_1 + 0x70);
        local_118 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar25 = 0x174;
        local_f8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        local_128 = (longlong *)0x0;
        goto LAB_23e7c91dc;
      }
      plVar10 = (longlong *)FUN_23ebf7180(local_130);
      if (plVar10 == (longlong *)0x0) {
        local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_98[0] = *(longlong **)(param_1 + 0x70);
        local_118 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar25 = 0x177;
        local_f8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_128 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7c91dc;
      }
      local_118 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      do {
        plVar12 = (longlong *)(**(code **)(plVar10[1] + 0xe0))();
        if (plVar12 == (longlong *)0x0) {
          cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)local_c8);
          if (cVar5 == '\0') {
            pcVar16 = *(code **)(param_1 + 0x60);
            uVar18 = *(undefined8 *)(param_1 + 0x68);
            plVar14 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uVar25 = 0x177;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_98[0] = (longlong *)0x0;
            local_a8 = (undefined1  [16])0x0;
            if (plVar11 != (longlong *)0x0) goto LAB_23e7ca099;
            goto LAB_23e7ca0b9;
          }
          if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
            FUN_23a334bc0(plVar11);
          }
          lVar19 = *plVar10;
          *plVar10 = lVar19 + -1;
          if (lVar19 + -1 == 0) {
            FUN_23a334bc0(plVar10);
          }
          lVar19 = *plVar13;
          goto LAB_23e7c99ea;
        }
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *plVar12 = *plVar12 + 1;
        if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        plVar9 = plVar12;
        plVar11 = plVar12;
        if (plVar1 == (longlong *)0x0) {
          local_a8._8_8_ =
               PyUnicode_FromFormat
                         ("cannot access local variable \'%U\' where it is not associated with a value"
                          ,DAT_23eed80d0);
          local_a8._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
          *(longlong *)local_a8._0_8_ = *(longlong *)local_a8._0_8_ + 1;
          local_98[0] = (longlong *)0x0;
          if ((code *)local_a8._0_8_ != _Py_NoneStruct_exref) {
            FUN_23e91b1b0(param_1,local_a8,local_a8 + 8,local_98);
          }
          uVar25 = 0x179;
          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_a8._8_8_);
          plVar14 = local_98[0];
          pcVar16 = (code *)local_a8._0_8_;
          uVar18 = local_a8._8_8_;
          goto LAB_23e7ca099;
        }
        plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8500);
        if (plVar14 == (longlong *)0x0) {
LAB_23e7caf1d:
          pcVar16 = *(code **)(param_1 + 0x60);
          plVar14 = *(longlong **)(param_1 + 0x70);
          uVar25 = 0x179;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar18 = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e7ca099;
        }
        pcVar23 = (code *)plVar12;
        plVar15 = plVar14;
        if (plVar2 == (longlong *)0x0) {
LAB_23e7cb95e:
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar15);
          }
          local_a8._8_8_ =
               PyUnicode_FromFormat
                         ("cannot access local variable \'%U\' where it is not associated with a value"
                          ,DAT_23eed8508);
          local_a8._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
          *(longlong *)local_a8._0_8_ = *(longlong *)local_a8._0_8_ + 1;
          local_98[0] = (longlong *)0x0;
          if ((code *)local_a8._0_8_ != _Py_NoneStruct_exref) {
            FUN_23e91b1b0(param_1,local_a8,local_a8 + 8,local_98);
          }
          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_a8._8_8_);
          plVar12 = (longlong *)pcVar23;
LAB_23e7cb915:
          uVar25 = 0x17a;
          plVar9 = plVar12;
          plVar14 = local_98[0];
          plVar11 = plVar12;
          pcVar16 = (code *)local_a8._0_8_;
          uVar18 = local_a8._8_8_;
          goto LAB_23e7ca099;
        }
        plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed82c0);
        if (plVar15 == (longlong *)0x0) {
LAB_23e7cae63:
          local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_98[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          uVar25 = 0x17a;
          plVar14 = local_98[0];
          pcVar16 = (code *)local_a8._0_8_;
          uVar18 = local_a8._8_8_;
          goto LAB_23e7ca099;
        }
        pcVar16 = (code *)FUN_23a38cc10(param_1,plVar15,plVar12);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if (pcVar16 == (code *)0x0) goto LAB_23e7cae63;
        plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed82b8);
        if (plVar15 == (longlong *)0x0) {
          local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_98[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
          if (*(longlong *)pcVar16 == 0) {
            (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
          }
          goto LAB_23e7cb915;
        }
        *(undefined4 *)(plVar7 + 5) = 0x179;
        local_88 = plVar2;
        pcStack_80 = pcVar16;
        local_78 = plVar15;
        plVar17 = (longlong *)FUN_23e956150(param_1,plVar14,&local_88);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
        if (*(longlong *)pcVar16 == 0) {
          (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
        }
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if (plVar17 == (longlong *)0x0) goto LAB_23e7caf1d;
        if ((local_128 != (longlong *)0x0) && (*local_128 = *local_128 + -1, *local_128 == 0)) {
          (**(code **)(local_128[1] + 0x30))(local_128);
        }
        iVar6 = FUN_23a35f020(plVar17);
        if (iVar6 == -1) {
          pcVar16 = *(code **)(param_1 + 0x60);
          plVar14 = *(longlong **)(param_1 + 0x70);
          uVar25 = 0x17d;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar18 = *(undefined8 *)(param_1 + 0x68);
          local_128 = plVar17;
          goto LAB_23e7ca099;
        }
        if (iVar6 != 0) {
          uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
          plVar14 = DAT_23eed8510;
          lVar19 = *(longlong *)(param_1 + 0x10);
          plVar15 = *(longlong **)(lVar19 + 0xe38);
          if (plVar15 == (longlong *)0x0) {
            plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
          }
          else {
            lVar3 = plVar15[3];
            *(int *)(lVar19 + 0xec8) = *(int *)(lVar19 + 0xec8) + -1;
            *(longlong *)(lVar19 + 0xe38) = lVar3;
            *plVar15 = 1;
          }
          pcVar16 = _PyRuntime_exref;
          *(undefined1 (*) [16])(plVar15 + 4) = (undefined1  [16])0x0;
          lVar19 = *(longlong *)(pcVar16 + 0x1f8);
          *(undefined1 (*) [16])(plVar15 + 6) = (undefined1  [16])0x0;
          lVar19 = *(longlong *)(*(longlong *)(lVar19 + 0x10) + 0x2e8);
          lVar3 = plVar15[-1];
          puVar4 = *(undefined8 **)(lVar19 + 8);
          *puVar4 = plVar15 + -2;
          plVar15[-2] = lVar19;
          plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
          *(longlong **)(lVar19 + 8) = plVar15 + -2;
          uVar8 = DAT_23eed8308;
          *plVar14 = *plVar14 + 1;
          plVar15[3] = (longlong)plVar14;
          local_128 = (longlong *)FUN_23e8bc2f0(plVar1,uVar8);
          if (local_128 != (longlong *)0x0) {
            plVar14 = (longlong *)FUN_23a38cc10(param_1,local_128,plVar12);
            *local_128 = *local_128 + -1;
            if (*local_128 == 0) {
              (**(code **)(local_128[1] + 0x30))(local_128);
            }
            pcVar16 = DAT_23ed6cd28;
            if (plVar14 != (longlong *)0x0) {
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar20 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar20 != (longlong *)0x0) {
                  *plVar20 = *plVar20 + 1;
                  DAT_23ed6a4c0 = plVar20;
                  goto LAB_23e7ca203;
                }
LAB_23e7cb94b:
                PyErr_PrintEx(0);
                plVar14 = (longlong *)Py_Exit(1);
                goto LAB_23e7cb95e;
              }
LAB_23e7ca203:
              pcStack_80 = pcVar16;
              local_88 = plVar14;
              lVar19 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (lVar19 != 0) {
                plVar15[4] = lVar19;
                plVar14 = DAT_23eed8518;
                *DAT_23eed8518 = *DAT_23eed8518 + 1;
                plVar15[5] = (longlong)plVar14;
                plVar14 = (longlong *)FUN_23e8bd600(param_1,plVar17);
                pcVar16 = DAT_23ed6cd28;
                if (plVar14 != (longlong *)0x0) {
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar20 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar20 == (longlong *)0x0) goto LAB_23e7cb94b;
                    *plVar20 = *plVar20 + 1;
                    DAT_23ed6a4c0 = plVar20;
                  }
                  pcStack_80 = pcVar16;
                  local_88 = plVar14;
                  lVar19 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (lVar19 != 0) {
                    plVar15[6] = lVar19;
                    plVar14 = DAT_23eed8520;
                    *DAT_23eed8520 = *DAT_23eed8520 + 1;
                    plVar15[7] = (longlong)plVar14;
                    plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    if (plVar14 != (longlong *)0x0) {
                      *(undefined4 *)(plVar7 + 5) = 0x17e;
                      plVar15 = (longlong *)FUN_23e914090(param_1,uVar18,plVar14);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if (plVar15 != (longlong *)0x0) {
                        *plVar15 = *plVar15 + -1;
                        if (*plVar15 == 0) {
                          (**(code **)(plVar15[1] + 0x30))(plVar15);
                        }
                        pcVar16 = PyEnum_Type_exref;
                        pcStack_80 = DAT_23ed6ccf8;
                        *(undefined4 *)(plVar7 + 5) = 0x181;
                        local_88 = plVar17;
                        plVar14 = (longlong *)FUN_23e94ed00(param_1,pcVar16);
                        if (plVar14 != (longlong *)0x0) {
                          plVar20 = (longlong *)FUN_23ebf7180(plVar14);
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                          }
                          if (plVar20 != (longlong *)0x0) {
                            local_b8 = (longlong *)0x0;
LAB_23e7ca3eb:
                            pcVar16 = *(code **)(plVar20[1] + 0xe0);
                            local_d0 = local_110;
                            if (pcVar16 != (code *)0x0) {
                              plVar14 = (longlong *)(*pcVar16)(plVar20);
                              if (plVar14 == (longlong *)0x0) goto LAB_23e7cb08f;
                              if ((local_b8 != (longlong *)0x0) &&
                                 (*local_b8 = *local_b8 + -1, *local_b8 == 0)) {
                                (**(code **)(local_b8[1] + 0x30))(local_b8);
                              }
                              plVar15 = (longlong *)FUN_23a388310(plVar14);
                              local_b8 = plVar14;
                              if (plVar15 == (longlong *)0x0) {
                                pcVar16 = *(code **)(param_1 + 0x60);
                                uVar18 = *(undefined8 *)(param_1 + 0x68);
                                plVar14 = *(longlong **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23e7cb3da:
                                uVar25 = 0x181;
                                local_c0 = local_f8;
                                local_c8 = (code *)local_108;
                              }
                              else {
                                local_128 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                                if ((local_128 == (longlong *)0x0) &&
                                   (local_128 = (longlong *)FUN_23a3c1b70(param_1,local_a8,0,2),
                                   plVar14 = local_98[0], local_128 == (longlong *)0x0)) {
                                  pcVar16 = (code *)local_a8._0_8_;
                                  uVar18 = local_a8._8_8_;
                                  local_a8 = (undefined1  [16])0x0;
                                  local_98[0] = (longlong *)0x0;
                                  *plVar15 = *plVar15 + -1;
                                  if (*plVar15 == 0) {
                                    FUN_23a334bc0(plVar15);
                                  }
                                  goto LAB_23e7cb3da;
                                }
                                plVar21 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                                if ((plVar21 == (longlong *)0x0) &&
                                   (plVar21 = (longlong *)FUN_23a3c1b70(param_1,local_a8,1,2),
                                   plVar21 == (longlong *)0x0)) {
                                  lVar19 = *plVar15;
LAB_23e7cb57a:
                                  plVar14 = local_98[0];
                                  pcVar16 = (code *)local_a8._0_8_;
                                  uVar18 = local_a8._8_8_;
                                  local_a8 = (undefined1  [16])0x0;
                                  local_98[0] = (longlong *)0x0;
                                  *plVar15 = lVar19 + -1;
                                  if (lVar19 + -1 == 0) {
                                    FUN_23a334bc0(plVar15);
                                  }
                                  local_98[0] = (longlong *)0x0;
                                  local_a8 = (undefined1  [16])0x0;
                                  lVar19 = *local_128;
                                  *local_128 = lVar19 + -1;
                                  if (lVar19 + -1 == 0) {
                                    (**(code **)(local_128[1] + 0x30))(local_128);
                                  }
                                  if (plVar21 != (longlong *)0x0) {
LAB_23e7cb3ac:
                                    lVar19 = *plVar21;
                                    *plVar21 = lVar19 + -1;
                                    if (lVar19 + -1 == 0) {
                                      (**(code **)(plVar21[1] + 0x30))(plVar21);
                                    }
                                  }
                                  goto LAB_23e7cb3da;
                                }
                                cVar5 = FUN_23a3884a0(param_1,local_a8,plVar15,2);
                                lVar19 = *plVar15;
                                if (cVar5 == '\0') goto LAB_23e7cb57a;
                                *plVar15 = lVar19 + -1;
                                if (lVar19 + -1 == 0) {
                                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                                }
                                lVar19 = *local_128;
                                *local_128 = lVar19 + 1;
                                if (local_110 != (longlong *)0x0) {
                                  *local_110 = *local_110 + -1;
                                  if (*local_110 == 0) {
                                    (**(code **)(local_110[1] + 0x30))(local_110);
                                  }
                                  lVar19 = *local_128 + -1;
                                }
                                *local_128 = lVar19;
                                if (lVar19 == 0) {
                                  (**(code **)(local_128[1] + 0x30))(local_128);
                                }
                                plVar22 = (longlong *)FUN_23a388310(plVar21);
                                local_d0 = local_128;
                                if (plVar22 == (longlong *)0x0) {
                                  pcVar16 = *(code **)(param_1 + 0x60);
                                  uVar18 = *(undefined8 *)(param_1 + 0x68);
                                  plVar14 = *(longlong **)(param_1 + 0x70);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23e7cb394:
                                  local_98[0] = (longlong *)0x0;
                                  local_a8 = (undefined1  [16])0x0;
                                  goto LAB_23e7cb3ac;
                                }
                                pcVar23 = (code *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
                                if ((pcVar23 == (code *)0x0) &&
                                   (pcVar23 = (code *)FUN_23a3c1b70(param_1,local_a8,0,3),
                                   pcVar23 == (code *)0x0)) {
                                  plVar15 = (longlong *)0x0;
                                  local_c0 = (longlong *)0x0;
                                  lVar19 = *plVar22;
LAB_23e7cb294:
                                  local_c8 = pcVar23;
                                  plVar14 = local_98[0];
                                  pcVar16 = (code *)local_a8._0_8_;
                                  uVar18 = local_a8._8_8_;
                                  local_a8 = (undefined1  [16])0x0;
                                  local_98[0] = (longlong *)0x0;
                                  *plVar22 = lVar19 + -1;
                                  if (lVar19 + -1 == 0) {
                                    (**(code **)(plVar22[1] + 0x30))(plVar22);
                                  }
                                  local_98[0] = (longlong *)0x0;
                                  local_a8 = (undefined1  [16])0x0;
                                  if ((local_c8 != (code *)0x0) &&
                                     (lVar19 = *(longlong *)local_c8,
                                     *(longlong *)local_c8 = lVar19 + -1, lVar19 + -1 == 0)) {
                                    (**(code **)(*(longlong *)((longlong)local_c8 + 8) + 0x30))
                                              (local_c8);
                                  }
                                  if ((plVar15 != (longlong *)0x0) &&
                                     (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                                  }
                                  if ((local_c0 != (longlong *)0x0) &&
                                     (lVar19 = *local_c0, *local_c0 = lVar19 + -1, lVar19 + -1 == 0)
                                     ) {
                                    (**(code **)(local_c0[1] + 0x30))(local_c0);
                                  }
                                  goto LAB_23e7cb394;
                                }
                                plVar15 = (longlong *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
                                if ((plVar15 == (longlong *)0x0) &&
                                   (plVar15 = (longlong *)FUN_23a3c1b70(param_1,local_a8,1,3),
                                   plVar15 == (longlong *)0x0)) {
                                  local_c0 = (longlong *)0x0;
                                  lVar19 = *plVar22;
                                  goto LAB_23e7cb294;
                                }
                                local_c0 = (longlong *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
                                if ((local_c0 == (longlong *)0x0) &&
                                   (local_c0 = (longlong *)FUN_23a3c1b70(param_1,local_a8,2,3),
                                   local_c0 == (longlong *)0x0)) {
                                  lVar19 = *plVar22;
                                  goto LAB_23e7cb294;
                                }
                                cVar5 = FUN_23a3884a0(param_1,local_a8,plVar22);
                                lVar19 = *plVar22;
                                if (cVar5 == '\0') goto LAB_23e7cb294;
                                *plVar22 = lVar19 + -1;
                                if (lVar19 + -1 == 0) {
                                  (**(code **)(plVar22[1] + 0x30))(plVar22);
                                }
                                lVar19 = *(longlong *)pcVar23;
                                *(longlong *)pcVar23 = lVar19 + 1;
                                if (local_108 != (longlong *)0x0) {
                                  lVar19 = *local_108;
                                  *local_108 = lVar19 + -1;
                                  if (lVar19 + -1 == 0) {
                                    (**(code **)(local_108[1] + 0x30))(local_108);
                                  }
                                  lVar19 = *(longlong *)pcVar23 + -1;
                                }
                                *(longlong *)pcVar23 = lVar19;
                                if (lVar19 == 0) {
                                  (**(code **)(*(longlong *)((longlong)pcVar23 + 8) + 0x30))
                                            (pcVar23);
                                }
                                lVar19 = *plVar15;
                                *plVar15 = lVar19 + 1;
                                if (local_100 != (longlong *)0x0) {
                                  lVar19 = *local_100;
                                  *local_100 = lVar19 + -1;
                                  if (lVar19 + -1 == 0) {
                                    (**(code **)(local_100[1] + 0x30))(local_100);
                                  }
                                  lVar19 = *plVar15 + -1;
                                }
                                *plVar15 = lVar19;
                                if (lVar19 == 0) {
                                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                                }
                                lVar19 = *local_c0;
                                *local_c0 = lVar19 + 1;
                                if (local_f8 != (longlong *)0x0) {
                                  lVar19 = *local_f8;
                                  *local_f8 = lVar19 + -1;
                                  if (lVar19 + -1 == 0) {
                                    (**(code **)(local_f8[1] + 0x30))(local_f8);
                                  }
                                  lVar19 = *local_c0 + -1;
                                }
                                *local_c0 = lVar19;
                                if (lVar19 == 0) {
                                  (**(code **)(local_c0[1] + 0x30))(local_c0);
                                }
                                *plVar21 = *plVar21 + -1;
                                if (*plVar21 == 0) {
                                  (**(code **)(plVar21[1] + 0x30))(plVar21);
                                }
                                uVar18 = DAT_23eed8528;
                                plVar21 = (longlong *)_PyDict_NewPresized(6);
                                PyDict_SetItem(plVar21,uVar18,plVar12);
                                plVar14 = DAT_23ed6ce48;
                                local_110 = DAT_23ed6ce48;
                                local_108 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8308);
                                if (local_108 == (longlong *)0x0) {
LAB_23e7cbc9d:
                                  plVar14 = *(longlong **)(param_1 + 0x70);
                                  pcVar16 = *(code **)(param_1 + 0x60);
                                  uVar18 = *(undefined8 *)(param_1 + 0x68);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  lVar19 = *plVar21;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *plVar21 = lVar19 + -1;
                                  if (lVar19 + -1 == 0) {
                                    uVar25 = 0x184;
                                    local_98[0] = plVar14;
                                    local_a8._0_8_ = pcVar16;
                                    local_a8._8_8_ = uVar18;
                                    FUN_23a334bc0(plVar21);
                                    local_100 = plVar15;
                                    plVar14 = local_98[0];
                                    pcVar16 = (code *)local_a8._0_8_;
                                    uVar18 = local_a8._8_8_;
                                    local_c8 = pcVar23;
                                  }
                                  else {
                                    uVar25 = 0x184;
                                    local_100 = plVar15;
                                    local_c8 = pcVar23;
                                  }
                                }
                                else {
                                  plVar22 = (longlong *)FUN_23a38cc10(param_1,local_108,plVar12);
                                  *local_108 = *local_108 + -1;
                                  if (*local_108 == 0) {
                                    (**(code **)(local_108[1] + 0x30))(local_108);
                                  }
                                  if (plVar22 == (longlong *)0x0) goto LAB_23e7cbc9d;
                                  PyDict_SetItem(plVar21,plVar14,plVar22);
                                  *plVar22 = *plVar22 + -1;
                                  if (*plVar22 == 0) {
                                    (**(code **)(plVar22[1] + 0x30))(plVar22);
                                  }
                                  PyDict_SetItem(plVar21,DAT_23eed8338,pcVar23);
                                  PyDict_SetItem(plVar21,DAT_23eed8410,plVar15);
                                  PyDict_SetItem(plVar21,DAT_23eed8530,local_c0);
                                  PyDict_SetItem(plVar21,DAT_23eed8538,local_128);
                                  if ((local_118 != (longlong *)0x0) &&
                                     (lVar19 = *local_118, *local_118 = lVar19 + -1,
                                     lVar19 + -1 == 0)) {
                                    (**(code **)(local_118[1] + 0x30))(local_118);
                                  }
                                  plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eed8108);
                                  if (plVar14 == (longlong *)0x0) {
LAB_23e7cbc1e:
                                    pcVar16 = *(code **)(param_1 + 0x60);
                                    plVar14 = *(longlong **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    uVar25 = 0x18a;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    local_100 = plVar15;
                                    uVar18 = *(undefined8 *)(param_1 + 0x68);
                                    local_118 = plVar21;
                                    local_c8 = pcVar23;
                                  }
                                  else {
                                    *(undefined4 *)(plVar7 + 5) = 0x18a;
                                    plVar22 = (longlong *)FUN_23e914090(param_1,plVar14,plVar21);
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                                    }
                                    if (plVar22 == (longlong *)0x0) goto LAB_23e7cbc1e;
                                    *plVar22 = *plVar22 + -1;
                                    if (*plVar22 == 0) {
                                      (**(code **)(plVar22[1] + 0x30))(plVar22);
                                    }
                                    local_118 = (longlong *)FUN_23a3a0d40(DAT_23ed6cf28);
                                    plVar22 = DAT_23eed8548;
                                    lVar19 = *(longlong *)(param_1 + 0x10);
                                    plVar14 = *(longlong **)(lVar19 + 0xe58);
                                    if (plVar14 == (longlong *)0x0) {
                                      local_110 = DAT_23eed8548;
                                      plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,9);
                                    }
                                    else {
                                      lVar3 = plVar14[3];
                                      *(int *)(lVar19 + 0xed8) = *(int *)(lVar19 + 0xed8) + -1;
                                      *(longlong *)(lVar19 + 0xe58) = lVar3;
                                      *plVar14 = 1;
                                    }
                                    pcVar16 = _PyRuntime_exref;
                                    *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
                                    lVar19 = *(longlong *)(pcVar16 + 0x1f8);
                                    *(undefined1 (*) [16])(plVar14 + 6) = (undefined1  [16])0x0;
                                    *(undefined1 (*) [16])(plVar14 + 8) = (undefined1  [16])0x0;
                                    lVar19 = *(longlong *)(lVar19 + 0x10);
                                    *(undefined1 (*) [16])(plVar14 + 10) = (undefined1  [16])0x0;
                                    lVar19 = *(longlong *)(lVar19 + 0x2e8);
                                    lVar3 = plVar14[-1];
                                    puVar4 = *(undefined8 **)(lVar19 + 8);
                                    *puVar4 = plVar14 + -2;
                                    plVar14[-2] = lVar19;
                                    plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
                                    *(longlong **)(lVar19 + 8) = plVar14 + -2;
                                    plVar24 = DAT_23ed6a4c0;
                                    *plVar22 = *plVar22 + 1;
                                    plVar14[3] = (longlong)plVar22;
                                    pcVar16 = DAT_23ed6cd28;
                                    if (plVar24 == (longlong *)0x0) {
                                      plVar24 = (longlong *)
                                                PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                      if (plVar24 == (longlong *)0x0) goto LAB_23e7cb94b;
                                      *plVar24 = *plVar24 + 1;
                                      DAT_23ed6a4c0 = plVar24;
                                    }
                                    pcStack_80 = pcVar16;
                                    local_88 = local_128;
                                    lVar19 = FUN_23e94ed00(param_1,plVar24,&local_88);
                                    if (lVar19 == 0) {
LAB_23e7cb6d0:
                                      local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      local_98[0] = *(longlong **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        FUN_23a334bc0(plVar14);
                                      }
                                      uVar25 = 0x18b;
                                      local_100 = plVar15;
                                      plVar14 = local_98[0];
                                      pcVar16 = (code *)local_a8._0_8_;
                                      uVar18 = local_a8._8_8_;
                                      local_118 = plVar21;
                                      local_c8 = pcVar23;
                                    }
                                    else {
                                      plVar14[4] = lVar19;
                                      plVar22 = DAT_23eed8550;
                                      *DAT_23eed8550 = *DAT_23eed8550 + 1;
                                      plVar14[5] = (longlong)plVar22;
                                      pcVar16 = DAT_23ed6cd28;
                                      if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                        plVar22 = (longlong *)
                                                  PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                        if (plVar22 == (longlong *)0x0) goto LAB_23e7cb94b;
                                        *plVar22 = *plVar22 + 1;
                                        DAT_23ed6a4c0 = plVar22;
                                      }
                                      pcStack_80 = pcVar16;
                                      local_88 = (longlong *)pcVar23;
                                      lVar19 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                                      if (lVar19 == 0) goto LAB_23e7cb6d0;
                                      plVar14[6] = lVar19;
                                      plVar22 = DAT_23eed8558;
                                      *DAT_23eed8558 = *DAT_23eed8558 + 1;
                                      plVar14[7] = (longlong)plVar22;
                                      pcVar16 = DAT_23ed6cd28;
                                      if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                        plVar22 = (longlong *)
                                                  PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                        if (plVar22 == (longlong *)0x0) goto LAB_23e7cb94b;
                                        *plVar22 = *plVar22 + 1;
                                        DAT_23ed6a4c0 = plVar22;
                                      }
                                      pcStack_80 = pcVar16;
                                      local_88 = plVar15;
                                      lVar19 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                                      if (lVar19 == 0) goto LAB_23e7cb6d0;
                                      plVar14[8] = lVar19;
                                      pcVar16 = DAT_23eed8568;
                                      plVar22 = DAT_23eed8560;
                                      *DAT_23eed8560 = *DAT_23eed8560 + 1;
                                      plVar14[9] = (longlong)plVar22;
                                      if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                        plVar22 = (longlong *)
                                                  PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                        if (plVar22 == (longlong *)0x0) goto LAB_23e7cb94b;
                                        *plVar22 = *plVar22 + 1;
                                        DAT_23ed6a4c0 = plVar22;
                                      }
                                      pcStack_80 = pcVar16;
                                      local_88 = local_c0;
                                      lVar19 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                                      if (lVar19 == 0) goto LAB_23e7cb6d0;
                                      plVar14[10] = lVar19;
                                      plVar22 = DAT_23eed8570;
                                      pcVar16 = DAT_23ed6cd28;
                                      *DAT_23eed8570 = *DAT_23eed8570 + 1;
                                      plVar14[0xb] = (longlong)plVar22;
                                      plVar22 = (longlong *)PyUnicode_Join(pcVar16,plVar14);
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                                      }
                                      if (plVar22 == (longlong *)0x0) {
                                        pcVar16 = *(code **)(param_1 + 0x60);
                                        plVar14 = *(longlong **)(param_1 + 0x70);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        uVar25 = 0x18b;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        local_100 = plVar15;
                                        uVar18 = *(undefined8 *)(param_1 + 0x68);
                                        local_118 = plVar21;
                                        local_c8 = pcVar23;
                                      }
                                      else {
                                        *(undefined4 *)(plVar7 + 5) = 0x18b;
                                        plVar14 = (longlong *)FUN_23e914090();
                                        *plVar22 = *plVar22 + -1;
                                        if (*plVar22 == 0) {
                                          (**(code **)(plVar22[1] + 0x30))();
                                        }
                                        if (plVar14 != (longlong *)0x0) {
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                                          }
                                          lVar19 = *(longlong *)(param_1 + 0x10);
                                          if ((((*(int *)(*(longlong *)(lVar19 + 0x28) + 0x160) == 0
                                                ) && (*(int *)(lVar19 + 0x78) == 0)) ||
                                              (iVar6 = Py_MakePendingCalls(), -1 < iVar6)) ||
                                             (*(longlong *)(param_1 + 0x60) == 0))
                                          goto LAB_23e7caaf9;
                                          goto LAB_23e7cace9;
                                        }
                                        pcVar16 = *(code **)(param_1 + 0x60);
                                        plVar14 = *(longlong **)(param_1 + 0x70);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        uVar25 = 0x18b;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        local_100 = plVar15;
                                        uVar18 = *(undefined8 *)(param_1 + 0x68);
                                        local_118 = plVar21;
                                        local_c8 = pcVar23;
                                      }
                                    }
                                  }
                                }
                              }
                              goto LAB_23e7cad28;
                            }
                            PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                                         "\'%s\' object is not an iterator",
                                         *(undefined8 *)(plVar20[1] + 0x18));
LAB_23e7cb08f:
                            cVar5 = FUN_23a3591a0();
                            if (cVar5 == '\0') goto LAB_23e7cbfe8;
                            if ((local_b8 != (longlong *)0x0) &&
                               (*local_b8 = *local_b8 + -1, *local_b8 == 0)) {
                              FUN_23a334bc0(local_b8);
                            }
                            lVar19 = *plVar20;
                            *plVar20 = lVar19 + -1;
                            if (lVar19 + -1 == 0) {
                              FUN_23a334bc0(plVar20);
                            }
                            goto LAB_23e7c9f13;
                          }
                        }
                        pcVar16 = *(code **)(param_1 + 0x60);
                        plVar14 = *(longlong **)(param_1 + 0x70);
                        uVar25 = 0x181;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        uVar18 = *(undefined8 *)(param_1 + 0x68);
                        local_128 = plVar17;
                        goto LAB_23e7ca099;
                      }
                    }
                    pcVar16 = *(code **)(param_1 + 0x60);
                    plVar14 = *(longlong **)(param_1 + 0x70);
                    uVar25 = 0x17e;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar18 = *(undefined8 *)(param_1 + 0x68);
                    local_128 = plVar17;
                    goto LAB_23e7ca099;
                  }
                }
              }
            }
          }
          local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_98[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            uVar25 = 0x17e;
            FUN_23a334bc0(plVar15);
            plVar14 = local_98[0];
            pcVar16 = (code *)local_a8._0_8_;
            uVar18 = local_a8._8_8_;
            local_128 = plVar17;
          }
          else {
            uVar25 = 0x17e;
            plVar14 = local_98[0];
            pcVar16 = (code *)local_a8._0_8_;
            uVar18 = local_a8._8_8_;
            local_128 = plVar17;
          }
          goto LAB_23e7ca099;
        }
LAB_23e7c9f13:
        lVar19 = *(longlong *)(param_1 + 0x10);
        if ((((*(int *)(*(longlong *)(lVar19 + 0x28) + 0x160) != 0) ||
             (*(int *)(lVar19 + 0x78) != 0)) && (iVar6 = Py_MakePendingCalls(), iVar6 < 0)) &&
           (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e7ca064;
        if (*(int *)(lVar19 + 0x68) == 0) {
          plVar12 = *(longlong **)(param_1 + 0x90);
        }
        else {
          PyEval_SaveThread();
          PyEval_AcquireThread(param_1);
          plVar12 = *(longlong **)(param_1 + 0x90);
        }
        local_128 = plVar17;
      } while (plVar12 == (longlong *)0x0);
      plVar14 = *(longlong **)(param_1 + 0x60);
      plVar15 = *(longlong **)(param_1 + 0x68);
      plVar20 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar12;
      *(undefined8 *)(param_1 + 0x90) = 0;
      *plVar12 = *plVar12 + 1;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
        (**(code **)(plVar20[1] + 0x30))(plVar20);
      }
LAB_23e7ca064:
      plVar14 = *(longlong **)(param_1 + 0x70);
      pcVar16 = *(code **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar25 = 0x177;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar18 = *(undefined8 *)(param_1 + 0x68);
      local_128 = plVar17;
      goto LAB_23e7ca099;
    }
    local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar25 = 0x173;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    plVar12 = (longlong *)0x0;
    do {
      plVar9 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
      if (plVar9 == (longlong *)0x0) {
        local_c8 = PyExc_StopIteration_exref;
        cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
        if (cVar5 == '\0') {
          plVar11 = *(longlong **)(param_1 + 0x70);
          pcVar16 = *(code **)(param_1 + 0x60);
          uVar18 = *(undefined8 *)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (plVar12 != (longlong *)0x0) goto LAB_23e7c914b;
          goto LAB_23e7c9f9b;
        }
        if (plVar12 == (longlong *)0x0) goto LAB_23e7cb108;
        *plVar12 = *plVar12 + -1;
        plVar9 = plVar12;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        goto LAB_23e7c991c;
      }
      if (plVar12 == (longlong *)0x0) {
        *plVar9 = *plVar9 + 1;
      }
      else {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar9 = *plVar9 + 1;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
      }
      plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed82e8);
      if (plVar11 == (longlong *)0x0) {
LAB_23e7c9648:
        local_98[0] = *(longlong **)(param_1 + 0x70);
        local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar9 = *plVar9 + -1;
        lVar19 = *plVar9;
joined_r0x00023e7c967e:
        uVar25 = 0x170;
        plVar11 = local_98[0];
        pcVar16 = (code *)local_a8._0_8_;
        uVar18 = local_a8._8_8_;
        goto joined_r0x00023e7c967e;
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6ce40);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar12 == (longlong *)0x0) goto LAB_23e7c9648;
      *(undefined4 *)(plVar7 + 5) = 0x170;
      pcStack_80 = _Py_FalseStruct_exref;
      local_88 = plVar9;
      plVar11 = (longlong *)FUN_23e94ed00(param_1,plVar12,&local_88);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar11 == (longlong *)0x0) goto LAB_23e7c9648;
      iVar6 = FUN_23a35f020(plVar11);
      lVar19 = *plVar11 + -1;
      if (iVar6 == -1) {
        local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
        local_98[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar11 = lVar19;
        if (lVar19 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *plVar9 = *plVar9 + -1;
        lVar19 = *plVar9;
        goto joined_r0x00023e7c967e;
      }
      *plVar11 = lVar19;
      if (lVar19 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (iVar6 != 0) {
        FUN_23e8bc550(local_130,plVar9);
      }
      lVar19 = *(longlong *)(param_1 + 0x10);
      plVar12 = plVar9;
      if ((((*(int *)(*(longlong *)(lVar19 + 0x28) + 0x160) != 0) || (*(int *)(lVar19 + 0x78) != 0))
          && (iVar6 = Py_MakePendingCalls(), iVar6 < 0)) &&
         (pcVar16 = *(code **)(param_1 + 0x60), pcVar16 != (code *)0x0)) goto LAB_23e7c9115;
      if (*(int *)(lVar19 + 0x68) == 0) {
        plVar9 = *(longlong **)(param_1 + 0x90);
      }
      else {
        PyEval_SaveThread();
        PyEval_AcquireThread(param_1);
        plVar9 = *(longlong **)(param_1 + 0x90);
      }
    } while (plVar9 == (longlong *)0x0);
    plVar11 = *(longlong **)(param_1 + 0x60);
    plVar14 = *(longlong **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x90) = 0;
    plVar15 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar9;
    *plVar9 = *plVar9 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))();
    }
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    pcVar16 = *(code **)(param_1 + 0x60);
LAB_23e7c9115:
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7c914b:
    uVar25 = 0x16f;
    *plVar12 = *plVar12 + -1;
    lVar19 = *plVar12;
    plVar9 = plVar12;
joined_r0x00023e7c967e:
    local_a8 = (undefined1  [16])0x0;
    local_98[0] = (longlong *)0x0;
    if (lVar19 == 0) {
      local_98[0] = (longlong *)0x0;
      local_a8 = (undefined1  [16])0x0;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
LAB_23e7c917a:
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    local_a8._8_8_ = uVar18;
    local_a8._0_8_ = pcVar16;
  }
  local_118 = (longlong *)0x0;
  local_f8 = (longlong *)0x0;
  local_100 = (longlong *)0x0;
  local_108 = (longlong *)0x0;
  local_110 = (longlong *)0x0;
  local_128 = (longlong *)0x0;
  local_98[0] = plVar11;
LAB_23e7c91dc:
  plVar11 = local_98[0];
  plVar10 = DAT_23ed6a4f8;
  if (local_98[0] == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar11 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar11;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar16 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar19 = *(longlong *)(pcVar16 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar19 = *(longlong *)(lVar19 + 0x10);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar25;
    lVar19 = *(longlong *)(lVar19 + 0x2e8);
    lVar3 = plVar10[-1];
    puVar4 = *(undefined8 **)(lVar19 + 8);
    *puVar4 = plVar10 + -2;
    plVar10[-2] = lVar19;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar19 + 8) = plVar10 + -2;
    plVar11 = plVar10;
    if ((local_98[0] != (longlong *)0x0) && (*local_98[0] = *local_98[0] + -1, *local_98[0] == 0)) {
      (**(code **)(local_98[0][1] + 0x30))(local_98[0]);
    }
  }
  else if ((longlong *)local_98[0][3] != plVar7) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar12 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar16 = _PyRuntime_exref;
    plVar10[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar19 = *(longlong *)(pcVar16 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar25;
    lVar19 = *(longlong *)(*(longlong *)(lVar19 + 0x10) + 0x2e8);
    lVar3 = plVar10[-1];
    puVar4 = *(undefined8 **)(lVar19 + 8);
    *puVar4 = plVar10 + -2;
    plVar10[-2] = lVar19;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar19 + 8) = plVar10 + -2;
    plVar10[2] = (longlong)plVar11;
    *plVar11 = *plVar11 + 1;
    plVar11 = plVar10;
    if ((local_98[0] != (longlong *)0x0) && (*local_98[0] = *local_98[0] + -1, *local_98[0] == 0)) {
      (**(code **)(local_98[0][1] + 0x30))();
    }
  }
  local_98[0] = plVar11;
  FUN_23e8bba40(plVar7,"ooooooooooo",plVar1,plVar2,plVar13,local_130,plVar9,local_128,local_110,
                local_108,local_100,local_f8,local_118);
  if (DAT_23eedabf0 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    DAT_23eedabf0 = (longlong *)0x0;
  }
  lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar19 + 0x28);
  plVar10 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar19 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
    plVar7[0xf] = 0;
    plVar7 = local_98[0];
    uVar18 = local_a8._0_8_;
    uVar8 = local_a8._8_8_;
  }
  else {
    plVar7[0xf] = 0;
    plVar7 = local_98[0];
    uVar18 = local_a8._0_8_;
    uVar8 = local_a8._8_8_;
  }
  local_98[0] = (longlong *)0x0;
  local_a8 = (undefined1  [16])0x0;
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((local_130 != (longlong *)0x0) &&
     (lVar19 = *local_130, *local_130 = lVar19 + -1, lVar19 + -1 == 0)) {
    (**(code **)(local_130[1] + 0x30))();
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((local_128 != (longlong *)0x0) &&
     (lVar19 = *local_128, *local_128 = lVar19 + -1, lVar19 + -1 == 0)) {
    (**(code **)(local_128[1] + 0x30))(local_128);
  }
  if ((local_110 != (longlong *)0x0) &&
     (lVar19 = *local_110, *local_110 = lVar19 + -1, lVar19 + -1 == 0)) {
    (**(code **)(local_110[1] + 0x30))(local_110);
  }
  if ((local_108 != (longlong *)0x0) &&
     (lVar19 = *local_108, *local_108 = lVar19 + -1, lVar19 + -1 == 0)) {
    (**(code **)(local_108[1] + 0x30))(local_108);
  }
  if ((local_100 != (longlong *)0x0) &&
     (lVar19 = *local_100, *local_100 = lVar19 + -1, lVar19 + -1 == 0)) {
    (**(code **)(local_100[1] + 0x30))(local_100);
  }
  if ((local_f8 != (longlong *)0x0) &&
     (lVar19 = *local_f8, *local_f8 = lVar19 + -1, lVar19 + -1 == 0)) {
    (**(code **)(local_f8[1] + 0x30))(local_f8);
  }
  if ((local_118 != (longlong *)0x0) &&
     (lVar19 = *local_118, *local_118 = lVar19 + -1, lVar19 + -1 == 0)) {
    (**(code **)(local_118[1] + 0x30))(local_118);
  }
  local_a8._8_8_ = uVar8;
  local_a8._0_8_ = uVar18;
  lVar19 = *plVar1;
  *plVar1 = lVar19 + -1;
  local_98[0] = plVar7;
  if (lVar19 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar19 = *plVar2;
  *plVar2 = lVar19 + -1;
  if (lVar19 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_a8._0_8_,local_a8._8_8_,local_98[0]);
  return (longlong *)0x0;
LAB_23e7caaf9:
  if (*(int *)(lVar19 + 0x68) == 0) {
    plVar14 = *(longlong **)(param_1 + 0x90);
  }
  else {
    PyEval_SaveThread();
    PyEval_AcquireThread(param_1);
    plVar14 = *(longlong **)(param_1 + 0x90);
  }
  local_110 = local_128;
  local_118 = plVar21;
  local_108 = (longlong *)pcVar23;
  local_100 = plVar15;
  local_f8 = local_c0;
  if (plVar14 != (longlong *)0x0) {
    plVar12 = *(longlong **)(param_1 + 0x60);
    plVar22 = *(longlong **)(param_1 + 0x68);
    plVar24 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar14;
    *(undefined8 *)(param_1 + 0x90) = 0;
    *plVar14 = *plVar14 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
      (**(code **)(plVar22[1] + 0x30))(plVar22);
    }
    if ((plVar24 != (longlong *)0x0) && (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
      (**(code **)(plVar24[1] + 0x30))(plVar24);
    }
LAB_23e7cace9:
    plVar14 = *(longlong **)(param_1 + 0x70);
    pcVar16 = *(code **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar25 = 0x181;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    local_100 = plVar15;
    uVar18 = *(undefined8 *)(param_1 + 0x68);
    local_118 = plVar21;
    local_c8 = pcVar23;
    goto LAB_23e7cad28;
  }
  goto LAB_23e7ca3eb;
LAB_23e7cbfe8:
  pcVar16 = *(code **)(param_1 + 0x60);
  uVar18 = *(undefined8 *)(param_1 + 0x68);
  plVar14 = *(longlong **)(param_1 + 0x70);
  local_98[0] = (longlong *)0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  if (local_b8 == (longlong *)0x0) {
    uVar25 = 0x181;
  }
  else {
    uVar25 = 0x181;
    local_c0 = local_f8;
    local_c8 = (code *)local_108;
LAB_23e7cad28:
    local_98[0] = (longlong *)0x0;
    local_a8 = (undefined1  [16])0x0;
    lVar19 = *local_b8;
    *local_b8 = lVar19 + -1;
    if (lVar19 + -1 == 0) {
      (**(code **)(local_b8[1] + 0x30))(local_b8);
    }
    local_f8 = local_c0;
    local_108 = (longlong *)local_c8;
    local_110 = local_d0;
  }
  lVar19 = *plVar20;
  *plVar20 = lVar19 + -1;
  local_128 = plVar17;
  if (lVar19 + -1 == 0) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
LAB_23e7ca099:
  local_98[0] = (longlong *)0x0;
  local_a8 = (undefined1  [16])0x0;
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
LAB_23e7ca0b9:
  lVar19 = *plVar10;
  *plVar10 = lVar19 + -1;
  if (lVar19 + -1 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  local_a8._8_8_ = uVar18;
  local_a8._0_8_ = pcVar16;
  local_98[0] = plVar14;
  goto LAB_23e7c91dc;
}
