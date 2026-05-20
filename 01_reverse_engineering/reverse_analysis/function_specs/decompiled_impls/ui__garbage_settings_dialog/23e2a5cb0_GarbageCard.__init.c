/* ===== 23e2a5cb0 ui.garbage_settings_dialog:c913 ===== */
/* ghidra_name=FUN_23e2a5cb0 entry=23e2a5cb0 size=16552 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2a5cb0(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  code *pcVar11;
  char cVar12;
  int iVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong lVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong *plVar21;
  longlong *plVar22;
  longlong lVar23;
  longlong *plStack_e0;
  longlong *plStack_d8;
  longlong *plStack_c8;
  longlong *plStack_c0;
  undefined4 uStack_b8;
  undefined1 auStack_98 [16];
  longlong *aplStack_88 [2];
  undefined8 uStack_78;
  undefined8 uStack_70;
  longlong *plStack_68;
  longlong *plStack_60;
  
  plVar14 = _DAT_23eeb0430;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)*param_3;
  plVar4 = (longlong *)param_3[4];
  plVar5 = (longlong *)param_3[2];
  plVar6 = (longlong *)param_3[3];
  aplStack_88[0] = (longlong *)0x0;
  auStack_98._0_8_ = (code *)0x0;
  auStack_98._8_8_ = 0;
  if (_DAT_23eeb0430 == (longlong *)0x0) {
LAB_23e2a5d3d:
    _DAT_23eeb0430 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0490,DAT_23eeb0428,0x70);
  }
  else {
    lVar17 = *_DAT_23eeb0430;
    if (1 < lVar17) {
      *_DAT_23eeb0430 = lVar17 + -1;
      goto LAB_23e2a5d3d;
    }
    if (_DAT_23eeb0430[2] != 0) {
      *_DAT_23eeb0430 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      goto LAB_23e2a5d3d;
    }
  }
  plVar8 = _DAT_23eeb0430;
  lVar17 = *(longlong *)(param_1 + 0x38);
  plVar14 = _DAT_23eeb0430 + 9;
  lVar23 = *(longlong *)(lVar17 + 8);
  _DAT_23eeb0430[0xf] = lVar23;
  *(longlong **)(lVar17 + 8) = plVar14;
  if ((lVar23 != 0) &&
     (((*(char *)(lVar23 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar23 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar23 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar23 + 0x38))) && (plVar8[0xe] != 0)))) {
    plVar14 = *(longlong **)(lVar23 + 0x28);
    *(longlong **)(plVar8[0xe] + 0x10) = plVar14;
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
  }
  *plVar8 = *plVar8 + 1;
  *(undefined4 *)(plVar8 + 8) = 0;
  lVar17 = *(longlong *)(*(longlong *)(param_2 + 0xd8) + 0x10);
  if (lVar17 == 0) {
    if (((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x40) == 0) ||
       ((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x20) == 0)) {
      lVar17 = *(longlong *)(DAT_23ed6cd40 + 0x38);
    }
    else {
      lVar17 = DAT_23ed6cd40 + 0x30;
    }
    auStack_98._8_8_ =
         PyUnicode_FromFormat
                   ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                    ,lVar17);
    auStack_98._0_8_ = *(undefined8 *)PyExc_NameError_exref;
    *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + 1;
    aplStack_88[0] = (longlong *)0x0;
    if ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,aplStack_88);
    }
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_98._8_8_);
    plStack_c0 = (longlong *)0x0;
    uStack_b8 = 0x16;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  plVar14 = (longlong *)FUN_23e954510(param_1,DAT_23eeae260,lVar17,plVar3);
  if (plVar14 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar15 = (longlong *)0x0;
    uStack_b8 = 0x16;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x16;
  plVar15 = (longlong *)FUN_23e915840(param_1,plVar14,DAT_23ed6cdb0,plVar4);
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if (plVar15 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar14 = (longlong *)0x0;
    uStack_b8 = 0x16;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar15 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *plVar15 = *plVar15 + -1;
  if (*plVar15 == 0) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  cVar12 = FUN_23e8d9ac0(plVar3,_DAT_23eeae280,plVar2);
  if (cVar12 == '\0') {
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar15 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    uStack_b8 = 0x17;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2a73e9;
  }
  cVar12 = FUN_23e8d9ac0(plVar3,_DAT_23eeae288,plVar5);
  lVar17 = _DAT_23eeae298;
  if (cVar12 == '\0') {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar15 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    uStack_b8 = 0x18;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x19;
  plVar14 = (longlong *)FUN_23e915840(param_1,plVar3,_DAT_23eeae290,*(undefined8 *)(lVar17 + 0x18));
  if (plVar14 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar15 = (longlong *)0x0;
    uStack_b8 = 0x19;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  plVar16 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eeae2a0);
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar14 = (longlong *)0x0;
    uStack_b8 = 0x1a;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar15 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = FUN_23e8f8190();
  if (lVar17 == 0) {
    FUN_23e915740(param_1,auStack_98,DAT_23eeae2a8);
    *plVar16 = *plVar16 + -1;
    plVar14 = (longlong *)0x0;
    if (*plVar16 == 0) {
      plVar19 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      (**(code **)(plVar16[1] + 0x30))(plVar16);
      uStack_b8 = 0x1a;
      plStack_c0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
    }
    else {
      plStack_c0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      uStack_b8 = 0x1a;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  plVar14 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eeae2b0);
  if (plVar14 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = *plVar16 + -1;
    plVar14 = (longlong *)0x0;
    if (*plVar16 == 0) {
      plVar19 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      (**(code **)(plVar16[1] + 0x30))(plVar16);
      uStack_b8 = 0x1a;
      plStack_c0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
    }
    else {
      plStack_c0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      uStack_b8 = 0x1a;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eeae2b8);
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if (plVar15 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = *plVar16 + -1;
    plVar18 = (longlong *)0x0;
    if (*plVar16 == 0) {
      plVar19 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      (**(code **)(plVar16[1] + 0x30))(plVar16);
      uStack_b8 = 0x1a;
      plStack_c0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
    }
    else {
      plStack_c0 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      uStack_b8 = 0x1a;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x1a;
  plVar14 = (longlong *)FUN_23e914090(param_1,plVar16,plVar15);
  *plVar16 = *plVar16 + -1;
  if (*plVar16 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  *plVar15 = *plVar15 + -1;
  if (*plVar15 == 0) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if (plVar14 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar15 = (longlong *)0x0;
    uStack_b8 = 0x1a;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  lVar17 = FUN_23e8f8060();
  if (lVar17 == 0) {
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    FUN_23e915740(param_1,auStack_98,DAT_23eeae2c0);
    plStack_c0 = (longlong *)0x0;
    uStack_b8 = 0x1c;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x1c;
  plVar14 = (longlong *)FUN_23e914090(param_1,lVar17,plVar3);
  lVar17 = _DAT_23eeae2d0;
  if (plVar14 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar15 = (longlong *)0x0;
    uStack_b8 = 0x1c;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x1d;
  plVar15 = (longlong *)FUN_23e915840(param_1,plVar14,_DAT_23eeae2c8,*(undefined8 *)(lVar17 + 0x18))
  ;
  if (plVar15 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_b8 = 0x1d;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar15 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *plVar15 = *plVar15 + -1;
  if (*plVar15 == 0) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  *(undefined4 *)(plVar8 + 5) = 0x1e;
  plVar15 = (longlong *)FUN_23e95a860(param_1,plVar14,_DAT_23eeae2d8);
  if (plVar15 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_b8 = 0x1e;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar15 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *plVar15 = *plVar15 + -1;
  if (*plVar15 == 0) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  lVar17 = FUN_23e8f7de0();
  if (lVar17 == 0) {
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    FUN_23e915740(param_1,auStack_98,_DAT_23eeae2e8);
    plStack_c0 = (longlong *)0x0;
    uStack_b8 = 0x21;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x21;
  plVar15 = (longlong *)FUN_23e91a870(param_1,lVar17);
  if (plVar15 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_b8 = 0x21;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2a73e9;
  }
  plVar16 = (longlong *)FUN_23e9367b0(param_1,plVar6);
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plStack_c0 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_b8 = 0x22;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar18 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  iVar13 = FUN_23a35f020(plVar16);
  lVar17 = *plVar16 + -1;
  if (iVar13 == -1) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = lVar17;
    if (lVar17 == 0) {
      plVar19 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      (**(code **)(plVar16[1] + 0x30))(plVar16);
      uStack_b8 = 0x22;
      plStack_c0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
    }
    else {
      plStack_c0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      uStack_b8 = 0x22;
      plVar18 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  *plVar16 = lVar17;
  if (lVar17 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  lVar17 = _DAT_23eeae348;
  if (iVar13 == 0) {
    *(undefined4 *)(plVar8 + 5) = 0x29;
    plVar18 = (longlong *)
              FUN_23e915840(param_1,plVar15,_DAT_23eeae340,*(undefined8 *)(lVar17 + 0x18));
    if (plVar18 == (longlong *)0x0) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      plStack_c0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_b8 = 0x29;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar18 = (longlong *)0x0;
      goto LAB_23e2a73e9;
    }
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    lVar17 = _DAT_23eeae358;
    *(undefined4 *)(plVar8 + 5) = 0x2a;
    plVar18 = (longlong *)
              FUN_23e915840(param_1,plVar15,_DAT_23eeae350,*(undefined8 *)(lVar17 + 0x18));
    if (plVar18 == (longlong *)0x0) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      plStack_c0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_b8 = 0x2a;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar18 = (longlong *)0x0;
      goto LAB_23e2a73e9;
    }
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    plStack_c8 = (longlong *)0x0;
    plVar18 = (longlong *)0x0;
  }
  else {
    lVar17 = *(longlong *)(DAT_23eeae260 + 0x20);
    if (*(char *)(lVar17 + 10) == '\0') {
      plVar18 = (longlong *)FUN_23a37a020(DAT_23eeae260,_DAT_23eeae2f0);
      if (plVar18 == (longlong *)0x0) goto LAB_23e2a81d0;
      lVar17 = *plVar18;
LAB_23e2a81bb:
      if (lVar17 == 0) goto LAB_23e2a81d0;
    }
    else {
      iVar13 = *(int *)(lVar17 + 0xc);
      if (*(int *)(lVar17 + 0xc) == 0) {
        *(int *)(lVar17 + 0xc) = DAT_23ec14e8c;
        iVar13 = DAT_23ec14e8c;
        DAT_23ec14e8c = DAT_23ec14e8c + 1;
      }
      if (_DAT_23ec14e88 != iVar13) {
        _DAT_23ec14e88 = iVar13;
        _DAT_23eeb0418 = FUN_23e8cbd60(lVar17,_DAT_23eeae2f0,*(undefined8 *)(_DAT_23eeae2f0 + 0x18))
        ;
      }
      if (-1 < _DAT_23eeb0418) {
        lVar23 = lVar17 + 0x20 + (1L << (*(byte *)(lVar17 + 9) & 0x3f));
        if (*(longlong *)(lVar23 + 8 + _DAT_23eeb0418 * 0x10) != 0) goto LAB_23e2a6129;
        _DAT_23eeb0418 = FUN_23e8cbd60(lVar17,_DAT_23eeae2f0,*(undefined8 *)(_DAT_23eeae2f0 + 0x18))
        ;
        if (-1 < _DAT_23eeb0418) {
          lVar17 = *(longlong *)(lVar23 + 8 + _DAT_23eeb0418 * 0x10);
          goto LAB_23e2a81bb;
        }
      }
LAB_23e2a81d0:
      plVar18 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeae2f0);
      if ((plVar18 == (longlong *)0x0) || (*plVar18 == 0)) {
        plVar19 = (longlong *)0x0;
        plVar18 = (longlong *)0x0;
        FUN_23e915740(param_1,auStack_98,_DAT_23eeae2f0);
        plStack_c0 = (longlong *)0x0;
        uStack_b8 = 0x23;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        goto LAB_23e2a73e9;
      }
    }
LAB_23e2a6129:
    *(undefined4 *)(plVar8 + 5) = 0x23;
    plVar18 = (longlong *)FUN_23e914090(param_1);
    if (plVar18 == (longlong *)0x0) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      plStack_c0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_b8 = 0x23;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2a73e9;
    }
    plVar16 = (longlong *)FUN_23e8bc2f0(plVar18,_DAT_23eeae2f8);
    uVar10 = uRam000000023eeae308;
    uVar9 = _DAT_23eeae300;
    if (plVar16 == (longlong *)0x0) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      plStack_c0 = (longlong *)0x0;
      uStack_b8 = 0x25;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar19 = (longlong *)0x0;
      goto LAB_23e2a73e9;
    }
    lVar17 = FUN_23e8f7c90();
    if (lVar17 == 0) {
      FUN_23e915740(param_1,auStack_98,_DAT_23eeae310);
      *plVar16 = *plVar16 + -1;
      plStack_c8 = (longlong *)0x0;
      if (*plVar16 == 0) {
        plVar19 = (longlong *)0x0;
        FUN_23a334bc0(plVar16);
        uStack_b8 = 0x25;
        plStack_c0 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
      }
      else {
        plVar19 = (longlong *)0x0;
        uStack_b8 = 0x25;
        plStack_c0 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
      }
      goto LAB_23e2a73e9;
    }
    plVar19 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eeae318);
    if (plVar19 == (longlong *)0x0) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar16 = *plVar16 + -1;
      plStack_c8 = (longlong *)0x0;
      if (*plVar16 == 0) {
        plVar19 = (longlong *)0x0;
        (**(code **)(plVar16[1] + 0x30))(plVar16);
        uStack_b8 = 0x25;
        plStack_c0 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
      }
      else {
        plStack_c0 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        uStack_b8 = 0x25;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
      }
      goto LAB_23e2a73e9;
    }
    plVar20 = (longlong *)FUN_23e8bc2f0(plVar19,_DAT_23eeae320);
    lVar17 = *plVar19;
    *plVar19 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    if (plVar20 == (longlong *)0x0) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar16 = *plVar16 + -1;
      plStack_e0 = (longlong *)0x0;
      if (*plVar16 == 0) {
        plVar19 = (longlong *)0x0;
        (**(code **)(plVar16[1] + 0x30))(plVar16);
        uStack_b8 = 0x25;
        plStack_c0 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
      }
      else {
        plStack_c0 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        uStack_b8 = 0x25;
        plStack_d8 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
      }
      goto LAB_23e2a73e9;
    }
    lVar17 = FUN_23e8f7c90();
    if (lVar17 == 0) {
      FUN_23e915740(param_1,auStack_98,_DAT_23eeae310);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      lVar17 = *plVar20;
      *plVar20 = lVar17 + -1;
      plStack_c8 = (longlong *)0x0;
      if (lVar17 + -1 == 0) {
        FUN_23a334bc0(plVar20);
        plStack_c0 = (longlong *)0x0;
        uStack_b8 = 0x26;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
      }
      else {
        plVar19 = (longlong *)0x0;
        uStack_b8 = 0x26;
        plStack_c0 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
      }
      goto LAB_23e2a73e9;
    }
    plVar19 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eeae328);
    if (plVar19 == (longlong *)0x0) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      lVar17 = *plVar20;
      *plVar20 = lVar17 + -1;
      plStack_c8 = (longlong *)0x0;
      if (lVar17 + -1 == 0) {
        plVar19 = (longlong *)0x0;
        FUN_23a334bc0(plVar20);
        uStack_b8 = 0x26;
        plStack_c0 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
      }
      else {
        plVar19 = (longlong *)0x0;
        uStack_b8 = 0x26;
        plStack_c0 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
      }
      goto LAB_23e2a73e9;
    }
    plVar21 = (longlong *)FUN_23e8bc2f0(plVar19,_DAT_23eeae330);
    lVar17 = *plVar19;
    *plVar19 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    if (plVar21 == (longlong *)0x0) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      lVar17 = *plVar20;
      *plVar20 = lVar17 + -1;
      plStack_d8 = (longlong *)0x0;
      if (lVar17 + -1 == 0) {
        plVar19 = (longlong *)0x0;
        FUN_23a334bc0();
        uStack_b8 = 0x26;
        plStack_c0 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
      }
      else {
        plVar19 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        uStack_b8 = 0x26;
        plStack_c0 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
      }
      goto LAB_23e2a73e9;
    }
    *(undefined4 *)(plVar8 + 5) = 0x25;
    uStack_78 = uVar9;
    uStack_70 = uVar10;
    plStack_68 = plVar20;
    plStack_60 = plVar21;
    plStack_c8 = (longlong *)FUN_23e9583d0(param_1,plVar16,&uStack_78);
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    lVar17 = *plVar20;
    *plVar20 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    lVar17 = *plVar21;
    *plVar21 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar21[1] + 0x30))(plVar21);
    }
    if (plStack_c8 == (longlong *)0x0) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      plStack_c0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_b8 = 0x25;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2a73e9;
    }
    *(undefined4 *)(plVar8 + 5) = 0x27;
    plVar19 = (longlong *)FUN_23e915840(param_1,plVar15,_DAT_23eeae338,plStack_c8);
    if (plVar19 == (longlong *)0x0) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      uStack_b8 = 0x27;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_c0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar19 = (longlong *)0x0;
      goto LAB_23e2a73e9;
    }
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
  }
  plVar16 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eeae360);
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plStack_c0 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_b8 = 0x2c;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e0 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = FUN_23e8f7c90();
  if (lVar17 == 0) {
    FUN_23e915740(param_1,auStack_98,_DAT_23eeae310);
    lVar17 = *plVar16;
    *plVar16 = lVar17 + -1;
    plVar19 = (longlong *)0x0;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
      uStack_b8 = 0x2c;
      plStack_c0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    else {
      uStack_b8 = 0x2c;
      plStack_c0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  plVar19 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eeae368);
  if (plVar19 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar17 = *plVar16;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = lVar17 + -1;
    plVar19 = (longlong *)0x0;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
      uStack_b8 = 0x2c;
      plStack_c0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    else {
      plStack_c0 = (longlong *)0x0;
      uStack_b8 = 0x2c;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  plVar20 = (longlong *)FUN_23e8bc2f0(plVar19,_DAT_23eeae370);
  *plVar19 = *plVar19 + -1;
  if (*plVar19 == 0) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  if (plVar20 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar17 = *plVar16;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = lVar17 + -1;
    plStack_d8 = (longlong *)0x0;
    if (lVar17 + -1 == 0) {
      plVar19 = (longlong *)0x0;
      (**(code **)(plVar16[1] + 0x30))();
      uStack_b8 = 0x2c;
      plStack_c0 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    else {
      plStack_c0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      uStack_b8 = 0x2c;
      plStack_e0 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x2c;
  plVar19 = (longlong *)FUN_23e914090(param_1,plVar16,plVar20);
  lVar17 = *plVar16;
  *plVar16 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  lVar17 = *plVar20;
  *plVar20 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  if (plVar19 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plStack_c0 = (longlong *)0x0;
    uStack_b8 = 0x2c;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar19 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *plVar19 = *plVar19 + -1;
  if (*plVar19 == 0) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  lVar17 = _DAT_23eeae380;
  *(undefined4 *)(plVar8 + 5) = 0x2d;
  plVar19 = (longlong *)FUN_23e915840(param_1,plVar15,_DAT_23eeae378,*(undefined8 *)(lVar17 + 0x18))
  ;
  if (plVar19 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plStack_c0 = (longlong *)0x0;
    uStack_b8 = 0x2d;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar19 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *plVar19 = *plVar19 + -1;
  if (*plVar19 == 0) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  *(undefined4 *)(plVar8 + 5) = 0x2e;
  plVar19 = (longlong *)FUN_23e915840(param_1,plVar14,_DAT_23eeae388);
  if (plVar19 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plStack_c0 = (longlong *)0x0;
    uStack_b8 = 0x2e;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar19 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *plVar19 = *plVar19 + -1;
  if (*plVar19 == 0) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  lVar17 = FUN_23e8f7de0();
  if (lVar17 == 0) {
    FUN_23e915740(param_1,auStack_98,_DAT_23eeae2e8);
    plStack_c0 = (longlong *)0x0;
    uStack_b8 = 0x31;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x31;
  plVar19 = (longlong *)FUN_23e914090(param_1,lVar17);
  if (plVar19 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plStack_c0 = (longlong *)0x0;
    uStack_b8 = 0x31;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2a73e9;
  }
  plVar16 = (longlong *)FUN_23e8bc2f0(plVar19,_DAT_23eeae360);
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plStack_c0 = (longlong *)0x0;
    uStack_b8 = 0x32;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e0 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = FUN_23e8f7c90();
  if (lVar17 == 0) {
    FUN_23e915740(param_1,auStack_98,_DAT_23eeae310);
    lVar17 = *plVar16;
    *plVar16 = lVar17 + -1;
    plStack_d8 = (longlong *)0x0;
    if (lVar17 + -1 == 0) {
      FUN_23a334bc0(plVar16);
      uStack_b8 = 0x32;
      plStack_c0 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    else {
      uStack_b8 = 0x32;
      plStack_c0 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  plVar20 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eeae368);
  if (plVar20 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar17 = *plVar16;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = lVar17 + -1;
    plStack_d8 = (longlong *)0x0;
    if (lVar17 + -1 == 0) {
      FUN_23a334bc0();
      uStack_b8 = 0x32;
      plStack_c0 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    else {
      uStack_b8 = 0x32;
      plStack_c0 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  plVar21 = (longlong *)FUN_23e8bc2f0(plVar20,_DAT_23eeae370);
  lVar17 = *plVar20;
  *plVar20 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  if (plVar21 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar17 = *plVar16;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = lVar17 + -1;
    plStack_c0 = (longlong *)0x0;
    if (lVar17 + -1 == 0) {
      FUN_23a334bc0();
      uStack_b8 = 0x32;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    else {
      uStack_b8 = 0x32;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x32;
  plVar20 = (longlong *)FUN_23e914090(param_1,plVar16,plVar21);
  lVar17 = *plVar16;
  *plVar16 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  lVar17 = *plVar21;
  *plVar21 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar21[1] + 0x30))(plVar21);
  }
  if (plVar20 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    uStack_b8 = 0x32;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_d8 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = *plVar20;
  *plVar20 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  lVar17 = _DAT_23eeae398;
  *(undefined4 *)(plVar8 + 5) = 0x33;
  plVar16 = (longlong *)FUN_23e915840(param_1,plVar19,_DAT_23eeae390,*(undefined8 *)(lVar17 + 0x18))
  ;
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x33;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e0 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = *plVar16;
  *plVar16 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  lVar17 = _DAT_23eeae3a0;
  *(undefined4 *)(plVar8 + 5) = 0x34;
  plVar16 = (longlong *)FUN_23e915840(param_1,plVar19,_DAT_23eeae350,*(undefined8 *)(lVar17 + 0x18))
  ;
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x34;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e0 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = *plVar16;
  *plVar16 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  *(undefined4 *)(plVar8 + 5) = 0x35;
  plVar16 = (longlong *)FUN_23e915840(param_1,plVar14,_DAT_23eeae388,plVar19);
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x35;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e0 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = *plVar16;
  *plVar16 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  lVar17 = FUN_23e8f7f10();
  if (lVar17 == 0) {
    FUN_23e915740(param_1,auStack_98,_DAT_23eeae3a8);
    uStack_b8 = 0x38;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x38;
  plStack_e0 = (longlong *)FUN_23e91a870(param_1,lVar17);
  if (plStack_e0 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x38;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x39;
  plVar16 = (longlong *)FUN_23e915840(param_1,plStack_e0,_DAT_23eeae2c8);
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x39;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_d8 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = *plVar16;
  *plVar16 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  lVar17 = FUN_23e8f7de0();
  if (lVar17 == 0) {
    FUN_23e915740(param_1,auStack_98,_DAT_23eeae2e8);
    uStack_b8 = 0x3c;
    plStack_c0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x3c;
  plStack_d8 = (longlong *)FUN_23e94bb80(param_1,lVar17);
  if (plStack_d8 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x3c;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2a73e9;
  }
  plVar16 = (longlong *)FUN_23e8bc2f0(plStack_d8,_DAT_23eeae360);
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x3d;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = FUN_23e8f7c90();
  if (lVar17 == 0) {
    FUN_23e915740(param_1,auStack_98,_DAT_23eeae310);
    *plVar16 = *plVar16 + -1;
    plStack_c0 = (longlong *)0x0;
    if (*plVar16 == 0) {
      FUN_23a334bc0(plVar16);
      uStack_b8 = 0x3d;
    }
    else {
      uStack_b8 = 0x3d;
    }
    goto LAB_23e2a73e9;
  }
  plVar20 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eeae368);
  if (plVar20 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_b8 = 0x3d;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = *plVar16 + -1;
    plStack_c0 = (longlong *)0x0;
    if (*plVar16 == 0) {
      FUN_23a334bc0(plVar16);
      uStack_b8 = 0x3d;
    }
    goto LAB_23e2a73e9;
  }
  plVar21 = (longlong *)FUN_23e8bc2f0(plVar20,_DAT_23eeae3b8);
  lVar17 = *plVar20;
  *plVar20 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    FUN_23a334bc0(plVar20);
  }
  if (plVar21 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      FUN_23a334bc0();
      uStack_b8 = 0x3d;
      plStack_c0 = (longlong *)0x0;
    }
    else {
      uStack_b8 = 0x3d;
      plStack_c0 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  lVar17 = FUN_23e8f7c90();
  if (lVar17 == 0) {
    FUN_23e915740(param_1,auStack_98,_DAT_23eeae310);
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      FUN_23a334bc0(plVar16);
    }
    lVar17 = *plVar21;
    *plVar21 = lVar17 + -1;
    plStack_c0 = (longlong *)0x0;
    if (lVar17 + -1 == 0) {
      FUN_23a334bc0(plVar21);
      uStack_b8 = 0x3d;
    }
    else {
      uStack_b8 = 0x3d;
    }
    goto LAB_23e2a73e9;
  }
  plVar20 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eeae368);
  if (plVar20 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      FUN_23a334bc0(plVar16);
    }
    lVar17 = *plVar21;
    *plVar21 = lVar17 + -1;
    plStack_c0 = (longlong *)0x0;
    if (lVar17 + -1 == 0) {
      FUN_23a334bc0(plVar21);
      uStack_b8 = 0x3d;
    }
    else {
      uStack_b8 = 0x3d;
    }
    goto LAB_23e2a73e9;
  }
  plVar22 = (longlong *)FUN_23e8bc2f0(plVar20,_DAT_23eeae3c0);
  lVar17 = *plVar20;
  *plVar20 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    FUN_23a334bc0();
  }
  if (plVar22 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      FUN_23a334bc0(plVar16);
    }
    lVar17 = *plVar21;
    *plVar21 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      FUN_23a334bc0(plVar21);
      uStack_b8 = 0x3d;
      plStack_c0 = (longlong *)0x0;
    }
    else {
      uStack_b8 = 0x3d;
      plStack_c0 = (longlong *)0x0;
    }
    goto LAB_23e2a73e9;
  }
  plVar20 = (longlong *)FUN_23e8c1360(plVar21);
  lVar17 = *plVar21;
  *plVar21 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    FUN_23a334bc0();
  }
  *plVar22 = *plVar22 + -1;
  if (*plVar22 == 0) {
    FUN_23a334bc0(plVar22);
  }
  if (plVar20 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x3d;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar16 = *plVar16 + -1;
    plStack_c0 = (longlong *)0x0;
    if (*plVar16 == 0) {
      FUN_23a334bc0(plVar16);
      uStack_b8 = 0x3d;
    }
    goto LAB_23e2a73e9;
  }
  *(undefined4 *)(plVar8 + 5) = 0x3d;
  plVar21 = (longlong *)FUN_23e914090(param_1,plVar16,plVar20);
  *plVar16 = *plVar16 + -1;
  if (*plVar16 == 0) {
    FUN_23a334bc0(plVar16);
  }
  lVar17 = *plVar20;
  *plVar20 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    FUN_23a334bc0();
  }
  if (plVar21 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x3d;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2a73e9;
  }
  *plVar21 = *plVar21 + -1;
  if (*plVar21 == 0) {
    FUN_23a334bc0(plVar21);
  }
  lVar17 = _DAT_23eeae3c8;
  *(undefined4 *)(plVar8 + 5) = 0x3e;
  plVar16 = (longlong *)
            FUN_23e915840(param_1,plStack_d8,_DAT_23eeae350,*(undefined8 *)(lVar17 + 0x18));
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x3e;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = *plVar16;
  *plVar16 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    FUN_23a334bc0(plVar16);
  }
  *(undefined4 *)(plVar8 + 5) = 0x3f;
  plVar16 = (longlong *)FUN_23e915840(param_1,plStack_e0,_DAT_23eeae388);
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_b8 = 0x3f;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e2a73e9;
  }
  lVar17 = *plVar16;
  *plVar16 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    FUN_23a334bc0(plVar16);
  }
  lVar17 = *(longlong *)(DAT_23eeae260 + 0x20);
  if (*(char *)(lVar17 + 10) == '\0') {
    plVar16 = (longlong *)FUN_23a37a020(DAT_23eeae260,_DAT_23eeae3d0);
    if (plVar16 == (longlong *)0x0) goto LAB_23e2a94a2;
    lVar23 = *plVar16;
LAB_23e2a9499:
    if (lVar23 == 0) goto LAB_23e2a94a2;
  }
  else {
    iVar13 = *(int *)(lVar17 + 0xc);
    if (*(int *)(lVar17 + 0xc) == 0) {
      *(int *)(lVar17 + 0xc) = DAT_23ec14e8c;
      iVar13 = DAT_23ec14e8c;
      DAT_23ec14e8c = DAT_23ec14e8c + 1;
    }
    if (_DAT_23ec14e90 != iVar13) {
      _DAT_23ec14e90 = iVar13;
      _DAT_23eeb0420 = FUN_23e8cbd60(lVar17,_DAT_23eeae3d0,*(undefined8 *)(_DAT_23eeae3d0 + 0x18));
    }
    if (-1 < _DAT_23eeb0420) {
      lVar1 = lVar17 + 0x20 + (1L << (*(byte *)(lVar17 + 9) & 0x3f));
      lVar23 = *(longlong *)(lVar1 + 8 + _DAT_23eeb0420 * 0x10);
      if (lVar23 != 0) goto LAB_23e2a6c4b;
      _DAT_23eeb0420 = FUN_23e8cbd60(lVar17,_DAT_23eeae3d0,*(undefined8 *)(_DAT_23eeae3d0 + 0x18));
      if (-1 < _DAT_23eeb0420) {
        lVar23 = *(longlong *)(lVar1 + 8 + _DAT_23eeb0420 * 0x10);
        goto LAB_23e2a9499;
      }
    }
LAB_23e2a94a2:
    plVar16 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeae3d0);
    if ((plVar16 == (longlong *)0x0) || (lVar23 = *plVar16, lVar23 == 0)) {
      FUN_23e915740(param_1,auStack_98);
      uStack_b8 = 0x42;
      plStack_c0 = (longlong *)0x0;
      goto LAB_23e2a73e9;
    }
  }
LAB_23e2a6c4b:
  lVar17 = _DAT_23eeae398;
  *(undefined4 *)(plVar8 + 5) = 0x42;
  plVar16 = (longlong *)FUN_23e9186b0(param_1,lVar23,lVar17 + 0x18,_DAT_23eeae3d8);
  if (plVar16 == (longlong *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    uStack_b8 = 0x42;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_c0 = (longlong *)0x0;
  }
  else {
    cVar12 = FUN_23e8d9ac0(plVar3,DAT_23eeae3e0,plVar16);
    lVar17 = *plVar16;
    *plVar16 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      FUN_23a334bc0();
    }
    if (cVar12 == '\0') {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      uStack_b8 = 0x42;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_c0 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      plVar16 = (longlong *)FUN_23e8bc2f0(plVar3,DAT_23eeae3e0);
      if (plVar16 == (longlong *)0x0) {
        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        aplStack_88[0] = *(longlong **)(param_1 + 0x70);
        uStack_b8 = 0x43;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_c0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        *(undefined4 *)(plVar8 + 5) = 0x43;
        plVar20 = (longlong *)FUN_23e915840(param_1,plVar16,DAT_23eeae3e8);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          FUN_23a334bc0(plVar16);
        }
        if (plVar20 == (longlong *)0x0) {
          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          aplStack_88[0] = *(longlong **)(param_1 + 0x70);
          uStack_b8 = 0x43;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_c0 = (longlong *)0x0;
        }
        else {
          lVar17 = *plVar20;
          *plVar20 = lVar17 + -1;
          if (lVar17 + -1 == 0) {
            FUN_23a334bc0(plVar20);
          }
          plVar16 = (longlong *)FUN_23e8bc2f0(plStack_e0,_DAT_23eeae388);
          if (plVar16 == (longlong *)0x0) {
            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            aplStack_88[0] = *(longlong **)(param_1 + 0x70);
            uStack_b8 = 0x44;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_c0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            plVar20 = (longlong *)FUN_23e8bc2f0(plVar3,DAT_23eeae3e0);
            if (plVar20 == (longlong *)0x0) {
              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              aplStack_88[0] = *(longlong **)(param_1 + 0x70);
              uStack_b8 = 0x44;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar16 = *plVar16 + -1;
              plStack_c0 = (longlong *)0x0;
              if (*plVar16 == 0) {
                FUN_23a334bc0(plVar16);
                uStack_b8 = 0x44;
              }
            }
            else {
              *(undefined4 *)(plVar8 + 5) = 0x44;
              plVar21 = (longlong *)FUN_23e914090(param_1,plVar16,plVar20);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                FUN_23a334bc0(plVar16);
              }
              lVar17 = *plVar20;
              *plVar20 = lVar17 + -1;
              if (lVar17 + -1 == 0) {
                FUN_23a334bc0();
              }
              if (plVar21 == (longlong *)0x0) {
                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                uStack_b8 = 0x44;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_c0 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                *plVar21 = *plVar21 + -1;
                if (*plVar21 == 0) {
                  FUN_23a334bc0(plVar21);
                }
                lVar17 = FUN_23e8f7de0();
                if (lVar17 == 0) {
                  FUN_23e915740(param_1,auStack_98,_DAT_23eeae2e8);
                  uStack_b8 = 0x47;
                  plStack_c0 = (longlong *)0x0;
                }
                else {
                  *(undefined4 *)(plVar8 + 5) = 0x47;
                  plStack_c0 = (longlong *)FUN_23e94bb80(param_1,lVar17);
                  if (plStack_c0 == (longlong *)0x0) {
                    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uStack_b8 = 0x47;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    plVar16 = (longlong *)FUN_23e8bc2f0(plStack_c0,_DAT_23eeae360);
                    if (plVar16 == (longlong *)0x0) {
                      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                      uStack_b8 = 0x48;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
                      lVar17 = FUN_23e8f7c90();
                      if (lVar17 == 0) {
                        FUN_23e915740(param_1,auStack_98,_DAT_23eeae310);
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          FUN_23a334bc0(plVar16);
                          uStack_b8 = 0x48;
                        }
                        else {
                          uStack_b8 = 0x48;
                        }
                      }
                      else {
                        plVar20 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eeae368);
                        if (plVar20 == (longlong *)0x0) {
                          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                          uStack_b8 = 0x48;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            FUN_23a334bc0(plVar16);
                            uStack_b8 = 0x48;
                          }
                        }
                        else {
                          plVar21 = (longlong *)FUN_23e8bc2f0(plVar20,_DAT_23eeae3f8);
                          *plVar20 = *plVar20 + -1;
                          if (*plVar20 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plVar21 == (longlong *)0x0) {
                            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                            uStack_b8 = 0x48;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar16 = *plVar16 + -1;
                            if (*plVar16 == 0) {
                              FUN_23a334bc0(plVar16);
                              uStack_b8 = 0x48;
                            }
                          }
                          else {
                            lVar17 = FUN_23e8f7c90();
                            if (lVar17 == 0) {
                              FUN_23e915740(param_1,auStack_98,_DAT_23eeae310);
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                FUN_23a334bc0(plVar16);
                              }
                              lVar17 = *plVar21;
                              *plVar21 = lVar17 + -1;
                              if (lVar17 + -1 == 0) {
                                FUN_23a334bc0(plVar21);
                                uStack_b8 = 0x48;
                              }
                              else {
                                uStack_b8 = 0x48;
                              }
                            }
                            else {
                              plVar20 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eeae368);
                              if (plVar20 == (longlong *)0x0) {
                                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  FUN_23a334bc0(plVar16);
                                }
                                lVar17 = *plVar21;
                                *plVar21 = lVar17 + -1;
                                if (lVar17 + -1 == 0) {
                                  FUN_23a334bc0(plVar21);
                                  uStack_b8 = 0x48;
                                }
                                else {
                                  uStack_b8 = 0x48;
                                }
                              }
                              else {
                                plVar22 = (longlong *)FUN_23e8bc2f0(plVar20,_DAT_23eeae3c0);
                                *plVar20 = *plVar20 + -1;
                                if (*plVar20 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (plVar22 == (longlong *)0x0) {
                                  auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                  auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                  aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *plVar16 = *plVar16 + -1;
                                  if (*plVar16 == 0) {
                                    FUN_23a334bc0(plVar16);
                                  }
                                  lVar17 = *plVar21;
                                  *plVar21 = lVar17 + -1;
                                  if (lVar17 + -1 == 0) {
                                    FUN_23a334bc0(plVar21);
                                    uStack_b8 = 0x48;
                                  }
                                  else {
                                    uStack_b8 = 0x48;
                                  }
                                }
                                else {
                                  plVar20 = (longlong *)FUN_23e8c1360(plVar21);
                                  lVar17 = *plVar21;
                                  *plVar21 = lVar17 + -1;
                                  if (lVar17 + -1 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  *plVar22 = *plVar22 + -1;
                                  if (*plVar22 == 0) {
                                    FUN_23a334bc0(plVar22);
                                  }
                                  if (plVar20 == (longlong *)0x0) {
                                    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                                    uStack_b8 = 0x48;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *plVar16 = *plVar16 + -1;
                                    if (*plVar16 == 0) {
                                      FUN_23a334bc0(plVar16);
                                      uStack_b8 = 0x48;
                                    }
                                  }
                                  else {
                                    *(undefined4 *)(plVar8 + 5) = 0x48;
                                    plVar21 = (longlong *)FUN_23e914090(param_1,plVar16,plVar20);
                                    *plVar16 = *plVar16 + -1;
                                    if (*plVar16 == 0) {
                                      FUN_23a334bc0(plVar16);
                                    }
                                    lVar17 = *plVar20;
                                    *plVar20 = lVar17 + -1;
                                    if (lVar17 + -1 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    if (plVar21 == (longlong *)0x0) {
                                      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                                      uStack_b8 = 0x48;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                    }
                                    else {
                                      *plVar21 = *plVar21 + -1;
                                      if (*plVar21 == 0) {
                                        FUN_23a334bc0(plVar21);
                                      }
                                      lVar17 = _DAT_23eeae3c8;
                                      *(undefined4 *)(plVar8 + 5) = 0x49;
                                      plVar16 = (longlong *)
                                                FUN_23e915840(param_1,plStack_c0,_DAT_23eeae350,
                                                              *(undefined8 *)(lVar17 + 0x18));
                                      if (plVar16 == (longlong *)0x0) {
                                        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                                        uStack_b8 = 0x49;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                      }
                                      else {
                                        *plVar16 = *plVar16 + -1;
                                        if (*plVar16 == 0) {
                                          FUN_23a334bc0(plVar16);
                                        }
                                        *(undefined4 *)(plVar8 + 5) = 0x4a;
                                        plVar16 = (longlong *)
                                                  FUN_23e915840(param_1,plStack_e0,_DAT_23eeae388,
                                                                plStack_c0);
                                        if (plVar16 == (longlong *)0x0) {
                                          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                                          uStack_b8 = 0x4a;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else {
                                          *plVar16 = *plVar16 + -1;
                                          if (*plVar16 == 0) {
                                            FUN_23a334bc0(plVar16);
                                          }
                                          *(undefined4 *)(plVar8 + 5) = 0x4c;
                                          plVar16 = (longlong *)
                                                    FUN_23e915840(param_1,plVar14,_DAT_23eeae400);
                                          if (plVar16 != (longlong *)0x0) {
                                            *plVar16 = *plVar16 + -1;
                                            if (*plVar16 == 0) {
                                              FUN_23a334bc0(plVar16);
                                            }
                                            FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                            pcVar11 = _Py_NoneStruct_exref;
                                            *(longlong *)_Py_NoneStruct_exref =
                                                 *(longlong *)_Py_NoneStruct_exref + 1;
                                            *plVar14 = *plVar14 + -1;
                                            if (*plVar14 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            *plVar15 = *plVar15 + -1;
                                            if (*plVar15 == 0) {
                                              FUN_23a334bc0(plVar15);
                                            }
                                            if ((plVar18 != (longlong *)0x0) &&
                                               (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
                                              FUN_23a334bc0(plVar18);
                                            }
                                            if ((plStack_c8 != (longlong *)0x0) &&
                                               (lVar17 = *plStack_c8, *plStack_c8 = lVar17 + -1,
                                               lVar17 + -1 == 0)) {
                                              FUN_23a334bc0(plStack_c8);
                                            }
                                            *plVar19 = *plVar19 + -1;
                                            if (*plVar19 == 0) {
                                              FUN_23a334bc0(plVar19);
                                            }
                                            lVar17 = *plStack_e0;
                                            *plStack_e0 = lVar17 + -1;
                                            if (lVar17 + -1 == 0) {
                                              FUN_23a334bc0(plStack_e0);
                                            }
                                            lVar17 = *plStack_d8;
                                            *plStack_d8 = lVar17 + -1;
                                            if (lVar17 + -1 == 0) {
                                              FUN_23a334bc0(plStack_d8);
                                            }
                                            lVar17 = *plStack_c0;
                                            *plStack_c0 = lVar17 + -1;
                                            if (lVar17 + -1 == 0) {
                                              FUN_23a334bc0(plStack_c0);
                                            }
                                            *plVar3 = *plVar3 + -1;
                                            if (*plVar3 == 0) {
                                              FUN_23a334bc0(plVar3);
                                            }
                                            lVar17 = *plVar2;
                                            *plVar2 = lVar17 + -1;
                                            if (lVar17 + -1 == 0) {
                                              FUN_23a334bc0(plVar2);
                                            }
                                            lVar17 = *plVar5;
                                            *plVar5 = lVar17 + -1;
                                            if (lVar17 + -1 == 0) {
                                              FUN_23a334bc0(plVar5);
                                            }
                                            lVar17 = *plVar6;
                                            *plVar6 = lVar17 + -1;
                                            if (lVar17 + -1 == 0) {
                                              FUN_23a334bc0(plVar6);
                                            }
                                            *plVar4 = *plVar4 + -1;
                                            if (*plVar4 != 0) {
                                              return pcVar11;
                                            }
                                            FUN_23a334bc0(plVar4);
                                            return pcVar11;
                                          }
                                          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          aplStack_88[0] = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uStack_b8 = 0x4c;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
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
LAB_23e2a73e9:
  plVar20 = aplStack_88[0];
  plVar16 = DAT_23ed6a4f8;
  if (aplStack_88[0] == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar20 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar20;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar16[2] = 0;
    plVar16[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar17 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)((longlong)plVar16 + 0x24) = uStack_b8;
    lVar17 = *(longlong *)(lVar17 + 0x10);
    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
    lVar17 = *(longlong *)(lVar17 + 0x2e8);
    lVar23 = plVar16[-1];
    puVar7 = *(undefined8 **)(lVar17 + 8);
    *puVar7 = plVar16 + -2;
    plVar16[-2] = lVar17;
    plVar16[-1] = (ulonglong)((uint)lVar23 & 3) | (ulonglong)puVar7;
    *(longlong **)(lVar17 + 8) = plVar16 + -2;
    plVar20 = plVar16;
    if ((aplStack_88[0] != (longlong *)0x0) &&
       (*aplStack_88[0] = *aplStack_88[0] + -1, *aplStack_88[0] == 0)) {
      (**(code **)(aplStack_88[0][1] + 0x30))(aplStack_88[0]);
    }
  }
  else if ((longlong *)aplStack_88[0][3] != plVar8) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar21 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar21;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar16[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar17 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)((longlong)plVar16 + 0x24) = uStack_b8;
    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
    lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
    lVar23 = plVar16[-1];
    puVar7 = *(undefined8 **)(lVar17 + 8);
    *puVar7 = plVar16 + -2;
    plVar16[-2] = lVar17;
    plVar16[-1] = (ulonglong)((uint)lVar23 & 3) | (ulonglong)puVar7;
    *(longlong **)(lVar17 + 8) = plVar16 + -2;
    plVar16[2] = (longlong)plVar20;
    *plVar20 = *plVar20 + 1;
    plVar20 = plVar16;
    if ((aplStack_88[0] != (longlong *)0x0) &&
       (*aplStack_88[0] = *aplStack_88[0] + -1, *aplStack_88[0] == 0)) {
      (**(code **)(aplStack_88[0][1] + 0x30))(aplStack_88[0]);
    }
  }
  aplStack_88[0] = plVar20;
  FUN_23e8bba40(plVar8,"oooooooooooooc",plVar3,plVar2,plVar5,plVar6,plVar4,plVar14,plVar15,plVar18,
                plStack_c8,plVar19,plStack_e0,plStack_d8,plStack_c0,*(undefined8 *)(param_2 + 0xd8))
  ;
  if (_DAT_23eeb0430 == plVar8) {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    _DAT_23eeb0430 = (longlong *)0x0;
  }
  lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar17 + 0x28);
  plVar16 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar16 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar16 = aplStack_88[0];
  uVar10 = auStack_98._8_8_;
  uVar9 = auStack_98._0_8_;
  plVar8[0xf] = 0;
  auStack_98 = (undefined1  [16])0x0;
  aplStack_88[0] = (longlong *)0x0;
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  if ((plStack_c8 != (longlong *)0x0) &&
     (lVar17 = *plStack_c8, *plStack_c8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
  }
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar17 = *plStack_e0, *plStack_e0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plStack_d8 != (longlong *)0x0) &&
     (lVar17 = *plStack_d8, *plStack_d8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
  }
  if ((plStack_c0 != (longlong *)0x0) &&
     (lVar17 = *plStack_c0, *plStack_c0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
  }
  auStack_98 = CONCAT88(uVar10,uVar9);
  *plVar3 = *plVar3 + -1;
  aplStack_88[0] = plVar16;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar17 = *plVar2;
  *plVar2 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar17 = *plVar5;
  *plVar5 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  lVar17 = *plVar6;
  *plVar6 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,auStack_98._0_8_,auStack_98._8_8_,aplStack_88[0]);
  return (code *)0x0;
}
