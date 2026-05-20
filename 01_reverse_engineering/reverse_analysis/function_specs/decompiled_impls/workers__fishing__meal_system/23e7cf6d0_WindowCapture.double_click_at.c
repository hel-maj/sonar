/* ===== 23e7cf6d0 workers.fishing.meal_system:119 ===== */
/* ghidra_name=FUN_23e7cf6d0 entry=23e7cf6d0 size=11223 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e7cf6d0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  code *pcVar8;
  int iVar9;
  uint uVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  longlong *plVar18;
  code *pcVar19;
  undefined8 uVar20;
  longlong *plVar21;
  code *pcVar22;
  longlong *plStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  code *pcStack_d8;
  code *pcStack_d0;
  code *pcStack_c0;
  longlong *plStack_a8;
  undefined8 uStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar11 = _DAT_23eeded28;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)*param_3;
  plVar4 = (longlong *)param_3[2];
  if (_DAT_23eeded28 == (longlong *)0x0) {
LAB_23e7cf72d:
    _DAT_23eeded28 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeded20,DAT_23eed7940,0x60);
  }
  else {
    lVar12 = *_DAT_23eeded28;
    if (1 < lVar12) {
      *_DAT_23eeded28 = lVar12 + -1;
      goto LAB_23e7cf72d;
    }
    if (_DAT_23eeded28[2] != 0) {
      *_DAT_23eeded28 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e7cf72d;
    }
  }
  plVar6 = _DAT_23eeded28;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eeded28 + 9;
  lVar5 = *(longlong *)(lVar12 + 8);
  _DAT_23eeded28[0xf] = lVar5;
  *(longlong **)(lVar12 + 8) = plVar11;
  if ((lVar5 != 0) &&
     (((*(char *)(lVar5 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar5 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar5 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar5 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar5 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  *(undefined4 *)(plVar6 + 8) = 0;
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eed70a8);
  if (plVar11 == (longlong *)0x0) {
    pcStack_d0 = *(code **)(param_1 + 0x60);
    pcVar19 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_d8 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar19 == (code *)0x0) goto LAB_23e7d1400;
    plVar11 = *(longlong **)(pcVar19 + 0x18);
joined_r0x00023e7d05b9:
    if (plVar6 == plVar11) {
      pcVar17 = (code *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      pcVar22 = pcVar19;
      goto LAB_23e7d06b0;
    }
LAB_23e7d05ef:
    pcVar17 = (code *)0x0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    iVar9 = 0x79;
    pcStack_c0 = _PyRuntime_exref;
  }
  else {
    iVar9 = FUN_23a35f020(plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (iVar9 == -1) {
LAB_23e7d0910:
      pcStack_d0 = *(code **)(param_1 + 0x60);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar19 == (code *)0x0) goto LAB_23e7d1400;
      plVar11 = *(longlong **)(pcVar19 + 0x18);
      goto joined_r0x00023e7d05b9;
    }
    if (iVar9 == 0) {
LAB_23e7cf7f9:
      pcVar19 = _Py_FalseStruct_exref;
      pcVar17 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
      plStack_f8 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
LAB_23e7cf837:
      lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar6 = *(longlong **)(lVar12 + 0x28);
      plVar16 = (longlong *)plVar6[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
      *(undefined4 *)(plVar6 + 8) = 0xffffffff;
      if (plVar16 != (longlong *)0x0) {
        plVar6[2] = 0;
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))();
        }
      }
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      plVar6[0xf] = 0;
      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (plVar11 != (longlong *)0x0) {
LAB_23e7cf89a:
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
LAB_23e7d0550:
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
      }
      if (plVar14 == (longlong *)0x0) goto LAB_23e7cf8b4;
LAB_23e7cf8a9:
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
LAB_23e7cf8b4:
      if ((plStack_108 != (longlong *)0x0) &&
         (lVar12 = *plStack_108, *plStack_108 = lVar12 + -1, lVar12 + -1 == 0)) {
        (**(code **)(plStack_108[1] + 0x30))(plStack_108);
      }
      if ((plStack_100 != (longlong *)0x0) &&
         (lVar12 = *plStack_100, *plStack_100 = lVar12 + -1, lVar12 + -1 == 0)) {
        (**(code **)(plStack_100[1] + 0x30))(plStack_100);
      }
      if ((pcVar17 != (code *)0x0) &&
         (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
      }
      if ((plStack_f8 != (longlong *)0x0) &&
         (lVar12 = *plStack_f8, *plStack_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
        (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
      }
      if ((plStack_f0 != (longlong *)0x0) &&
         (lVar12 = *plStack_f0, *plStack_f0 = lVar12 + -1, lVar12 + -1 == 0)) {
        (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
      }
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
      lVar12 = *plVar2;
      *plVar2 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar2[1] + 0x30))(plVar2);
      }
      lVar12 = *plVar4;
      *plVar4 = lVar12 + -1;
      if (lVar12 + -1 != 0) {
        return pcVar19;
      }
      (**(code **)(plVar4[1] + 0x30))(plVar4);
      return pcVar19;
    }
    lVar12 = FUN_23e8de4a0();
    if (lVar12 == 0) {
      FUN_23e915740(param_1,&plStack_78,uRam000000023eed70c0);
      pcStack_d0 = (code *)plStack_78;
      pcStack_d8 = pcStack_70;
joined_r0x00023e7d13c6:
      if (pcStack_68 == (code *)0x0) {
LAB_23e7d1400:
        pcVar17 = (code *)0x0;
        plVar13 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        iVar9 = 0x79;
        pcStack_c0 = _PyRuntime_exref;
LAB_23e7d1100:
        pcVar22 = DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar19 = *(code **)DAT_23ed6a4f8;
          *(undefined8 *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar19;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong *)(pcVar22 + 0x10) = 0;
        *(longlong **)(pcVar22 + 0x18) = plVar6;
        *plVar6 = *plVar6 + 1;
        lVar12 = *(longlong *)(pcStack_c0 + 0x1f8);
        *(int *)(pcVar22 + 0x24) = iVar9;
        lVar12 = *(longlong *)(lVar12 + 0x10);
        *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
        lVar12 = *(longlong *)(lVar12 + 0x2e8);
        lVar5 = *(longlong *)(pcVar22 + -8);
        plVar16 = *(longlong **)(lVar12 + 8);
        *plVar16 = (longlong)(pcVar22 + -0x10);
        *(longlong *)(pcVar22 + -0x10) = lVar12;
        *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar5 & 3) | (ulonglong)plVar16;
        *(code **)(lVar12 + 8) = pcVar22 + -0x10;
        goto LAB_23e7d06b0;
      }
      plVar11 = *(longlong **)(pcStack_68 + 0x18);
      pcVar19 = pcStack_68;
      goto joined_r0x00023e7d05b9;
    }
    plVar11 = (longlong *)FUN_23e8bc2f0(lVar12,uRam000000023eed7118);
    if (plVar11 == (longlong *)0x0) {
      pcStack_d0 = *(code **)(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto joined_r0x00023e7d13c6;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eed70a8);
    if (plVar13 == (longlong *)0x0) {
      pcStack_d0 = *(code **)(param_1 + 0x60);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar11 = *plVar11 + -1;
      plVar13 = (longlong *)0x0;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        if (pcVar19 != (code *)0x0) {
          plVar11 = *(longlong **)(pcVar19 + 0x18);
joined_r0x00023e7d16f5:
          if (plVar6 == plVar11) {
            plStack_100 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            pcVar22 = pcVar19;
            goto LAB_23e7d06b0;
          }
          goto LAB_23e7d05ef;
        }
      }
      else if (pcVar19 != (code *)0x0) {
        plVar11 = *(longlong **)(pcVar19 + 0x18);
        goto joined_r0x00023e7d16f5;
      }
      goto LAB_23e7d1400;
    }
    *(undefined4 *)(plVar6 + 5) = 0x79;
    plVar14 = (longlong *)FUN_23e914090(param_1,plVar11,plVar13);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar14 == (longlong *)0x0) {
      pcStack_d0 = *(code **)(param_1 + 0x60);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar11 = (longlong *)0x0;
      if (pcVar19 == (code *)0x0) goto LAB_23e7d1400;
      if (plVar6 == *(longlong **)(pcVar19 + 0x18)) {
        plStack_100 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcVar22 = pcVar19;
        goto LAB_23e7d06b0;
      }
      goto LAB_23e7d05ef;
    }
    uVar10 = FUN_23a35f020(plVar14);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if (uVar10 == 0xffffffff) goto LAB_23e7d0910;
    if ((uVar10 & 1) == 0) goto LAB_23e7cf7f9;
    lVar12 = FUN_23e8de4a0();
    if (lVar12 != 0) {
      plVar11 = (longlong *)FUN_23e8bc2f0(lVar12,uRam000000023eed7228);
      pcStack_d0 = _Py_NoneStruct_exref;
      if (plVar11 == (longlong *)0x0) {
        pcVar19 = *(code **)(param_1 + 0x70);
        pcVar17 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar13 = (longlong *)0x0;
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        plStack_100 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x7e;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar11 = (longlong *)0x0;
        goto LAB_23e7d0a4e;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eed70a8);
      if (plVar14 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        pcVar17 = (code *)0x0;
        plVar11 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x7e;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d0 = _Py_NoneStruct_exref;
        plVar14 = (longlong *)0x0;
        goto LAB_23e7d0a4e;
      }
      *(undefined4 *)(plVar6 + 5) = 0x7e;
      plVar13 = (longlong *)FUN_23e914090(param_1,plVar11,plVar14);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar13 == (longlong *)0x0) {
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar16 = *(longlong **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar22 = *(code **)(param_1 + 0x68);
        goto LAB_23e7d1519;
      }
      lVar12 = FUN_23e8de4a0();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,uRam000000023eed70c0);
        plVar11 = (longlong *)0x0;
        pcVar19 = pcStack_68;
        plVar16 = plStack_78;
        pcVar22 = pcStack_70;
LAB_23e7d1899:
        pcVar17 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x7f;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d0 = _Py_NoneStruct_exref;
        goto LAB_23e7d0a4e;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar12,uRam000000023eed7128);
      pcStack_d0 = _Py_NoneStruct_exref;
      if (plVar15 == (longlong *)0x0) {
        pcVar17 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar11 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d8._0_4_ = 0x7f;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto LAB_23e7d0a4e;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eed70a8);
      if (plVar14 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar12 = *plVar15;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar15 = lVar12 + -1;
        plVar14 = (longlong *)0x0;
        if (lVar12 + -1 == 0) {
          pcVar17 = (code *)0x0;
          plVar11 = (longlong *)0x0;
          (**(code **)(plVar15[1] + 0x30))(plVar15);
          plStack_f0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          pcStack_d8._0_4_ = 0x7f;
          plStack_f8 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          pcStack_d0 = _Py_NoneStruct_exref;
        }
        else {
          pcVar17 = (code *)0x0;
          plVar11 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          pcStack_d8._0_4_ = 0x7f;
          plStack_f8 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          pcStack_d0 = _Py_NoneStruct_exref;
        }
        goto LAB_23e7d0a4e;
      }
      *(undefined4 *)(plVar6 + 5) = 0x7f;
      plVar11 = (longlong *)FUN_23e914090(param_1,plVar15,plVar14);
      lVar12 = *plVar15;
      *plVar15 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar11 == (longlong *)0x0) {
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar16 = *(longlong **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar22 = *(code **)(param_1 + 0x68);
        goto LAB_23e7d1899;
      }
      plStack_108 = (longlong *)FUN_23a388650(param_1,plVar13,uRam000000023eed7230,2);
      if (plStack_108 == (longlong *)0x0) {
LAB_23e7d18e1:
        pcStack_d0 = _Py_NoneStruct_exref;
        pcVar17 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        plStack_f0 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x82;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7d0a4e;
      }
      plVar14 = (longlong *)FUN_23a388650(param_1,plVar13,DAT_23ed6ccf0,0);
      if (plVar14 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar12 = *plStack_108;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plStack_108 = lVar12 + -1;
        plVar14 = (longlong *)0x0;
        if (lVar12 + -1 != 0) goto LAB_23e7d1abe;
        (**(code **)(plStack_108[1] + 0x30))(plStack_108);
        pcStack_d8 = pcVar19;
        goto LAB_23e7d1a70;
      }
      plStack_100 = (longlong *)FUN_23e8c6640(plStack_108,plVar14);
      lVar12 = *plStack_108;
      *plStack_108 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plStack_108[1] + 0x30))(plStack_108);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      pcStack_d0 = _Py_NoneStruct_exref;
      if (plStack_100 == (longlong *)0x0) {
        pcVar17 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        plStack_f0 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x82;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7d0a4e;
      }
      plVar16 = (longlong *)FUN_23a388650(param_1,plVar11);
      plVar14 = (longlong *)0x0;
      if (plVar16 == (longlong *)0x0) goto LAB_23e7d1b6f;
      plStack_108 = (longlong *)FUN_23e8c6640(plStack_100,plVar16);
      lVar12 = *plStack_100;
      *plStack_100 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plStack_100[1] + 0x30))(plStack_100);
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      if (plStack_108 == (longlong *)0x0) goto LAB_23e7d18e1;
      if ((code *)plStack_108[1] == PyLong_Type_exref) {
        plVar14 = (longlong *)
                  (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0xe8))
                            (plStack_108,uRam000000023eed7230);
        lVar12 = *plStack_108 + -1;
        *plStack_108 = lVar12;
        if (plVar14 == (longlong *)0x0) {
          if (lVar12 == 0) {
            (**(code **)(plStack_108[1] + 0x30))();
          }
          goto LAB_23e7d1c01;
        }
        if (lVar12 == 0) {
          (**(code **)(plStack_108[1] + 0x30))();
        }
      }
      else {
        plVar14 = (longlong *)FUN_23e8c1be0();
        lVar12 = *plStack_108;
        *plStack_108 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
          (**(code **)(plStack_108[1] + 0x30))();
        }
        if (plVar14 == (longlong *)0x0) {
LAB_23e7d1c01:
          pcStack_d0 = _Py_NoneStruct_exref;
          plVar16 = *(longlong **)(param_1 + 0x60);
          pcVar22 = *(code **)(param_1 + 0x68);
          pcVar19 = *(code **)(param_1 + 0x70);
          pcVar17 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcStack_d8._0_4_ = 0x82;
          plVar14 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7d0a4e;
        }
      }
      plStack_100 = (longlong *)FUN_23a388650(param_1,plVar13,uRam000000023eed7238,3);
      if (plStack_100 == (longlong *)0x0) {
LAB_23e7d1c56:
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d0 = _Py_NoneStruct_exref;
        pcVar17 = (code *)0x0;
        pcStack_d8._0_4_ = 0x83;
        plStack_108 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        goto LAB_23e7d0a4e;
      }
      plVar16 = (longlong *)FUN_23a388650(param_1,plVar13,DAT_23ed6ccf8,1);
      if (plVar16 == (longlong *)0x0) {
        pcVar19 = *(code **)(param_1 + 0x70);
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar12 = *plStack_100 + -1;
        *plStack_100 = lVar12;
        plVar15 = plStack_100;
joined_r0x00023e7d1ccc:
        plStack_108 = (longlong *)0x0;
        if (lVar12 == 0) {
          plStack_108 = (longlong *)0x0;
          FUN_23a334bc0(plVar15);
          pcVar17 = (code *)0x0;
          pcStack_d8._0_4_ = 0x83;
          plStack_f0 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          pcStack_d0 = _Py_NoneStruct_exref;
          goto LAB_23e7d0a4e;
        }
LAB_23e7d1d33:
        pcVar17 = (code *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x83;
        pcStack_d0 = _Py_NoneStruct_exref;
        goto LAB_23e7d0a4e;
      }
      plVar15 = (longlong *)FUN_23e8c6640(plStack_100,plVar16);
      lVar12 = *plStack_100;
      *plStack_100 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plStack_100);
      }
      lVar12 = *plVar16;
      *plVar16 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plVar16);
      }
      if (plVar15 == (longlong *)0x0) {
        pcVar19 = *(code **)(param_1 + 0x70);
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d0 = _Py_NoneStruct_exref;
        pcStack_d8._0_4_ = 0x83;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar17 = (code *)0x0;
        goto LAB_23e7d0a4e;
      }
      plVar16 = (longlong *)FUN_23a388650(param_1,plVar11,uRam000000023eed7238);
      if (plVar16 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar15 = *plVar15 + -1;
        lVar12 = *plVar15;
        goto joined_r0x00023e7d1ccc;
      }
      plStack_100 = (longlong *)FUN_23e8c6640(plVar15,plVar16);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      lVar12 = *plVar16;
      *plVar16 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plVar16);
      }
      if (plStack_100 == (longlong *)0x0) goto LAB_23e7d1c56;
      plStack_108 = (longlong *)FUN_23e8c6640(plStack_100);
      lVar12 = *plStack_100;
      *plStack_100 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plStack_100);
      }
      if (plStack_108 == (longlong *)0x0) {
        pcVar19 = *(code **)(param_1 + 0x70);
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7d1d33;
      }
      plStack_100 = (longlong *)FUN_23a388650(param_1,plVar13,DAT_23ed6ccf0);
      if (plStack_100 == (longlong *)0x0) {
LAB_23e7d1de4:
        pcStack_d0 = _Py_NoneStruct_exref;
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar17 = (code *)0x0;
        pcStack_d8._0_4_ = 0x86;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7d0a4e;
      }
      plVar16 = (longlong *)FUN_23e8c09e0(plStack_100,plVar14);
      lVar12 = *plStack_100;
      *plStack_100 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plStack_100);
      }
      pcStack_d0 = _Py_NoneStruct_exref;
      if (plVar16 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d8._0_4_ = 0x86;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar17 = (code *)0x0;
        goto LAB_23e7d0a4e;
      }
      plStack_100 = (longlong *)FUN_23e8c09e0(plVar16,plVar2);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      if (plStack_100 == (longlong *)0x0) goto LAB_23e7d1de4;
      plVar16 = (longlong *)FUN_23a388650(param_1,plVar13,DAT_23ed6ccf8,1);
      pcVar17 = (code *)0x0;
      if (plVar16 == (longlong *)0x0) {
LAB_23e7d1e64:
        pcStack_d0 = _Py_NoneStruct_exref;
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d8._0_4_ = 0x87;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7d0a4e;
      }
      plVar15 = (longlong *)FUN_23e8c09e0(plVar16,plStack_108);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      pcStack_d0 = _Py_NoneStruct_exref;
      if (plVar15 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar17 = (code *)0x0;
        pcStack_d8._0_4_ = 0x87;
        plStack_f0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_f8 = (longlong *)0x0;
        goto LAB_23e7d0a4e;
      }
      pcVar17 = (code *)FUN_23e8c09e0(plVar15,plVar4);
      lVar12 = *plVar15;
      *plVar15 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0();
      }
      pcStack_d0 = _Py_NoneStruct_exref;
      lVar12 = _DAT_23eede1c0;
      uVar20 = uRam000000023eed7240;
      if (pcVar17 == (code *)0x0) goto LAB_23e7d1e64;
      *(undefined4 *)(plVar6 + 5) = 0x8a;
      plStack_f8 = (longlong *)
                   FUN_23e95c160(param_1,uVar20,lVar12,pcStack_d0,pcStack_d0,DAT_23ed6ccf0);
      if (plStack_f8 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        plStack_f0 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d8._0_4_ = 0x8a;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7d0a4e;
      }
      *(undefined4 *)(plVar6 + 5) = 0x8b;
      plStack_f0 = (longlong *)FUN_23e91bfe0(param_1,plStack_f8,uRam000000023eed7248);
      if (plStack_f0 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x8b;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e7d0a4e;
      }
      lVar12 = FUN_23e8ddf60();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,uRam000000023eed7250);
        pcStack_d8._0_4_ = 0x8e;
        pcVar19 = pcStack_68;
        plVar16 = plStack_78;
        pcVar22 = pcStack_70;
        goto LAB_23e7d0a4e;
      }
      *(undefined4 *)(plVar6 + 5) = 0x8e;
      plStack_78 = plStack_100;
      pcStack_70 = pcVar17;
      plVar16 = (longlong *)FUN_23e954670(param_1,lVar12,uRam000000023eed7258,&plStack_78);
      if (plVar16 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x8e;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = *(code **)(param_1 + 0x68);
        goto LAB_23e7d0a4e;
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      lVar12 = FUN_23e8de0b0();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,uRam000000023eed7260);
        pcStack_d8._0_4_ = 0x8f;
        pcVar19 = pcStack_68;
        plVar16 = plStack_78;
        pcVar22 = pcStack_70;
        goto LAB_23e7d0a4e;
      }
      *(undefined4 *)(plVar6 + 5) = 0x8f;
      plVar16 = (longlong *)
                FUN_23e915840(param_1,lVar12,uRam000000023eed7268,
                              *(undefined8 *)(lRam000000023eed7270 + 0x18));
      if (plVar16 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x8f;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = *(code **)(param_1 + 0x68);
        goto LAB_23e7d0a4e;
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      lVar12 = FUN_23e8ddf60();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,uRam000000023eed7250);
        pcStack_d8._0_4_ = 0x92;
        pcVar19 = pcStack_68;
        plVar16 = plStack_78;
        pcVar22 = pcStack_70;
        goto LAB_23e7d0a4e;
      }
      *(undefined4 *)(plVar6 + 5) = 0x92;
      plVar16 = (longlong *)FUN_23e91bfe0(param_1,lVar12,uRam000000023eed7278);
      if (plVar16 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x92;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = *(code **)(param_1 + 0x68);
        goto LAB_23e7d0a4e;
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      lVar12 = FUN_23e8de0b0();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,uRam000000023eed7260);
        pcStack_d8._0_4_ = 0x93;
        pcVar19 = pcStack_68;
        plVar16 = plStack_78;
        pcVar22 = pcStack_70;
        goto LAB_23e7d0a4e;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar12,uRam000000023eed7268);
      if (plVar15 == (longlong *)0x0) {
LAB_23e7d2305:
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x93;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = *(code **)(param_1 + 0x68);
        goto LAB_23e7d0a4e;
      }
      lVar12 = *(longlong *)(_DAT_23eede1c0 + 0x20);
      if (*(char *)(lVar12 + 10) != '\0') {
        iVar9 = *(int *)(lVar12 + 0xc);
        if (*(int *)(lVar12 + 0xc) == 0) {
          *(int *)(lVar12 + 0xc) = _DAT_23ec15654;
          iVar9 = _DAT_23ec15654;
          _DAT_23ec15654 = _DAT_23ec15654 + 1;
        }
        if (_DAT_23ec15648 != iVar9) {
          _DAT_23ec15648 = iVar9;
          _DAT_23eeded18 =
               FUN_23e8cbd60(lVar12,lRam000000023eed7280,
                             *(undefined8 *)(lRam000000023eed7280 + 0x18));
        }
        if (-1 < _DAT_23eeded18) {
          lVar5 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
          if (*(longlong *)(lVar5 + 8 + _DAT_23eeded18 * 0x10) != 0) goto LAB_23e7d0263;
          _DAT_23eeded18 =
               FUN_23e8cbd60(lVar12,lRam000000023eed7280,
                             *(undefined8 *)(lRam000000023eed7280 + 0x18));
          if (-1 < _DAT_23eeded18) {
            lVar12 = *(longlong *)(lVar5 + 8 + _DAT_23eeded18 * 0x10);
            goto LAB_23e7d2267;
          }
        }
LAB_23e7d2270:
        plVar16 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,lRam000000023eed7280);
        if ((plVar16 != (longlong *)0x0) && (*plVar16 != 0)) goto LAB_23e7d0263;
        FUN_23e915740(param_1,&plStack_78,lRam000000023eed7280);
        pcStack_d8._0_4_ = 0x93;
        *plVar15 = *plVar15 + -1;
        pcVar19 = pcStack_68;
        plVar16 = plStack_78;
        pcVar22 = pcStack_70;
        if (*plVar15 != 0) goto LAB_23e7d0a4e;
LAB_23e7d20f4:
        FUN_23a334bc0(plVar15);
        goto LAB_23e7d0a4e;
      }
      plVar16 = (longlong *)FUN_23a37a020(_DAT_23eede1c0,lRam000000023eed7280);
      if (plVar16 == (longlong *)0x0) goto LAB_23e7d2270;
      lVar12 = *plVar16;
LAB_23e7d2267:
      if (lVar12 == 0) goto LAB_23e7d2270;
LAB_23e7d0263:
      *(undefined4 *)(plVar6 + 5) = 0x93;
      plVar16 = (longlong *)FUN_23e914090(param_1,plVar15);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      if (plVar16 == (longlong *)0x0) goto LAB_23e7d2305;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      lVar12 = FUN_23e8ddf60();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,uRam000000023eed7250);
        pcStack_d8._0_4_ = 0x94;
        pcVar19 = pcStack_68;
        plVar16 = plStack_78;
        pcVar22 = pcStack_70;
        goto LAB_23e7d0a4e;
      }
      *(undefined4 *)(plVar6 + 5) = 0x94;
      plVar16 = (longlong *)FUN_23e91bfe0(param_1,lVar12,uRam000000023eed7278);
      if (plVar16 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x94;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = *(code **)(param_1 + 0x68);
        goto LAB_23e7d0a4e;
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      lVar12 = FUN_23e8de0b0();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,uRam000000023eed7260);
        pcStack_d8._0_4_ = 0x96;
        pcVar19 = pcStack_68;
        plVar16 = plStack_78;
        pcVar22 = pcStack_70;
        goto LAB_23e7d0a4e;
      }
      *(undefined4 *)(plVar6 + 5) = 0x96;
      plVar16 = (longlong *)FUN_23e915840(param_1,lVar12,uRam000000023eed7268);
      if (plVar16 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x96;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = *(code **)(param_1 + 0x68);
        goto LAB_23e7d0a4e;
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      lVar12 = FUN_23e8ddf60();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,uRam000000023eed7250);
        pcStack_d8._0_4_ = 0x99;
        pcVar19 = pcStack_68;
        plVar16 = plStack_78;
        pcVar22 = pcStack_70;
        goto LAB_23e7d0a4e;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar12,uRam000000023eed7258);
      if (plVar15 == (longlong *)0x0) {
LAB_23e7d211f:
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = *(code **)(param_1 + 0x68);
        pcStack_d8._0_4_ = 0x99;
        goto LAB_23e7d0a4e;
      }
      plVar18 = (longlong *)FUN_23a388650(param_1,plStack_f0,DAT_23ed6ccf0);
      if (plVar18 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x99;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) goto LAB_23e7d20f4;
        goto LAB_23e7d0a4e;
      }
      pcVar19 = (code *)FUN_23a388650(param_1,plStack_f0,DAT_23ed6ccf8,1);
      if (pcVar19 == (code *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          FUN_23a334bc0(plVar15);
        }
        *plVar18 = *plVar18 + -1;
        pcStack_d8._0_4_ = 0x99;
        if (*plVar18 == 0) {
          FUN_23a334bc0(plVar18);
          pcStack_d8._0_4_ = 0x99;
        }
        goto LAB_23e7d0a4e;
      }
      *(undefined4 *)(plVar6 + 5) = 0x99;
      plStack_78 = plVar18;
      pcStack_70 = pcVar19;
      plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar15,&plStack_78);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0();
      }
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        FUN_23a334bc0();
      }
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
      if (*(longlong *)pcVar19 == 0) {
        FUN_23a334bc0();
      }
      if (plVar16 == (longlong *)0x0) goto LAB_23e7d211f;
      lVar12 = *plVar16;
      *plVar16 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plVar16);
      }
      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
      pcVar19 = _Py_TrueStruct_exref;
      *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
        goto LAB_23e7cf89a;
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) goto LAB_23e7d0550;
      goto LAB_23e7cf8a9;
    }
    FUN_23e915740(param_1,&plStack_78,uRam000000023eed70c0);
    plVar13 = (longlong *)0x0;
    pcVar19 = pcStack_68;
    plVar16 = plStack_78;
    pcVar22 = pcStack_70;
LAB_23e7d1519:
    pcVar17 = (code *)0x0;
    plVar14 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    pcStack_d8._0_4_ = 0x7e;
    plStack_f0 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    pcStack_d0 = _Py_NoneStruct_exref;
LAB_23e7d0a4e:
    while( true ) {
      plVar15 = *(longlong **)(param_1 + 0x138);
      auStack_98._8_8_ = pcVar22;
      auStack_98._0_8_ = plVar16;
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
      }
      pcVar22 = DAT_23ed6a4f8;
      apcStack_88[0] = pcVar19;
      if (pcVar19 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar19 = *(code **)DAT_23ed6a4f8;
          *(undefined8 *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar19;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcStack_c0 = _PyRuntime_exref;
        *(longlong *)(pcVar22 + 0x10) = 0;
        *(longlong **)(pcVar22 + 0x18) = plVar6;
        *plVar6 = *plVar6 + 1;
        lVar12 = *(longlong *)(pcStack_c0 + 0x1f8);
        *(undefined4 *)(pcVar22 + 0x24) = pcStack_d8._0_4_;
        lVar12 = *(longlong *)(lVar12 + 0x10);
        *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
        lVar12 = *(longlong *)(lVar12 + 0x2e8);
        lVar5 = *(longlong *)(pcVar22 + -8);
        plVar16 = *(longlong **)(lVar12 + 8);
        *plVar16 = (longlong)(pcVar22 + -0x10);
        *(longlong *)(pcVar22 + -0x10) = lVar12;
        *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar5 & 3) | (ulonglong)plVar16;
        *(code **)(lVar12 + 8) = pcVar22 + -0x10;
        if ((apcStack_88[0] != (code *)0x0) &&
           (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
           *(longlong *)apcStack_88[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar8 = *(code **)DAT_23ed6a4f8;
          *(undefined8 *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar8;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcStack_c0 = _PyRuntime_exref;
        *(longlong **)(pcVar22 + 0x18) = plVar6;
        *plVar6 = *plVar6 + 1;
        lVar12 = *(longlong *)(pcStack_c0 + 0x1f8);
        *(undefined4 *)(pcVar22 + 0x24) = pcStack_d8._0_4_;
        lVar12 = *(longlong *)(lVar12 + 0x10);
        *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
        lVar12 = *(longlong *)(lVar12 + 0x2e8);
        lVar5 = *(longlong *)(pcVar22 + -8);
        plVar16 = *(longlong **)(lVar12 + 8);
        *plVar16 = (longlong)(pcVar22 + -0x10);
        *(longlong *)(pcVar22 + -0x10) = lVar12;
        *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar5 & 3) | (ulonglong)plVar16;
        *(code **)(lVar12 + 8) = pcVar22 + -0x10;
        *(code **)(pcVar22 + 0x10) = pcVar19;
        *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
        if ((apcStack_88[0] != (code *)0x0) &&
           (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
           *(longlong *)apcStack_88[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
        }
      }
      apcStack_88[0] = pcVar22;
      if (((code *)auStack_98._0_8_ != (code *)0x0) && ((code *)auStack_98._0_8_ != pcStack_d0)) {
        FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
      }
      plVar16 = *(longlong **)(auStack_98._8_8_ + 0x28);
      if (apcStack_88[0] == pcStack_d0) {
        pcVar19 = (code *)0x0;
      }
      else {
        pcVar19 = apcStack_88[0];
        if (apcStack_88[0] != (code *)0x0) {
          *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
        }
      }
      *(code **)(auStack_98._8_8_ + 0x28) = pcVar19;
      if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
        (**(code **)(plVar16[1] + 0x30))();
      }
      plVar16 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
      if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
        (**(code **)(plVar16[1] + 0x30))();
      }
      *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
      if (*(longlong *)auStack_98._0_8_ == 0) {
        (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
      }
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
      }
      apcStack_88[0] = (code *)0x0;
      auStack_98 = (undefined1  [16])0x0;
      iVar9 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                            *(undefined8 *)PyExc_Exception_exref);
      if (iVar9 == 0) {
        pcVar22 = *(code **)(param_1 + 0x138);
        if ((pcVar22 == pcStack_d0) || (pcVar22 == (code *)0x0)) {
          pcStack_d0 = *(code **)PyExc_RuntimeError_exref;
          pcStack_d8 = (code *)PyUnicode_FromString("No active exception to reraise");
          pcVar22 = *(code **)(param_1 + 0x138);
          *(longlong *)pcStack_d0 = *(longlong *)pcStack_d0 + 1;
          iVar9 = 0x7c;
          *(longlong **)(param_1 + 0x138) = plVar15;
          if ((pcVar22 == (code *)0x0) ||
             (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 != 0))
          goto LAB_23e7d1100;
          pcVar19 = (code *)0x0;
          goto LAB_23e7d1313;
        }
        pcStack_d0 = *(code **)(pcVar22 + 8);
        *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
        *(longlong *)pcStack_d0 = *(longlong *)pcStack_d0 + 1;
        pcVar19 = *(code **)(pcVar22 + 0x28);
        iVar9 = 0;
        pcStack_d8 = pcVar22;
        if (pcVar19 == (code *)0x0) {
          *(longlong **)(param_1 + 0x138) = plVar15;
          lVar12 = *(longlong *)pcVar22;
          *(longlong *)pcVar22 = lVar12 + -1;
          if (lVar12 + -1 != 0) goto LAB_23e7d134c;
          goto LAB_23e7d1313;
        }
        *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
        if (plVar6 == *(longlong **)(pcVar19 + 0x18)) {
          *(undefined4 *)(plVar6 + 5) = *(undefined4 *)(pcVar19 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar15;
        lVar12 = *(longlong *)pcVar22;
        *(longlong *)pcVar22 = lVar12 + -1;
        if (lVar12 + -1 != 0) {
          pcVar22 = pcVar19;
          if (plVar6 == *(longlong **)(pcVar19 + 0x18)) goto LAB_23e7d06b0;
          goto LAB_23e7d0fd4;
        }
        (**(code **)((longlong)pcStack_d0 + 0x30))();
        goto LAB_23e7d0fc1;
      }
      plVar16 = *(longlong **)(param_1 + 0x138);
      *plVar16 = *plVar16 + 1;
      uVar20 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar21 = plRam000000023eed7288;
      lVar12 = *(longlong *)(param_1 + 0x10);
      plVar18 = *(longlong **)(lVar12 + 0xe20);
      if (plVar18 == (longlong *)0x0) {
        plVar18 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar5 = plVar18[3];
        *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
        *(longlong *)(lVar12 + 0xe20) = lVar5;
        *plVar18 = 1;
      }
      plVar18[4] = 0;
      lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_c0 + 0x1f8) + 0x10) + 0x2e8);
      lVar5 = plVar18[-1];
      puVar7 = *(undefined8 **)(lVar12 + 8);
      *puVar7 = plVar18 + -2;
      plVar18[-2] = lVar12;
      plVar18[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar7;
      *(longlong **)(lVar12 + 8) = plVar18 + -2;
      *plVar21 = *plVar21 + 1;
      plVar18[3] = (longlong)plVar21;
      uVar1 = DAT_23ed6cd28;
      if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23e7d0d32;
      plVar21 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar21 != (longlong *)0x0) break;
      PyErr_PrintEx(0);
      Py_Exit(1);
LAB_23e7d1b6f:
      plVar16 = *(longlong **)(param_1 + 0x60);
      pcVar22 = *(code **)(param_1 + 0x68);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      lVar12 = *plStack_100;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plStack_100 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plStack_100);
        pcStack_d8 = pcVar19;
LAB_23e7d1a70:
        pcStack_d0 = _Py_NoneStruct_exref;
        pcVar17 = (code *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcVar19 = pcStack_d8;
        pcStack_d8._0_4_ = 0x82;
      }
      else {
LAB_23e7d1abe:
        pcVar17 = (code *)0x0;
        plStack_f0 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x82;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d0 = _Py_NoneStruct_exref;
      }
    }
    *plVar21 = *plVar21 + 1;
    DAT_23ed6a4c0 = plVar21;
LAB_23e7d0d32:
    plStack_a8 = plVar16;
    uStack_a0 = uVar1;
    lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_a8);
    if (lVar12 == 0) {
      pcStack_d0 = *(code **)(param_1 + 0x60);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
    }
    else {
      plVar18[4] = lVar12;
      plVar21 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar18);
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
      if (plVar21 != (longlong *)0x0) {
        *(undefined4 *)(plVar6 + 5) = 0x9e;
        plVar18 = (longlong *)FUN_23e914090(param_1,uVar20);
        *plVar21 = *plVar21 + -1;
        if (*plVar21 == 0) {
          (**(code **)(plVar21[1] + 0x30))(plVar21);
        }
        if (plVar18 != (longlong *)0x0) {
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          pcVar19 = _Py_FalseStruct_exref;
          *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          plVar6 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar15;
          if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
            (**(code **)(plVar6[1] + 0x30))();
          }
          goto LAB_23e7cf837;
        }
      }
      pcStack_d0 = *(code **)(param_1 + 0x60);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    pcVar22 = *(code **)(param_1 + 0x138);
    *(longlong **)(param_1 + 0x138) = plVar15;
    if ((pcVar22 != (code *)0x0) &&
       (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
      iVar9 = 0x9e;
LAB_23e7d1313:
      (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))();
      if (pcVar19 != (code *)0x0) {
LAB_23e7d0fc1:
        pcVar22 = pcVar19;
        if (plVar6 == *(longlong **)(pcVar19 + 0x18)) goto LAB_23e7d06b0;
        if (iVar9 == 0) {
LAB_23e7d0fd4:
          iVar9 = (int)plVar6[5];
        }
        goto LAB_23e7d0613;
      }
      if (iVar9 == 0) {
LAB_23e7d134c:
        iVar9 = (int)plVar6[5];
      }
      goto LAB_23e7d1100;
    }
    iVar9 = 0x9e;
    if (pcVar19 == (code *)0x0) goto LAB_23e7d1100;
    pcVar22 = pcVar19;
    if (plVar6 == *(longlong **)(pcVar19 + 0x18)) goto LAB_23e7d06b0;
    iVar9 = 0x9e;
  }
LAB_23e7d0613:
  pcVar22 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar8 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar8;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar22 + 0x18) = plVar6;
  *plVar6 = *plVar6 + 1;
  lVar12 = *(longlong *)(pcStack_c0 + 0x1f8);
  *(int *)(pcVar22 + 0x24) = iVar9;
  *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
  lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
  lVar5 = *(longlong *)(pcVar22 + -8);
  plVar16 = *(longlong **)(lVar12 + 8);
  *plVar16 = (longlong)(pcVar22 + -0x10);
  *(longlong *)(pcVar22 + -0x10) = lVar12;
  *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar5 & 3) | (ulonglong)plVar16;
  lVar5 = *(longlong *)pcVar19;
  *(code **)(lVar12 + 8) = pcVar22 + -0x10;
  *(code **)(pcVar22 + 0x10) = pcVar19;
  if (lVar5 == 0) {
    (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
  }
LAB_23e7d06b0:
  FUN_23e8bba40(plVar6,"oooooooooooo",plVar3,plVar2,plVar4,plVar13,plVar11,plVar14,plStack_108,
                plStack_100,pcVar17,plStack_f8,plStack_f0,0);
  if (_DAT_23eeded28 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eeded28 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar12 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  plVar16 = (longlong *)plVar6[2];
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar16 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar12 = *plStack_108, *plStack_108 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar12 = *plStack_100, *plStack_100 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar12 = *plStack_f8, *plStack_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((plStack_f0 != (longlong *)0x0) &&
     (lVar12 = *plStack_f0, *plStack_f0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar12 = *plVar2;
  *plVar2 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar12 = *plVar4;
  *plVar4 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,pcStack_d0,pcStack_d8,pcVar22);
  return (code *)0x0;
}
