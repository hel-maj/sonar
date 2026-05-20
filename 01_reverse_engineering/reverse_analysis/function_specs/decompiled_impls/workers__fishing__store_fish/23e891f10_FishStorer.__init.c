/* ===== 23e891f10 workers.fishing.store_fish:288 ===== */
/* ghidra_name=FUN_23e891f10 entry=23e891f10 size=7486 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e891f10(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  char cVar6;
  int iVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong lVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong *plVar21;
  code *pcVar22;
  undefined4 uVar23;
  longlong **pplVar24;
  undefined8 uVar25;
  longlong *local_100;
  longlong *local_f0;
  longlong *local_e8;
  longlong *local_c0;
  longlong *local_b8;
  undefined1 local_a8 [16];
  longlong *local_98 [2];
  longlong *local_88;
  longlong *plStack_80;
  longlong *local_78;
  
  plVar1 = (longlong *)*param_3;
  lVar18 = *(longlong *)(param_1 + 0x10);
  plVar2 = (longlong *)param_3[1];
  local_98[0] = (longlong *)0x0;
  local_a8 = (undefined1  [16])0x0;
  if (*(int *)(lVar18 + 0x1188) == 0) {
    plVar20 = (longlong *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    iVar7 = *(int *)(lVar18 + 0x1188) + -1;
    *(int *)(lVar18 + 0x1188) = iVar7;
    plVar20 = *(longlong **)(lVar18 + 0xf08 + (longlong)iVar7 * 8);
    *plVar20 = 1;
  }
  pcVar22 = _PyRuntime_exref;
  plVar20[2] = 0;
  plVar20[4] = 0;
  lVar18 = *(longlong *)(pcVar22 + 0x1f8);
  plVar20[3] = 0;
  lVar18 = *(longlong *)(*(longlong *)(lVar18 + 0x10) + 0x2e8);
  lVar3 = plVar20[-1];
  puVar4 = *(undefined8 **)(lVar18 + 8);
  *puVar4 = plVar20 + -2;
  plVar20[-2] = lVar18;
  plVar20[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
  local_100 = _DAT_23eede628;
  *(longlong **)(lVar18 + 8) = plVar20 + -2;
  if (local_100 == (longlong *)0x0) {
LAB_23e89201e:
    _DAT_23eede628 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede620,DAT_23eede708);
    local_100 = _DAT_23eede628;
  }
  else {
    lVar18 = *local_100;
    if (1 < lVar18) {
      *local_100 = lVar18 + -1;
      goto LAB_23e89201e;
    }
    if (local_100[2] != 0) {
      *local_100 = lVar18 + -1;
      if (lVar18 + -1 == 0) {
        (**(code **)(local_100[1] + 0x30))(local_100);
      }
      goto LAB_23e89201e;
    }
  }
  lVar18 = *(longlong *)(param_1 + 0x38);
  lVar3 = *(longlong *)(lVar18 + 8);
  local_100[0xf] = lVar3;
  *(longlong **)(lVar18 + 8) = local_100 + 9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (local_100[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(local_100[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *local_100 = *local_100 + 1;
  uVar8 = DAT_23ed6cf28;
  *(undefined4 *)(local_100 + 8) = 0;
  uVar8 = FUN_23a3a0d40(uVar8);
  *(undefined4 *)(local_100 + 5) = 0x127;
  plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar8);
  if (plVar9 == (longlong *)0x0) {
    local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_98[0] = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar23 = 0x127;
    local_b8 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e892b16;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedca28);
  if (plVar9 == (longlong *)0x0) {
    local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_98[0] = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar23 = 0x129;
    local_b8 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e892b16;
  }
  plVar10 = (longlong *)FUN_23ebf7180(plVar9);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (plVar10 == (longlong *)0x0) {
    local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_98[0] = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = (longlong *)0x0;
    uVar23 = 0x129;
    local_b8 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e892b16;
  }
  if (plVar1 == (longlong *)0x0) {
    lVar18 = plVar10[1];
    if (*(code **)(lVar18 + 0xe0) == (code *)0x0) {
      local_f0 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
LAB_23e892ed0:
      PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                   *(undefined8 *)(lVar18 + 0x18));
LAB_23e892eeb:
      cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
      if (cVar6 != '\0') {
        if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_23e892f1a:
        lVar18 = *plVar10;
        *plVar10 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        *plVar20 = *plVar20 + 1;
        lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar11 = *(longlong **)(lVar18 + 0x28);
        plVar10 = (longlong *)plVar11[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
        *(undefined4 *)(plVar11 + 8) = 0xffffffff;
        if (plVar10 != (longlong *)0x0) {
          plVar11[2] = 0;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))();
          }
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plVar11[0xf] = 0;
        lVar18 = *plVar20;
        *plVar20 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(plVar20[1] + 0x30))(plVar20);
        }
        if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if ((local_f0 != (longlong *)0x0) &&
           (lVar18 = *local_f0, *local_f0 = lVar18 + -1, lVar18 + -1 == 0)) {
          (**(code **)(local_f0[1] + 0x30))(local_f0);
        }
        if ((local_c0 != (longlong *)0x0) && (*local_c0 = *local_c0 + -1, *local_c0 == 0)) {
          (**(code **)(local_c0[1] + 0x30))(local_c0);
        }
        if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if ((local_e8 != (longlong *)0x0) &&
           (lVar18 = *local_e8, *local_e8 = lVar18 + -1, lVar18 + -1 == 0)) {
          (**(code **)(local_e8[1] + 0x30))(local_e8);
        }
        if ((local_b8 != (longlong *)0x0) &&
           (lVar18 = *local_b8, *local_b8 = lVar18 + -1, lVar18 + -1 == 0)) {
          (**(code **)(local_b8[1] + 0x30))(local_b8);
        }
        lVar18 = *plVar1;
        *plVar1 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(plVar1[1] + 0x30))(plVar1);
        }
        lVar18 = *plVar2;
        *plVar2 = lVar18 + -1;
        if (lVar18 + -1 != 0) {
          return plVar20;
        }
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return plVar20;
      }
      plVar13 = *(longlong **)(param_1 + 0x70);
      pcVar22 = *(code **)(param_1 + 0x60);
      uVar8 = *(undefined8 *)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_98[0] = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_a8 = (undefined1  [16])0x0;
      if (plVar12 != (longlong *)0x0) {
        uVar23 = 0x129;
        plVar11 = plVar12;
        goto LAB_23e892ab0;
      }
      plVar11 = (longlong *)0x0;
      uVar23 = 0x129;
    }
    else {
      plVar11 = (longlong *)(**(code **)(lVar18 + 0xe0))(plVar10);
      if (plVar11 != (longlong *)0x0) {
        *plVar11 = *plVar11 + 1;
        local_a8._8_8_ =
             PyUnicode_FromFormat
                       ("cannot access local variable \'%U\' where it is not associated with a value"
                        ,DAT_23eedc830);
        local_a8._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
        *(longlong *)local_a8._0_8_ = *(longlong *)local_a8._0_8_ + 1;
        local_98[0] = (longlong *)0x0;
        if ((code *)local_a8._0_8_ != _Py_NoneStruct_exref) {
          FUN_23e91b1b0(param_1,local_a8,local_a8 + 8,local_98);
        }
        plVar9 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        uVar23 = 0x12a;
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_a8._8_8_);
        local_b8 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        plVar13 = local_98[0];
        pcVar22 = (code *)local_a8._0_8_;
        uVar8 = local_a8._8_8_;
        goto LAB_23e892ab0;
      }
      cVar6 = FUN_23a3591a0();
      if (cVar6 != '\0') {
        plVar12 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        goto LAB_23e892f1a;
      }
      pcVar22 = *(code **)(param_1 + 0x60);
      uVar8 = *(undefined8 *)(param_1 + 0x68);
      plVar13 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_c0 = (longlong *)0x0;
      uVar23 = 0x129;
      local_98[0] = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_a8 = (undefined1  [16])0x0;
    }
  }
  else {
    local_b8 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
LAB_23e89219f:
    do {
      lVar18 = plVar10[1];
      if (*(code **)(lVar18 + 0xe0) == (code *)0x0) goto LAB_23e892ed0;
      plVar11 = (longlong *)(**(code **)(lVar18 + 0xe0))();
      if (plVar11 == (longlong *)0x0) goto LAB_23e892eeb;
      if (plVar12 == (longlong *)0x0) {
        *plVar11 = *plVar11 + 1;
      }
      else {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar11 = *plVar11 + 1;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedcbf8);
      if (plVar12 == (longlong *)0x0) goto LAB_23e8934b0;
      if (plVar2 == (longlong *)0x0) {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        local_a8._8_8_ =
             PyUnicode_FromFormat
                       ("cannot access local variable \'%U\' where it is not associated with a value"
                        ,_DAT_23eedcc00);
        local_a8._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
        *(longlong *)local_a8._0_8_ = *(longlong *)local_a8._0_8_ + 1;
        local_98[0] = (longlong *)0x0;
        if ((code *)local_a8._0_8_ != _Py_NoneStruct_exref) {
          FUN_23e91b1b0(param_1,local_a8,local_a8 + 8,local_98);
        }
        uVar23 = 299;
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_a8._8_8_);
        plVar13 = local_98[0];
        pcVar22 = (code *)local_a8._0_8_;
        uVar8 = local_a8._8_8_;
        goto LAB_23e892ab0;
      }
      plVar13 = (longlong *)FUN_23a38cc10(param_1,plVar11,_DAT_23eedcb90);
      if (plVar13 == (longlong *)0x0) {
        uVar23 = 299;
        local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
        local_98[0] = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar12 = *plVar12 + -1;
        plVar13 = local_98[0];
        pcVar22 = (code *)local_a8._0_8_;
        uVar8 = local_a8._8_8_;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          plVar13 = local_98[0];
          pcVar22 = (code *)local_a8._0_8_;
          uVar8 = local_a8._8_8_;
        }
        goto LAB_23e892ab0;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedca20);
      if (plVar14 == (longlong *)0x0) {
        local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_98[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        uVar23 = 299;
        plVar13 = local_98[0];
        pcVar22 = (code *)local_a8._0_8_;
        uVar8 = local_a8._8_8_;
        goto LAB_23e892ab0;
      }
      *(undefined4 *)(local_100 + 5) = 0x12a;
      local_88 = plVar2;
      plStack_80 = plVar13;
      local_78 = plVar14;
      plVar15 = (longlong *)FUN_23e956150(param_1,plVar12,&local_88);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar15 == (longlong *)0x0) {
LAB_23e8934b0:
        uVar23 = 0x12a;
        plVar13 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = *(code **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        goto LAB_23e892ab0;
      }
      plVar12 = (longlong *)FUN_23a388310(plVar15);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if (plVar12 == (longlong *)0x0) goto LAB_23e8934b0;
      plVar14 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
      if ((plVar14 == (longlong *)0x0) &&
         (plVar14 = (longlong *)FUN_23a3c1b70(param_1,local_a8,0,4), plVar14 == (longlong *)0x0)) {
        plVar17 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        pplVar24 = (longlong **)*plVar12;
        plVar15 = (longlong *)0x0;
LAB_23e89317a:
        plVar13 = local_98[0];
        pcVar22 = (code *)local_a8._0_8_;
        uVar8 = local_a8._8_8_;
        local_a8 = (undefined1  [16])0x0;
        local_98[0] = (longlong *)0x0;
        *plVar12 = (longlong)pplVar24 + -1;
        if ((longlong)pplVar24 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        local_98[0] = (longlong *)0x0;
        local_a8 = (undefined1  [16])0x0;
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        uVar23 = 0x12a;
        goto LAB_23e892ab0;
      }
      plVar15 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
      if ((plVar15 == (longlong *)0x0) &&
         (plVar15 = (longlong *)FUN_23a3c1b70(param_1,local_a8,1,4), plVar15 == (longlong *)0x0)) {
        plVar17 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        pplVar24 = (longlong **)*plVar12;
        goto LAB_23e89317a;
      }
      plVar16 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
      if ((plVar16 == (longlong *)0x0) &&
         (plVar16 = (longlong *)FUN_23a3c1b70(param_1,local_a8,2,4), plVar16 == (longlong *)0x0)) {
        plVar17 = (longlong *)0x0;
        pplVar24 = (longlong **)*plVar12;
        goto LAB_23e89317a;
      }
      plVar17 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
      if ((plVar17 == (longlong *)0x0) &&
         (plVar17 = (longlong *)FUN_23a3c1b70(param_1,local_a8,3,4), plVar17 == (longlong *)0x0)) {
        pplVar24 = (longlong **)*plVar12;
        goto LAB_23e89317a;
      }
      cVar6 = FUN_23a3884a0(param_1,local_a8,plVar12,4);
      pplVar24 = (longlong **)*plVar12;
      if (cVar6 == '\0') goto LAB_23e89317a;
      *plVar12 = (longlong)pplVar24 + -1;
      if ((longlong)pplVar24 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      lVar18 = *plVar14;
      *plVar14 = lVar18 + 1;
      if (local_f0 != (longlong *)0x0) {
        lVar18 = *local_f0;
        *local_f0 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(local_f0[1] + 0x30))();
          lVar18 = *plVar14 + -1;
        }
        else {
          lVar18 = *plVar14 + -1;
        }
      }
      *plVar14 = lVar18;
      if (lVar18 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      lVar18 = *plVar15;
      *plVar15 = lVar18 + 1;
      if (local_c0 != (longlong *)0x0) {
        lVar18 = *local_c0;
        *local_c0 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(local_c0[1] + 0x30))(local_c0);
          lVar18 = *plVar15 + -1;
        }
        else {
          lVar18 = *plVar15 + -1;
        }
      }
      *plVar15 = lVar18;
      if (lVar18 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      lVar18 = *plVar16;
      *plVar16 = lVar18 + 1;
      if (plVar9 != (longlong *)0x0) {
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
          lVar18 = *plVar16 + -1;
        }
        else {
          lVar18 = *plVar16 + -1;
        }
      }
      *plVar16 = lVar18;
      if (lVar18 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      lVar18 = *plVar17;
      *plVar17 = lVar18 + 1;
      if (local_e8 != (longlong *)0x0) {
        lVar18 = *local_e8;
        *local_e8 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(local_e8[1] + 0x30))(local_e8);
          lVar18 = *plVar17 + -1;
        }
        else {
          lVar18 = *plVar17 + -1;
        }
      }
      *plVar17 = lVar18;
      if (lVar18 == 0) {
        (**(code **)(plVar17[1] + 0x30))(plVar17);
      }
      iVar7 = FUN_23a35f020(plVar14);
      pplVar24 = DAT_23ed6ce48;
      plVar9 = plVar16;
      local_f0 = plVar14;
      local_e8 = plVar17;
      if (iVar7 == -1) {
        uVar23 = 0x12e;
        pcVar22 = *(code **)(param_1 + 0x60);
        plVar13 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_c0 = plVar15;
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        goto LAB_23e892ab0;
      }
      if (iVar7 != 0) {
        plVar13 = (longlong *)FUN_23a38cc10(param_1,plVar11,DAT_23ed6ce48);
        if (plVar13 == (longlong *)0x0) {
          uVar23 = 0x130;
          pcVar22 = *(code **)(param_1 + 0x60);
          plVar13 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_c0 = plVar15;
          uVar8 = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e892ab0;
        }
        plVar19 = (longlong *)_PyDict_NewPresized(4);
        PyDict_SetItem(plVar19,pplVar24,plVar13);
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        PyDict_SetItem(plVar19,DAT_23eedca70,plVar15);
        PyDict_SetItem(plVar19,DAT_23eedcb00,plVar16);
        PyDict_SetItem(plVar19,_DAT_23eedcc08,plVar17);
        if ((local_b8 != (longlong *)0x0) &&
           (lVar18 = *local_b8, *local_b8 = lVar18 + -1, lVar18 + -1 == 0)) {
          (**(code **)(local_b8[1] + 0x30))(local_b8);
        }
        FUN_23e8bc550(plVar20,plVar19);
        local_e8 = (longlong *)FUN_23a3a0d40(DAT_23ed6cf28);
        plVar13 = _DAT_23eedcc18;
        lVar18 = *(longlong *)(param_1 + 0x10);
        plVar9 = *(longlong **)(lVar18 + 0xe58);
        if (plVar9 == (longlong *)0x0) {
          plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,9);
        }
        else {
          lVar3 = plVar9[3];
          *(int *)(lVar18 + 0xed8) = *(int *)(lVar18 + 0xed8) + -1;
          *(longlong *)(lVar18 + 0xe58) = lVar3;
          *plVar9 = 1;
        }
        pcVar22 = _PyRuntime_exref;
        *(undefined1 (*) [16])(plVar9 + 4) = (undefined1  [16])0x0;
        lVar18 = *(longlong *)(pcVar22 + 0x1f8);
        *(undefined1 (*) [16])(plVar9 + 6) = (undefined1  [16])0x0;
        *(undefined1 (*) [16])(plVar9 + 8) = (undefined1  [16])0x0;
        lVar18 = *(longlong *)(lVar18 + 0x10);
        *(undefined1 (*) [16])(plVar9 + 10) = (undefined1  [16])0x0;
        lVar18 = *(longlong *)(lVar18 + 0x2e8);
        lVar3 = plVar9[-1];
        puVar4 = *(undefined8 **)(lVar18 + 8);
        *puVar4 = plVar9 + -2;
        plVar9[-2] = lVar18;
        plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
        *(longlong **)(lVar18 + 8) = plVar9 + -2;
        *plVar13 = *plVar13 + 1;
        plVar9[3] = (longlong)plVar13;
        pplVar24 = DAT_23ed6ce48;
        local_f0 = (longlong *)FUN_23a38cc10(param_1,plVar11);
        plVar13 = DAT_23ed6cd28;
        if (local_f0 == (longlong *)0x0) goto LAB_23e893740;
        plVar12 = (longlong *)&DAT_23ed6a4c0;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar21 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar21 != (longlong *)0x0) {
            *plVar21 = *plVar21 + 1;
            DAT_23ed6a4c0 = plVar21;
            goto LAB_23e8927a1;
          }
LAB_23e893ac0:
          PyErr_PrintEx(0,0);
          Py_Exit(1);
          goto LAB_23e89317a;
        }
LAB_23e8927a1:
        plStack_80 = plVar13;
        pplVar24 = &local_88;
        local_88 = local_f0;
        plVar13 = (longlong *)FUN_23e94ed00(param_1,DAT_23ed6a4c0);
        *local_f0 = *local_f0 + -1;
        if (*local_f0 == 0) {
          (**(code **)(local_f0[1] + 0x30))(local_f0);
          local_f0 = plVar13;
        }
        if (plVar13 == (longlong *)0x0) {
LAB_23e893740:
          local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_98[0] = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            uVar23 = 0x136;
            (**(code **)(plVar9[1] + 0x30))(plVar9);
            plVar13 = local_98[0];
            local_c0 = plVar15;
            plVar9 = plVar16;
            pcVar22 = (code *)local_a8._0_8_;
            uVar8 = local_a8._8_8_;
            local_f0 = plVar14;
            local_e8 = plVar17;
            local_b8 = plVar19;
            goto LAB_23e892ab0;
          }
        }
        else {
          plVar9[4] = (longlong)plVar13;
          plVar21 = _DAT_23eedcc20;
          plVar13 = DAT_23ed6a4c0;
          *_DAT_23eedcc20 = *_DAT_23eedcc20 + 1;
          plVar9[5] = (longlong)plVar21;
          plVar21 = DAT_23ed6cd28;
          if (plVar13 == (longlong *)0x0) {
            plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar13 == (longlong *)0x0) goto LAB_23e893ac0;
            *plVar13 = *plVar13 + 1;
            DAT_23ed6a4c0 = plVar13;
          }
          plStack_80 = plVar21;
          pplVar24 = &local_88;
          local_88 = plVar15;
          lVar18 = FUN_23e94ed00(param_1,plVar13);
          if (lVar18 == 0) goto LAB_23e893740;
          plVar9[6] = lVar18;
          plVar21 = _DAT_23eedcc28;
          plVar13 = DAT_23ed6a4c0;
          *_DAT_23eedcc28 = *_DAT_23eedcc28 + 1;
          plVar9[7] = (longlong)plVar21;
          plVar21 = DAT_23ed6cd28;
          if (plVar13 == (longlong *)0x0) {
            plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar13 == (longlong *)0x0) goto LAB_23e893ac0;
            *plVar13 = *plVar13 + 1;
            DAT_23ed6a4c0 = plVar13;
          }
          plStack_80 = plVar21;
          pplVar24 = &local_88;
          local_88 = plVar16;
          lVar18 = FUN_23e94ed00(param_1,plVar13);
          if (lVar18 == 0) goto LAB_23e893740;
          plVar9[8] = lVar18;
          plVar5 = _DAT_23eedcc38;
          plVar21 = _DAT_23eedcc30;
          plVar13 = DAT_23ed6a4c0;
          *_DAT_23eedcc30 = *_DAT_23eedcc30 + 1;
          plVar9[9] = (longlong)plVar21;
          if (plVar13 == (longlong *)0x0) {
            plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar13 == (longlong *)0x0) goto LAB_23e893ac0;
            *plVar13 = *plVar13 + 1;
            DAT_23ed6a4c0 = plVar13;
          }
          plStack_80 = plVar5;
          local_88 = plVar17;
          lVar18 = FUN_23e94ed00(param_1,plVar13,&local_88);
          if (lVar18 == 0) goto LAB_23e893740;
          plVar9[10] = lVar18;
          plVar13 = _DAT_23eedcc40;
          *_DAT_23eedcc40 = *_DAT_23eedcc40 + 1;
          plVar9[0xb] = (longlong)plVar13;
          plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar13 != (longlong *)0x0) {
            *(undefined4 *)(local_100 + 5) = 0x136;
            plVar9 = (longlong *)FUN_23e914090(param_1,local_e8,plVar13);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (plVar9 != (longlong *)0x0) {
              *plVar9 = *plVar9 + -1;
              local_b8 = plVar19;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              goto LAB_23e8924fa;
            }
          }
          local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_98[0] = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
        }
        uVar23 = 0x136;
        plVar13 = local_98[0];
        local_c0 = plVar15;
        plVar9 = plVar16;
        pcVar22 = (code *)local_a8._0_8_;
        uVar8 = local_a8._8_8_;
        local_f0 = plVar14;
        local_e8 = plVar17;
        local_b8 = plVar19;
        goto LAB_23e892ab0;
      }
LAB_23e8924fa:
      lVar18 = *(longlong *)(param_1 + 0x10);
      if ((((*(int *)(*(longlong *)(lVar18 + 0x28) + 0x160) != 0) || (*(int *)(lVar18 + 0x78) != 0))
          && (iVar7 = Py_MakePendingCalls(), iVar7 < 0)) &&
         (pcVar22 = *(code **)(param_1 + 0x60), pcVar22 != (code *)0x0)) goto LAB_23e892a5d;
      plVar12 = plVar11;
      if (*(int *)(lVar18 + 0x68) != 0) {
        PyEval_SaveThread();
        PyEval_AcquireThread(param_1);
        plVar13 = *(longlong **)(param_1 + 0x90);
        plVar9 = plVar16;
        local_f0 = plVar14;
        local_e8 = plVar17;
        local_c0 = plVar15;
        if (plVar13 != (longlong *)0x0) break;
        goto LAB_23e89219f;
      }
      plVar13 = *(longlong **)(param_1 + 0x90);
      plVar9 = plVar16;
      local_f0 = plVar14;
      local_e8 = plVar17;
      local_c0 = plVar15;
    } while (plVar13 == (longlong *)0x0);
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x90) = 0;
    plVar19 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar13;
    *plVar13 = *plVar13 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
      (**(code **)(plVar9[1] + 0x30))();
    }
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if ((plVar19 == (longlong *)0x0) || (*plVar19 = *plVar19 + -1, *plVar19 != 0)) {
      pcVar22 = *(code **)(param_1 + 0x60);
    }
    else {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
      pcVar22 = *(code **)(param_1 + 0x60);
    }
LAB_23e892a5d:
    plVar13 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar23 = 0x129;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    local_c0 = plVar15;
    plVar9 = plVar16;
    uVar8 = *(undefined8 *)(param_1 + 0x68);
    local_f0 = plVar14;
    local_e8 = plVar17;
LAB_23e892ab0:
    local_98[0] = (longlong *)0x0;
    local_a8 = (undefined1  [16])0x0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
  }
  lVar18 = *plVar10;
  *plVar10 = lVar18 + -1;
  if (lVar18 + -1 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  local_a8._8_8_ = uVar8;
  local_a8._0_8_ = pcVar22;
  local_98[0] = plVar13;
LAB_23e892b16:
  plVar13 = local_98[0];
  plVar10 = DAT_23ed6a4f8;
  if (local_98[0] == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar13 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar10[2] = 0;
    plVar10[3] = (longlong)local_100;
    *local_100 = *local_100 + 1;
    pcVar22 = _PyRuntime_exref;
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar18 = *(longlong *)(pcVar22 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar23;
    lVar18 = *(longlong *)(*(longlong *)(lVar18 + 0x10) + 0x2e8);
    lVar3 = plVar10[-1];
    puVar4 = *(undefined8 **)(lVar18 + 8);
    *puVar4 = plVar10 + -2;
    plVar10[-2] = lVar18;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar18 + 8) = plVar10 + -2;
    plVar13 = plVar10;
    if ((local_98[0] != (longlong *)0x0) && (*local_98[0] = *local_98[0] + -1, *local_98[0] == 0)) {
      (**(code **)(local_98[0][1] + 0x30))(local_98[0]);
    }
  }
  else if ((longlong *)local_98[0][3] != local_100) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar12 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar10[3] = (longlong)local_100;
    *local_100 = *local_100 + 1;
    pcVar22 = _PyRuntime_exref;
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar18 = *(longlong *)(pcVar22 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar23;
    lVar18 = *(longlong *)(*(longlong *)(lVar18 + 0x10) + 0x2e8);
    lVar3 = plVar10[-1];
    puVar4 = *(undefined8 **)(lVar18 + 8);
    *puVar4 = plVar10 + -2;
    plVar10[-2] = lVar18;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar18 + 8) = plVar10 + -2;
    plVar10[2] = (longlong)plVar13;
    *plVar13 = *plVar13 + 1;
    plVar13 = plVar10;
    if ((local_98[0] != (longlong *)0x0) && (*local_98[0] = *local_98[0] + -1, *local_98[0] == 0)) {
      (**(code **)(local_98[0][1] + 0x30))();
    }
  }
  local_98[0] = plVar13;
  FUN_23e8bba40(local_100,"ooooooooo",plVar1,plVar2,plVar20,plVar11,local_f0,local_c0,plVar9,
                local_e8,local_b8);
  if (_DAT_23eede628 == local_100) {
    lVar18 = *local_100;
    *local_100 = lVar18 + -1;
    if (lVar18 + -1 == 0) {
      (**(code **)(local_100[1] + 0x30))(local_100);
    }
    _DAT_23eede628 = (longlong *)0x0;
  }
  lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar18 + 0x28);
  plVar13 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
    plVar10[0xf] = 0;
    plVar10 = local_98[0];
    uVar8 = local_a8._0_8_;
    uVar25 = local_a8._8_8_;
  }
  else {
    plVar10[0xf] = 0;
    plVar10 = local_98[0];
    uVar8 = local_a8._0_8_;
    uVar25 = local_a8._8_8_;
  }
  local_98[0] = (longlong *)0x0;
  local_a8 = (undefined1  [16])0x0;
  lVar18 = *plVar20;
  *plVar20 = lVar18 + -1;
  if (lVar18 + -1 == 0) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((local_f0 != (longlong *)0x0) &&
     (lVar18 = *local_f0, *local_f0 = lVar18 + -1, lVar18 + -1 == 0)) {
    (**(code **)(local_f0[1] + 0x30))(local_f0);
  }
  if ((local_c0 != (longlong *)0x0) && (*local_c0 = *local_c0 + -1, *local_c0 == 0)) {
    (**(code **)(local_c0[1] + 0x30))(local_c0);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((local_e8 != (longlong *)0x0) &&
     (lVar18 = *local_e8, *local_e8 = lVar18 + -1, lVar18 + -1 == 0)) {
    (**(code **)(local_e8[1] + 0x30))(local_e8);
  }
  if ((local_b8 != (longlong *)0x0) &&
     (lVar18 = *local_b8, *local_b8 = lVar18 + -1, lVar18 + -1 == 0)) {
    (**(code **)(local_b8[1] + 0x30))(local_b8);
  }
  local_a8._8_8_ = uVar25;
  local_a8._0_8_ = uVar8;
  lVar18 = *plVar1;
  *plVar1 = lVar18 + -1;
  local_98[0] = plVar10;
  if (lVar18 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar18 = *plVar2;
  *plVar2 = lVar18 + -1;
  if (lVar18 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_a8._0_8_,local_a8._8_8_,local_98[0]);
  return (longlong *)0x0;
}
