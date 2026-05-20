/* ===== 23e82ba40 workers.fishing.store_fish:109 ===== */
/* ghidra_name=FUN_23e82ba40 entry=23e82ba40 size=10649 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e82ba40(longlong param_1,undefined8 param_2,longlong *param_3)

{
  undefined8 uVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
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
  longlong *plVar17;
  code *pcVar18;
  longlong lVar19;
  longlong *plVar20;
  code *pcVar21;
  undefined8 uVar22;
  longlong *plVar23;
  code *pcVar24;
  longlong *plStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
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
  
  plVar11 = _DAT_23eede6a0;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  plVar4 = (longlong *)param_3[2];
  plVar5 = (longlong *)param_3[3];
  if (_DAT_23eede6a0 == (longlong *)0x0) {
LAB_23e82bab1:
    _DAT_23eede6a0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede698,DAT_23eede708,0x68);
  }
  else {
    lVar12 = *_DAT_23eede6a0;
    if (1 < lVar12) {
      *_DAT_23eede6a0 = lVar12 + -1;
      goto LAB_23e82bab1;
    }
    if (_DAT_23eede6a0[2] != 0) {
      *_DAT_23eede6a0 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e82bab1;
    }
  }
  plVar6 = _DAT_23eede6a0;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eede6a0 + 9;
  lVar19 = *(longlong *)(lVar12 + 8);
  _DAT_23eede6a0[0xf] = lVar19;
  *(longlong **)(lVar12 + 8) = plVar11;
  if ((lVar19 != 0) &&
     (((*(char *)(lVar19 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar19 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar19 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar19 + 0x38))) && (plVar6[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar19 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  uVar22 = DAT_23eedc808;
  *(undefined4 *)(plVar6 + 8) = 0;
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,uVar22);
  if (plVar11 == (longlong *)0x0) {
    pcStack_d0 = *(code **)(param_1 + 0x60);
    pcStack_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_d8 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_68 == (code *)0x0) goto LAB_23e82d63e;
LAB_23e82c805:
    plVar11 = *(longlong **)(pcStack_68 + 0x18);
    pcVar21 = pcStack_68;
joined_r0x00023e82c809:
    if (plVar6 == plVar11) {
LAB_23e82cc62:
      pcVar18 = (code *)0x0;
      plVar16 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      pcVar24 = pcVar21;
      goto LAB_23e82c900;
    }
LAB_23e82c83d:
    pcVar18 = (code *)0x0;
    plVar16 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    iVar9 = 0x6f;
    pcStack_c0 = _PyRuntime_exref;
LAB_23e82c861:
    pcVar24 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar8 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar24 + 0x18) = plVar6;
    *plVar6 = *plVar6 + 1;
    lVar12 = *(longlong *)(pcStack_c0 + 0x1f8);
    *(int *)(pcVar24 + 0x24) = iVar9;
    *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar19 = *(longlong *)(pcVar24 + -8);
    plVar17 = *(longlong **)(lVar12 + 8);
    *plVar17 = (longlong)(pcVar24 + -0x10);
    *(longlong *)(pcVar24 + -0x10) = lVar12;
    *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)plVar17;
    lVar19 = *(longlong *)pcVar21;
    *(code **)(lVar12 + 8) = pcVar24 + -0x10;
    *(code **)(pcVar24 + 0x10) = pcVar21;
    if (lVar19 == 0) {
      (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
    }
    goto LAB_23e82c900;
  }
  iVar9 = FUN_23a35f020(plVar11);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (iVar9 == -1) {
LAB_23e82cbb0:
    pcStack_d0 = *(code **)(param_1 + 0x60);
    pcVar21 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_d8 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar21 != (code *)0x0) {
      plVar11 = *(longlong **)(pcVar21 + 0x18);
      goto joined_r0x00023e82d975;
    }
    goto LAB_23e82d63e;
  }
  if (iVar9 == 0) {
LAB_23e82bb79:
    pcVar21 = _Py_FalseStruct_exref;
    plVar16 = (longlong *)0x0;
    pcVar18 = (code *)0x0;
    plVar14 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
    plStack_100 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
LAB_23e82bbb5:
    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar6 = *(longlong **)(lVar12 + 0x28);
    plVar17 = (longlong *)plVar6[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
    *(undefined4 *)(plVar6 + 8) = 0xffffffff;
    if (plVar17 != (longlong *)0x0) {
      plVar6[2] = 0;
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        (**(code **)(plVar17[1] + 0x30))();
      }
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    plVar6[0xf] = 0;
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar13 != (longlong *)0x0) {
LAB_23e82bc17:
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
LAB_23e82c7a0:
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
    }
    if (plVar14 == (longlong *)0x0) goto LAB_23e82bc32;
LAB_23e82bc27:
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
LAB_23e82bc32:
    if ((plStack_108 != (longlong *)0x0) &&
       (lVar12 = *plStack_108, *plStack_108 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_108[1] + 0x30))(plStack_108);
    }
    if ((plStack_100 != (longlong *)0x0) &&
       (lVar12 = *plStack_100, *plStack_100 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_100[1] + 0x30))(plStack_100);
    }
    if ((pcVar18 != (code *)0x0) &&
       (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
      (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
    }
    if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    if ((plStack_f8 != (longlong *)0x0) &&
       (lVar12 = *plStack_f8, *plStack_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
    }
    lVar12 = *plVar2;
    *plVar2 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    lVar12 = *plVar3;
    *plVar3 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    lVar12 = *plVar4;
    *plVar4 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    lVar12 = *plVar5;
    *plVar5 = lVar12 + -1;
    if (lVar12 + -1 != 0) {
      return pcVar21;
    }
    (**(code **)(plVar5[1] + 0x30))(plVar5);
    return pcVar21;
  }
  lVar12 = FUN_23e8dbf70();
  if (lVar12 == 0) {
    FUN_23e915740(param_1,&plStack_78,DAT_23eedc820);
    pcStack_d0 = (code *)plStack_78;
    pcStack_d8 = pcStack_70;
    if (pcStack_68 != (code *)0x0) goto LAB_23e82c805;
LAB_23e82d63e:
    pcVar18 = (code *)0x0;
    plVar16 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    iVar9 = 0x6f;
    pcStack_c0 = _PyRuntime_exref;
  }
  else {
    plVar11 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23eedc878);
    if (plVar11 == (longlong *)0x0) {
      pcStack_d0 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar21 != (code *)0x0) {
        plVar11 = *(longlong **)(pcVar21 + 0x18);
        goto joined_r0x00023e82c809;
      }
      goto LAB_23e82d63e;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedc808);
    if (plVar13 == (longlong *)0x0) {
      pcStack_d0 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        if (pcVar21 != (code *)0x0) {
          plVar11 = *(longlong **)(pcVar21 + 0x18);
joined_r0x00023e82d975:
          if (plVar11 != plVar6) goto LAB_23e82c83d;
          goto LAB_23e82cc62;
        }
      }
      else if (pcVar21 != (code *)0x0) {
        plVar11 = *(longlong **)(pcVar21 + 0x18);
        goto joined_r0x00023e82d975;
      }
      goto LAB_23e82d63e;
    }
    *(undefined4 *)(plVar6 + 5) = 0x6f;
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
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar11 = (longlong *)0x0;
      if (pcVar21 != (code *)0x0) {
        if (plVar6 == *(longlong **)(pcVar21 + 0x18)) {
          plVar16 = (longlong *)0x0;
          pcVar18 = (code *)0x0;
          plVar14 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          pcVar24 = pcVar21;
          goto LAB_23e82c900;
        }
        goto LAB_23e82c83d;
      }
      goto LAB_23e82d63e;
    }
    uVar10 = FUN_23a35f020(plVar14);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if (uVar10 == 0xffffffff) goto LAB_23e82cbb0;
    if ((uVar10 & 1) == 0) goto LAB_23e82bb79;
    lVar12 = FUN_23e8dbf70();
    if (lVar12 != 0) {
      plVar13 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eedc988);
      pcStack_d0 = _Py_NoneStruct_exref;
      if (plVar13 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x70);
        plVar16 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar18 = (code *)0x0;
        plStack_f8 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x74;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e82cced;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedc808);
      if (plVar14 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        plVar16 = (longlong *)0x0;
        pcVar18 = (code *)0x0;
        plVar13 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x74;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d0 = _Py_NoneStruct_exref;
        plVar14 = (longlong *)0x0;
        goto LAB_23e82cced;
      }
      *(undefined4 *)(plVar6 + 5) = 0x74;
      plVar11 = (longlong *)FUN_23e914090(param_1,plVar13,plVar14);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar11 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar17 = *(longlong **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e82d739;
      }
      lVar12 = FUN_23e8dbf70();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,DAT_23eedc820);
        plVar13 = (longlong *)0x0;
        pcVar21 = pcStack_68;
        plVar17 = plStack_78;
        pcVar24 = pcStack_70;
LAB_23e82daef:
        plVar16 = (longlong *)0x0;
        pcVar18 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x75;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d0 = _Py_NoneStruct_exref;
        goto LAB_23e82cced;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23eedc888);
      pcStack_d0 = _Py_NoneStruct_exref;
      if (plVar15 == (longlong *)0x0) {
        plVar16 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar18 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x75;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto LAB_23e82cced;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedc808);
      if (plVar14 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar12 = *plVar15;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar15 = lVar12 + -1;
        plVar14 = (longlong *)0x0;
        if (lVar12 + -1 == 0) {
          plVar16 = (longlong *)0x0;
          pcVar18 = (code *)0x0;
          plVar13 = (longlong *)0x0;
          (**(code **)(plVar15[1] + 0x30))();
          pcStack_d8._0_4_ = 0x75;
          plStack_f8 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          pcStack_d0 = _Py_NoneStruct_exref;
        }
        else {
          plVar16 = (longlong *)0x0;
          pcVar18 = (code *)0x0;
          plVar13 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          pcStack_d8._0_4_ = 0x75;
          plStack_100 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          pcStack_d0 = _Py_NoneStruct_exref;
        }
        goto LAB_23e82cced;
      }
      *(undefined4 *)(plVar6 + 5) = 0x75;
      plVar13 = (longlong *)FUN_23e914090(param_1,plVar15,plVar14);
      lVar12 = *plVar15;
      *plVar15 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar13 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar17 = *(longlong **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e82daef;
      }
      plStack_108 = (longlong *)FUN_23a388650(param_1,plVar11,_DAT_23eedc990,2);
      if (plStack_108 == (longlong *)0x0) {
LAB_23e82db36:
        pcStack_d0 = _Py_NoneStruct_exref;
        plVar16 = (longlong *)0x0;
        pcVar18 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        pcVar21 = *(code **)(param_1 + 0x70);
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d8._0_4_ = 0x78;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e82cced;
      }
      plVar14 = (longlong *)FUN_23a388650(param_1,plVar11,DAT_23ed6ccf0,0);
      if (plVar14 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar12 = *plStack_108;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plStack_108 = lVar12 + -1;
        plVar14 = (longlong *)0x0;
        if (lVar12 + -1 != 0) goto LAB_23e82dcee;
        (**(code **)(plStack_108[1] + 0x30))();
        pcStack_d8 = pcVar21;
        goto LAB_23e82dc97;
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
        plVar16 = (longlong *)0x0;
        pcVar18 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        pcVar21 = *(code **)(param_1 + 0x70);
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d8._0_4_ = 0x78;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e82cced;
      }
      plVar16 = (longlong *)FUN_23a388650(param_1,plVar13,_DAT_23eedc990,2);
      plVar14 = (longlong *)0x0;
      if (plVar16 == (longlong *)0x0) goto LAB_23e82dd99;
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
      if (plStack_108 == (longlong *)0x0) goto LAB_23e82db36;
      if ((code *)plStack_108[1] == PyLong_Type_exref) {
        plVar14 = (longlong *)
                  (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0xe8))
                            (plStack_108,_DAT_23eedc990);
        lVar12 = *plStack_108 + -1;
        *plStack_108 = lVar12;
        if (plVar14 == (longlong *)0x0) {
          if (lVar12 == 0) {
            (**(code **)(plStack_108[1] + 0x30))();
          }
          goto LAB_23e82de34;
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
          (**(code **)(plStack_108[1] + 0x30))(plStack_108);
        }
        if (plVar14 == (longlong *)0x0) {
LAB_23e82de34:
          pcStack_d0 = _Py_NoneStruct_exref;
          plVar17 = *(longlong **)(param_1 + 0x60);
          pcVar24 = *(code **)(param_1 + 0x68);
          pcVar21 = *(code **)(param_1 + 0x70);
          pcVar18 = (code *)0x0;
          plStack_f8 = (longlong *)0x0;
          pcStack_d8._0_4_ = 0x78;
          plVar16 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e82cced;
        }
      }
      plStack_100 = (longlong *)FUN_23a388650(param_1,plVar11,_DAT_23eedc998,3);
      if (plStack_100 == (longlong *)0x0) {
LAB_23e82de8d:
        pcVar21 = *(code **)(param_1 + 0x70);
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d0 = _Py_NoneStruct_exref;
        plVar16 = (longlong *)0x0;
        pcVar18 = (code *)0x0;
        pcStack_d8._0_4_ = 0x79;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e82cced;
      }
      plVar16 = (longlong *)FUN_23a388650(param_1,plVar11);
      if (plVar16 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar12 = *plStack_100 + -1;
        *plStack_100 = lVar12;
        plVar15 = plStack_100;
joined_r0x00023e82df08:
        plStack_108 = (longlong *)0x0;
        if (lVar12 == 0) {
          plStack_108 = (longlong *)0x0;
          FUN_23a334bc0(plVar15);
          plVar16 = (longlong *)0x0;
          pcVar18 = (code *)0x0;
          plStack_f8 = (longlong *)0x0;
          pcStack_d8._0_4_ = 0x79;
          plStack_100 = (longlong *)0x0;
          pcStack_d0 = _Py_NoneStruct_exref;
          goto LAB_23e82cced;
        }
LAB_23e82df6a:
        plVar16 = (longlong *)0x0;
        pcVar18 = (code *)0x0;
        plStack_f8 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x79;
        plStack_100 = (longlong *)0x0;
        pcStack_d0 = _Py_NoneStruct_exref;
        goto LAB_23e82cced;
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
      pcStack_d0 = _Py_NoneStruct_exref;
      if (plVar15 == (longlong *)0x0) {
        plVar16 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        pcVar21 = *(code **)(param_1 + 0x70);
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d8._0_4_ = 0x79;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar18 = (code *)0x0;
        goto LAB_23e82cced;
      }
      plVar16 = (longlong *)FUN_23a388650(param_1,plVar13,_DAT_23eedc998,3);
      if (plVar16 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar15 = *plVar15 + -1;
        lVar12 = *plVar15;
        goto joined_r0x00023e82df08;
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
      if (plStack_100 == (longlong *)0x0) goto LAB_23e82de8d;
      plStack_108 = (longlong *)FUN_23e8c6640(plStack_100,plVar14);
      lVar12 = *plStack_100;
      *plStack_100 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0();
      }
      if (plStack_108 == (longlong *)0x0) {
        pcVar21 = *(code **)(param_1 + 0x70);
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e82df6a;
      }
      plStack_100 = (longlong *)FUN_23a388650(param_1,plVar11,DAT_23ed6ccf0,0);
      if (plStack_100 == (longlong *)0x0) {
LAB_23e82e01f:
        pcStack_d0 = _Py_NoneStruct_exref;
        plVar16 = (longlong *)0x0;
        pcVar18 = (code *)0x0;
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        plStack_f8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d8._0_4_ = 0x7c;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e82cced;
      }
      plVar16 = (longlong *)FUN_23e8c09e0(plStack_100,plVar14);
      lVar12 = *plStack_100;
      *plStack_100 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plStack_100);
      }
      pcStack_d0 = _Py_NoneStruct_exref;
      if (plVar16 == (longlong *)0x0) {
        plVar16 = (longlong *)0x0;
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        plStack_f8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d8._0_4_ = 0x7c;
        plStack_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar18 = (code *)0x0;
        goto LAB_23e82cced;
      }
      plStack_100 = (longlong *)FUN_23e8c09e0(plVar16,plVar3);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      if (plStack_100 == (longlong *)0x0) goto LAB_23e82e01f;
      plVar16 = (longlong *)FUN_23a388650(param_1,plVar11);
      pcVar18 = (code *)0x0;
      if (plVar16 == (longlong *)0x0) {
LAB_23e82e0e4:
        pcStack_d0 = _Py_NoneStruct_exref;
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar16 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x7d;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e82cced;
      }
      plVar17 = (longlong *)FUN_23e8c09e0(plVar16,plStack_108);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      pcStack_d0 = _Py_NoneStruct_exref;
      if (plVar17 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar18 = (code *)0x0;
        pcStack_d8._0_4_ = 0x7d;
        plStack_f8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar16 = (longlong *)0x0;
        goto LAB_23e82cced;
      }
      pcVar18 = (code *)FUN_23e8c09e0(plVar17,plVar4);
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        FUN_23a334bc0(plVar17);
      }
      pcStack_d0 = _Py_NoneStruct_exref;
      uVar22 = _DAT_23eedc9a0;
      if (pcVar18 == (code *)0x0) goto LAB_23e82e0e4;
      *(undefined4 *)(plVar6 + 5) = 0x80;
      plVar16 = (longlong *)
                FUN_23e95c160(param_1,uVar22,DAT_23eedc7f0,pcStack_d0,pcStack_d0,DAT_23ed6ccf0);
      if (plVar16 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        plStack_f8 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x80;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e82cced;
      }
      *(undefined4 *)(plVar6 + 5) = 0x81;
      plStack_f8 = (longlong *)FUN_23e91bfe0(param_1,plVar16,_DAT_23eedc9a8);
      if (plStack_f8 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x81;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e82cced;
      }
      lVar12 = FUN_23e8dba30();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,_DAT_23eedc9b0);
        pcStack_d8._0_4_ = 0x84;
        pcVar21 = pcStack_68;
        plVar17 = plStack_78;
        pcVar24 = pcStack_70;
        goto LAB_23e82cced;
      }
      *(undefined4 *)(plVar6 + 5) = 0x84;
      plStack_78 = plStack_100;
      pcStack_70 = pcVar18;
      plVar17 = (longlong *)FUN_23e954670(param_1,lVar12,_DAT_23eedc9b8,&plStack_78);
      if (plVar17 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x84;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e82cced;
      }
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        FUN_23a334bc0(plVar17);
      }
      lVar19 = FUN_23e8dbb80();
      lVar12 = _DAT_23eedc9d0;
      if (lVar19 == 0) {
        FUN_23e915740(param_1,&plStack_78,_DAT_23eedc9c0);
        pcStack_d8._0_4_ = 0x85;
        pcVar21 = pcStack_68;
        plVar17 = plStack_78;
        pcVar24 = pcStack_70;
        goto LAB_23e82cced;
      }
      *(undefined4 *)(plVar6 + 5) = 0x85;
      plVar17 = (longlong *)
                FUN_23e915840(param_1,lVar19,_DAT_23eedc9c8,*(undefined8 *)(lVar12 + 0x18));
      if (plVar17 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x85;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e82cced;
      }
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        FUN_23a334bc0(plVar17);
      }
      iVar9 = FUN_23e913250(plVar5,_DAT_23eedc9d8);
      if (iVar9 == -1) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x87;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e82cced;
      }
      if (iVar9 == 1) {
        lVar12 = FUN_23e8dba30();
        if (lVar12 == 0) {
          FUN_23e915740(param_1,&plStack_78,_DAT_23eedc9b0);
          pcStack_d8._0_4_ = 0x88;
          pcVar21 = pcStack_68;
          plVar17 = plStack_78;
          pcVar24 = pcStack_70;
        }
        else {
          *(undefined4 *)(plVar6 + 5) = 0x88;
          plVar17 = (longlong *)FUN_23e91bfe0(param_1,lVar12,_DAT_23eedc9e0);
          if (plVar17 != (longlong *)0x0) goto LAB_23e82c54d;
          plVar17 = *(longlong **)(param_1 + 0x60);
          pcVar21 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcStack_d8._0_4_ = 0x88;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar24 = *(code **)(param_1 + 0x68);
        }
        goto LAB_23e82cced;
      }
      lVar12 = FUN_23e8dba30();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,_DAT_23eedc9b0);
        pcStack_d8._0_4_ = 0x8a;
        pcVar21 = pcStack_68;
        plVar17 = plStack_78;
        pcVar24 = pcStack_70;
        goto LAB_23e82cced;
      }
      *(undefined4 *)(plVar6 + 5) = 0x8a;
      plVar17 = (longlong *)FUN_23e91bfe0(param_1,lVar12,_DAT_23eedc9e8);
      if (plVar17 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x8a;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e82cced;
      }
LAB_23e82c54d:
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        FUN_23a334bc0();
      }
      lVar19 = FUN_23e8dbb80();
      lVar12 = _DAT_23eedc9d0;
      if (lVar19 == 0) {
        FUN_23e915740(param_1,&plStack_78,_DAT_23eedc9c0);
        pcStack_d8._0_4_ = 0x8c;
        pcVar21 = pcStack_68;
        plVar17 = plStack_78;
        pcVar24 = pcStack_70;
        goto LAB_23e82cced;
      }
      *(undefined4 *)(plVar6 + 5) = 0x8c;
      plVar17 = (longlong *)
                FUN_23e915840(param_1,lVar19,_DAT_23eedc9c8,*(undefined8 *)(lVar12 + 0x18));
      if (plVar17 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x8c;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e82cced;
      }
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        FUN_23a334bc0(plVar17);
      }
      lVar12 = FUN_23e8dba30();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&plStack_78,_DAT_23eedc9b0);
        pcStack_d8._0_4_ = 0x8f;
        pcVar21 = pcStack_68;
        plVar17 = plStack_78;
        pcVar24 = pcStack_70;
        goto LAB_23e82cced;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eedc9b8);
      if (plVar15 == (longlong *)0x0) {
LAB_23e82e1f9:
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x68);
        pcStack_d8._0_4_ = 0x8f;
        goto LAB_23e82cced;
      }
      plVar20 = (longlong *)FUN_23a388650(param_1,plStack_f8,DAT_23ed6ccf0,0);
      if (plVar20 == (longlong *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_d8._0_4_ = 0x8f;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          FUN_23a334bc0(plVar15);
          pcStack_d8._0_4_ = 0x8f;
        }
        goto LAB_23e82cced;
      }
      pcVar21 = (code *)FUN_23a388650(param_1,plStack_f8,DAT_23ed6ccf8);
      if (pcVar21 == (code *)0x0) {
        plVar17 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          FUN_23a334bc0(plVar15);
        }
        *plVar20 = *plVar20 + -1;
        pcStack_d8._0_4_ = 0x8f;
        if (*plVar20 == 0) {
          FUN_23a334bc0(plVar20);
          pcStack_d8._0_4_ = 0x8f;
        }
        goto LAB_23e82cced;
      }
      *(undefined4 *)(plVar6 + 5) = 0x8f;
      plStack_78 = plVar20;
      pcStack_70 = pcVar21;
      plVar17 = (longlong *)FUN_23e94ed00(param_1,plVar15);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      *plVar20 = *plVar20 + -1;
      if (*plVar20 == 0) {
        FUN_23a334bc0(plVar20);
      }
      *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
      if (*(longlong *)pcVar21 == 0) {
        FUN_23a334bc0(pcVar21);
      }
      if (plVar17 == (longlong *)0x0) goto LAB_23e82e1f9;
      lVar12 = *plVar17;
      *plVar17 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plVar17);
      }
      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
      pcVar21 = _Py_TrueStruct_exref;
      *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        goto LAB_23e82bc17;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) goto LAB_23e82c7a0;
      goto LAB_23e82bc27;
    }
    FUN_23e915740(param_1,&plStack_78,DAT_23eedc820);
    plVar11 = (longlong *)0x0;
    pcVar21 = pcStack_68;
    plVar17 = plStack_78;
    pcVar24 = pcStack_70;
LAB_23e82d739:
    plVar16 = (longlong *)0x0;
    pcVar18 = (code *)0x0;
    plVar14 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    pcStack_d8._0_4_ = 0x74;
    plStack_100 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    pcStack_d0 = _Py_NoneStruct_exref;
LAB_23e82cced:
    while( true ) {
      plVar15 = *(longlong **)(param_1 + 0x138);
      auStack_98._8_8_ = pcVar24;
      auStack_98._0_8_ = plVar17;
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
      }
      pcVar24 = DAT_23ed6a4f8;
      apcStack_88[0] = pcVar21;
      if (pcVar21 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar21 = *(code **)DAT_23ed6a4f8;
          *(undefined8 *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar21;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcStack_c0 = _PyRuntime_exref;
        *(longlong *)(pcVar24 + 0x10) = 0;
        *(longlong **)(pcVar24 + 0x18) = plVar6;
        *plVar6 = *plVar6 + 1;
        lVar12 = *(longlong *)(pcStack_c0 + 0x1f8);
        *(undefined4 *)(pcVar24 + 0x24) = pcStack_d8._0_4_;
        lVar12 = *(longlong *)(lVar12 + 0x10);
        *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
        lVar12 = *(longlong *)(lVar12 + 0x2e8);
        lVar19 = *(longlong *)(pcVar24 + -8);
        plVar17 = *(longlong **)(lVar12 + 8);
        *plVar17 = (longlong)(pcVar24 + -0x10);
        *(longlong *)(pcVar24 + -0x10) = lVar12;
        *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)plVar17;
        *(code **)(lVar12 + 8) = pcVar24 + -0x10;
        if ((apcStack_88[0] != (code *)0x0) &&
           (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
           *(longlong *)apcStack_88[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar8 = *(code **)DAT_23ed6a4f8;
          *(undefined8 *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar8;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcStack_c0 = _PyRuntime_exref;
        *(longlong **)(pcVar24 + 0x18) = plVar6;
        *plVar6 = *plVar6 + 1;
        lVar12 = *(longlong *)(pcStack_c0 + 0x1f8);
        *(undefined4 *)(pcVar24 + 0x24) = pcStack_d8._0_4_;
        lVar12 = *(longlong *)(lVar12 + 0x10);
        *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
        lVar12 = *(longlong *)(lVar12 + 0x2e8);
        lVar19 = *(longlong *)(pcVar24 + -8);
        plVar17 = *(longlong **)(lVar12 + 8);
        *plVar17 = (longlong)(pcVar24 + -0x10);
        *(longlong *)(pcVar24 + -0x10) = lVar12;
        *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)plVar17;
        *(code **)(lVar12 + 8) = pcVar24 + -0x10;
        *(code **)(pcVar24 + 0x10) = pcVar21;
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
        if ((apcStack_88[0] != (code *)0x0) &&
           (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
           *(longlong *)apcStack_88[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
        }
      }
      apcStack_88[0] = pcVar24;
      if (((code *)auStack_98._0_8_ != (code *)0x0) && ((code *)auStack_98._0_8_ != pcStack_d0)) {
        FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
      }
      plVar17 = *(longlong **)(auStack_98._8_8_ + 0x28);
      if (apcStack_88[0] == pcStack_d0) {
        pcVar21 = (code *)0x0;
      }
      else {
        pcVar21 = apcStack_88[0];
        if (apcStack_88[0] != (code *)0x0) {
          *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
        }
      }
      *(code **)(auStack_98._8_8_ + 0x28) = pcVar21;
      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
        (**(code **)(plVar17[1] + 0x30))();
      }
      plVar17 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
        (**(code **)(plVar17[1] + 0x30))();
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
        pcVar24 = *(code **)(param_1 + 0x138);
        if ((pcVar24 == pcStack_d0) || (pcVar24 == (code *)0x0)) {
          pcStack_d0 = *(code **)PyExc_RuntimeError_exref;
          pcStack_d8 = (code *)PyUnicode_FromString("No active exception to reraise");
          pcVar24 = *(code **)(param_1 + 0x138);
          *(longlong *)pcStack_d0 = *(longlong *)pcStack_d0 + 1;
          iVar9 = 0x72;
          *(longlong **)(param_1 + 0x138) = plVar15;
          if ((pcVar24 == (code *)0x0) ||
             (*(longlong *)pcVar24 = *(longlong *)pcVar24 + -1, *(longlong *)pcVar24 != 0))
          goto LAB_23e82d380;
          pcVar21 = (code *)0x0;
          goto LAB_23e82d88e;
        }
        pcStack_d0 = *(code **)(pcVar24 + 8);
        *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
        *(longlong *)pcStack_d0 = *(longlong *)pcStack_d0 + 1;
        pcVar21 = *(code **)(pcVar24 + 0x28);
        iVar9 = 0;
        pcStack_d8 = pcVar24;
        if (pcVar21 == (code *)0x0) {
          *(longlong **)(param_1 + 0x138) = plVar15;
          lVar12 = *(longlong *)pcVar24;
          *(longlong *)pcVar24 = lVar12 + -1;
          if (lVar12 + -1 == 0) goto LAB_23e82d88e;
          goto LAB_23e82d8c7;
        }
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
        if (plVar6 == *(longlong **)(pcVar21 + 0x18)) {
          *(undefined4 *)(plVar6 + 5) = *(undefined4 *)(pcVar21 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar15;
        lVar12 = *(longlong *)pcVar24;
        *(longlong *)pcVar24 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
          (**(code **)((longlong)pcStack_d0 + 0x30))();
          goto LAB_23e82d250;
        }
        pcVar24 = pcVar21;
        if (*(longlong **)(pcVar21 + 0x18) != plVar6) goto LAB_23e82d263;
        goto LAB_23e82c900;
      }
      plVar17 = *(longlong **)(param_1 + 0x138);
      *plVar17 = *plVar17 + 1;
      uVar22 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar23 = _DAT_23eedc9f0;
      lVar12 = *(longlong *)(param_1 + 0x10);
      plVar20 = *(longlong **)(lVar12 + 0xe20);
      if (plVar20 == (longlong *)0x0) {
        plVar20 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar19 = plVar20[3];
        *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
        *(longlong *)(lVar12 + 0xe20) = lVar19;
        *plVar20 = 1;
      }
      plVar20[4] = 0;
      lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_c0 + 0x1f8) + 0x10) + 0x2e8);
      lVar19 = plVar20[-1];
      puVar7 = *(undefined8 **)(lVar12 + 8);
      *puVar7 = plVar20 + -2;
      plVar20[-2] = lVar12;
      plVar20[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar7;
      *(longlong **)(lVar12 + 8) = plVar20 + -2;
      *plVar23 = *plVar23 + 1;
      plVar20[3] = (longlong)plVar23;
      uVar1 = DAT_23ed6cd28;
      if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23e82cfca;
      plVar23 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar23 != (longlong *)0x0) break;
      PyErr_PrintEx(0);
      Py_Exit(1);
LAB_23e82dd99:
      plVar17 = *(longlong **)(param_1 + 0x60);
      pcVar24 = *(code **)(param_1 + 0x68);
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      lVar12 = *plStack_100;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plStack_100 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0();
        pcStack_d8 = pcVar21;
LAB_23e82dc97:
        pcStack_d0 = _Py_NoneStruct_exref;
        plVar16 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        pcVar18 = (code *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcVar21 = pcStack_d8;
        pcStack_d8._0_4_ = 0x78;
      }
      else {
LAB_23e82dcee:
        plVar16 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        pcVar18 = (code *)0x0;
        plStack_100 = (longlong *)0x0;
        pcStack_d8._0_4_ = 0x78;
        plStack_108 = (longlong *)0x0;
        pcStack_d0 = _Py_NoneStruct_exref;
      }
    }
    *plVar23 = *plVar23 + 1;
    DAT_23ed6a4c0 = plVar23;
LAB_23e82cfca:
    plStack_a8 = plVar17;
    uStack_a0 = uVar1;
    lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_a8);
    if (lVar12 == 0) {
      pcStack_d0 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar20 = *plVar20 + -1;
      if (*plVar20 == 0) {
        (**(code **)(plVar20[1] + 0x30))(plVar20);
      }
    }
    else {
      plVar20[4] = lVar12;
      plVar23 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar20);
      *plVar20 = *plVar20 + -1;
      if (*plVar20 == 0) {
        (**(code **)(plVar20[1] + 0x30))(plVar20);
      }
      if (plVar23 != (longlong *)0x0) {
        *(undefined4 *)(plVar6 + 5) = 0x94;
        plVar20 = (longlong *)FUN_23e914090(param_1,uVar22);
        *plVar23 = *plVar23 + -1;
        if (*plVar23 == 0) {
          (**(code **)(plVar23[1] + 0x30))(plVar23);
        }
        if (plVar20 != (longlong *)0x0) {
          *plVar20 = *plVar20 + -1;
          if (*plVar20 == 0) {
            (**(code **)(plVar20[1] + 0x30))(plVar20);
          }
          pcVar21 = _Py_FalseStruct_exref;
          *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          plVar6 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar15;
          if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
            (**(code **)(plVar6[1] + 0x30))();
          }
          goto LAB_23e82bbb5;
        }
      }
      pcStack_d0 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    pcVar24 = *(code **)(param_1 + 0x138);
    *(longlong **)(param_1 + 0x138) = plVar15;
    if (pcVar24 == (code *)0x0) {
      if (pcVar21 != (code *)0x0) {
        plVar17 = *(longlong **)(pcVar21 + 0x18);
joined_r0x00023e82d5aa:
        pcVar24 = pcVar21;
        if (plVar17 == plVar6) goto LAB_23e82c900;
        iVar9 = 0x94;
        goto LAB_23e82c861;
      }
LAB_23e82dce3:
      iVar9 = 0x94;
    }
    else {
      *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
      if (*(longlong *)pcVar24 != 0) {
        if (pcVar21 != (code *)0x0) {
          plVar17 = *(longlong **)(pcVar21 + 0x18);
          goto joined_r0x00023e82d5aa;
        }
        goto LAB_23e82dce3;
      }
      iVar9 = 0x94;
LAB_23e82d88e:
      (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))();
      if (pcVar21 != (code *)0x0) {
LAB_23e82d250:
        pcVar24 = pcVar21;
        if (plVar6 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e82c900;
        if (iVar9 == 0) {
LAB_23e82d263:
          iVar9 = (int)plVar6[5];
        }
        goto LAB_23e82c861;
      }
      if (iVar9 == 0) {
LAB_23e82d8c7:
        iVar9 = (int)plVar6[5];
      }
    }
  }
LAB_23e82d380:
  pcVar24 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar21 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar21;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar24 + 0x10) = 0;
  *(longlong **)(pcVar24 + 0x18) = plVar6;
  *plVar6 = *plVar6 + 1;
  lVar12 = *(longlong *)(pcStack_c0 + 0x1f8);
  *(int *)(pcVar24 + 0x24) = iVar9;
  lVar12 = *(longlong *)(lVar12 + 0x10);
  *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
  lVar12 = *(longlong *)(lVar12 + 0x2e8);
  lVar19 = *(longlong *)(pcVar24 + -8);
  plVar17 = *(longlong **)(lVar12 + 8);
  *plVar17 = (longlong)(pcVar24 + -0x10);
  *(longlong *)(pcVar24 + -0x10) = lVar12;
  *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)plVar17;
  *(code **)(lVar12 + 8) = pcVar24 + -0x10;
LAB_23e82c900:
  FUN_23e8bba40(plVar6,"ooooooooooooo",plVar2,plVar3,plVar4,plVar5,plVar11,plVar13,plVar14,
                plStack_108,plStack_100,pcVar18,plVar16,plStack_f8,0);
  if (_DAT_23eede6a0 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eede6a0 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar12 + 0x28);
  plVar17 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar17 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
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
  if ((pcVar18 != (code *)0x0) &&
     (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar12 = *plStack_f8, *plStack_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  lVar12 = *plVar2;
  *plVar2 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar12 = *plVar3;
  *plVar3 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar12 = *plVar4;
  *plVar4 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  lVar12 = *plVar5;
  *plVar5 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  FUN_23a33aa70(param_1,pcStack_d0,pcStack_d8,pcVar24);
  return (code *)0x0;
}
