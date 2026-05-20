/* ===== 23e120360 telegram.handlers.notifications_:13 ===== */
/* ghidra_name=forced_23e120360 entry=23e120360 size=11228 */

longlong forced_23e120360(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong *plVar5;
  code *pcVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  int iVar16;
  longlong lVar17;
  longlong *plStack_c0;
  longlong *plStack_b8;
  longlong *plStack_b0;
  longlong *plStack_a8;
  longlong *plStack_a0;
  longlong *plStack_98;
  longlong *plStack_90;
  undefined4 uStack_88;
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar10 = DAT_23eeaafd8;
  if (DAT_23eeaafd8 == (longlong *)0x0) {
LAB_23e1203a2:
    DAT_23eeaafd8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaafc8,DAT_23eeaafd0,0x50);
  }
  else {
    lVar7 = *DAT_23eeaafd8;
    if (1 < lVar7) {
      *DAT_23eeaafd8 = lVar7 + -1;
      goto LAB_23e1203a2;
    }
    if (DAT_23eeaafd8[2] != 0) {
      *DAT_23eeaafd8 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e1203a2;
    }
  }
  plVar3 = DAT_23eeaafd8;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar10 = DAT_23eeaafd8 + 9;
  lVar17 = *(longlong *)(lVar7 + 8);
  DAT_23eeaafd8[0xf] = lVar17;
  *(longlong **)(lVar7 + 8) = plVar10;
  if ((lVar17 != 0) &&
     (((*(char *)(lVar17 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar17 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar17 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar17 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar17 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar7 = FUN_23e900070();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&plStack_78,DAT_23eea8b60);
    plStack_98 = plStack_78;
    plStack_90 = plStack_70;
    plVar8 = (longlong *)0x0;
    plVar10 = plStack_68;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0xf;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,lVar7,DAT_23eea8b68);
    if (plVar8 != (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
      plVar10 = DAT_23eea8b70;
      lVar7 = DAT_23ed6cce8;
      if (plVar9 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        uStack_88 = 0x10;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_b0 = (longlong *)0x0;
        plStack_c0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      lVar17 = *(longlong *)(param_1 + 0x10);
      plVar11 = *(longlong **)(DAT_23ed6cce8 + 0x20);
      iVar16 = *(int *)(lVar17 + 0x1410);
      *plVar11 = *plVar11 + 1;
      if (iVar16 == 0) {
        plVar12 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
        plVar11 = *(longlong **)(lVar7 + 0x20);
      }
      else {
        iVar16 = iVar16 + -1;
        *(int *)(lVar17 + 0x1410) = iVar16;
        plVar12 = *(longlong **)(lVar17 + 0x1190 + (longlong)iVar16 * 8);
        *plVar12 = 1;
      }
      lVar7 = *(longlong *)(lVar7 + 0x28);
      plVar12[2] = 0;
      plVar12[4] = (longlong)plVar11;
      plVar12[5] = lVar7;
      plVar12[3] = 1;
      *(undefined4 *)(plVar3 + 5) = 0x10;
      plStack_78 = plVar10;
      plStack_70 = plVar12;
      plStack_c0 = (longlong *)FUN_23e94ed00(param_1,plVar9,&plStack_78);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plStack_c0 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        uStack_88 = 0x10;
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_b0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e121880;
      }
      lVar7 = *(longlong *)(DAT_23eea8b50 + 0x20);
      if (*(char *)(lVar7 + 10) == '\0') {
        plVar10 = (longlong *)FUN_23a37a020(DAT_23eea8b50,DAT_23eea8b78);
        if (plVar10 == (longlong *)0x0) goto LAB_23e1217d9;
        lVar7 = *plVar10;
LAB_23e121f08:
        if (lVar7 == 0) goto LAB_23e1217d9;
      }
      else {
        iVar16 = *(int *)(lVar7 + 0xc);
        if (*(int *)(lVar7 + 0xc) == 0) {
          *(int *)(lVar7 + 0xc) = DAT_23ec14c64;
          iVar16 = DAT_23ec14c64;
          DAT_23ec14c64 = DAT_23ec14c64 + 1;
        }
        if (DAT_23ec14c60 != iVar16) {
          DAT_23ec14c60 = iVar16;
          DAT_23eeaafb8 = FUN_23e8cbd60(lVar7,DAT_23eea8b78,*(undefined8 *)(DAT_23eea8b78 + 0x18));
        }
        if (-1 < DAT_23eeaafb8) {
          lVar17 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
          if (*(longlong *)(lVar17 + 8 + DAT_23eeaafb8 * 0x10) != 0) goto LAB_23e1205bc;
          DAT_23eeaafb8 = FUN_23e8cbd60(lVar7,DAT_23eea8b78,*(undefined8 *)(DAT_23eea8b78 + 0x18));
          if (-1 < DAT_23eeaafb8) {
            lVar7 = *(longlong *)(lVar17 + 8 + DAT_23eeaafb8 * 0x10);
            goto LAB_23e121f08;
          }
        }
LAB_23e1217d9:
        plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea8b78);
        if ((plVar10 == (longlong *)0x0) || (*plVar10 == 0)) {
          plVar13 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          FUN_23e915740(param_1,&plStack_78,DAT_23eea8b78);
          uStack_88 = 0x12;
          plStack_a0 = (longlong *)0x0;
          plStack_a8 = (longlong *)0x0;
          plStack_98 = plStack_78;
          plStack_b8 = (longlong *)0x0;
          plStack_90 = plStack_70;
          plStack_b0 = (longlong *)0x0;
          plVar10 = plStack_68;
          goto LAB_23e121880;
        }
      }
LAB_23e1205bc:
      *(undefined4 *)(plVar3 + 5) = 0x12;
      plVar9 = (longlong *)FUN_23e91a870(param_1);
      if (plVar9 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        uStack_88 = 0x12;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_b0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e121880;
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plStack_c0,DAT_23ed6ce40);
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        uStack_88 = 0x15;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_b0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar11 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x15;
      plStack_b0 = (longlong *)FUN_23e9557e0(param_1,plVar10,DAT_23eea8b80);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plStack_b0 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        uStack_88 = 0x15;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e121880;
      }
      plVar11 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eea8b88);
      if (plVar11 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar11 = (longlong *)0x0;
        uStack_88 = 0x16;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar12 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      iVar16 = FUN_23a35f020(plStack_b0);
      if (iVar16 == -1) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        uStack_88 = 0x17;
        plVar13 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      lVar7 = *(longlong *)(param_1 + 0x10);
      plVar10 = DAT_23eea8b98;
      if (iVar16 != 0) {
        plVar10 = DAT_23eea8b90;
      }
      plVar12 = *(longlong **)(lVar7 + 0xe20);
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar17 = plVar12[3];
        *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
        *(longlong *)(lVar7 + 0xe20) = lVar17;
        *plVar12 = 1;
      }
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar17 = plVar12[-1];
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = plVar12 + -2;
      plVar13 = DAT_23eea8ba0;
      plVar12[-2] = lVar7;
      plVar12[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar7 + 8) = plVar12 + -2;
      *plVar10 = *plVar10 + 1;
      plVar12[3] = (longlong)plVar10;
      *plVar13 = *plVar13 + 1;
      plVar12[4] = (longlong)plVar13;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      uVar4 = DAT_23eea8bb0;
      plVar12 = DAT_23eea8ba8;
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plStack_b8 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        uStack_88 = 0x17;
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x16;
      plStack_70 = plVar12;
      plStack_78 = plVar10;
      plVar12 = (longlong *)FUN_23e9186b0(param_1,plVar11,&plStack_78,uVar4);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar12 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        uStack_88 = 0x16;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_b8 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      lVar7 = *plVar12;
      *plVar12 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plStack_c0,DAT_23ed6ce40);
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar11 = (longlong *)0x0;
        uStack_88 = 0x1c;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar12 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x1c;
      plVar11 = (longlong *)FUN_23e9557e0(param_1,plVar10,DAT_23eea8bb8);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar11 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        uStack_88 = 0x1c;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e121880;
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eea8b88);
      if (plVar12 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        uStack_88 = 0x1d;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_b8 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      iVar16 = FUN_23a35f020(plVar11);
      if (iVar16 == -1) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar7 = *plVar12;
        *plVar12 = lVar7 + -1;
        if (lVar7 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        plStack_b8 = (longlong *)0x0;
        uStack_88 = 0x1e;
        plVar13 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      lVar7 = *(longlong *)(param_1 + 0x10);
      plVar10 = DAT_23eea8b98;
      if (iVar16 != 0) {
        plVar10 = DAT_23eea8b90;
      }
      plVar13 = *(longlong **)(lVar7 + 0xe20);
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar17 = plVar13[3];
        *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
        *(longlong *)(lVar7 + 0xe20) = lVar17;
        *plVar13 = 1;
      }
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar17 = plVar13[-1];
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = plVar13 + -2;
      plVar14 = DAT_23eea8bc0;
      plVar13[-2] = lVar7;
      plVar13[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar7 + 8) = plVar13 + -2;
      *plVar10 = *plVar10 + 1;
      plVar13[3] = (longlong)plVar10;
      *plVar14 = *plVar14 + 1;
      plVar13[4] = (longlong)plVar14;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar13 = DAT_23eea8bc8;
      uVar4 = DAT_23eea8bb0;
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar7 = *plVar12;
        *plVar12 = lVar7 + -1;
        if (lVar7 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
        }
        plStack_a0 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        uStack_88 = 0x1e;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x1d;
      plStack_70 = plVar13;
      plStack_78 = plVar10;
      plVar13 = (longlong *)FUN_23e9186b0(param_1,plVar12,&plStack_78,uVar4);
      lVar7 = *plVar12;
      *plVar12 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar13 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        uStack_88 = 0x1d;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_a8 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      lVar7 = *plVar13;
      *plVar13 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plStack_c0,DAT_23ed6ce40);
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        uStack_88 = 0x23;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_b8 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x23;
      plVar12 = (longlong *)FUN_23e9557e0(param_1,plVar10,DAT_23eea8bd0);
      lVar7 = *plVar10;
      *plVar10 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar12 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x23;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e121880;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eea8b88);
      if (plVar14 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x24;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_a8 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      iVar16 = FUN_23a35f020(plVar12);
      if (iVar16 == -1) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar7 = *plVar14;
        *plVar14 = lVar7 + -1;
        if (lVar7 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        plStack_a0 = (longlong *)0x0;
        uStack_88 = 0x25;
        plVar13 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      lVar7 = *(longlong *)(param_1 + 0x10);
      plVar10 = DAT_23eea8b98;
      if (iVar16 != 0) {
        plVar10 = DAT_23eea8b90;
      }
      plVar13 = *(longlong **)(lVar7 + 0xe20);
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar17 = plVar13[3];
        *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
        *(longlong *)(lVar7 + 0xe20) = lVar17;
        *plVar13 = 1;
      }
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar17 = plVar13[-1];
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = plVar13 + -2;
      plVar15 = DAT_23eea8bd8;
      plVar13[-2] = lVar7;
      plVar13[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar7 + 8) = plVar13 + -2;
      *plVar10 = *plVar10 + 1;
      plVar13[3] = (longlong)plVar10;
      *plVar15 = *plVar15 + 1;
      plVar13[4] = (longlong)plVar15;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar13 = DAT_23eea8be0;
      uVar4 = DAT_23eea8bb0;
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar7 = *plVar14;
        *plVar14 = lVar7 + -1;
        plStack_b8 = (longlong *)0x0;
        if (lVar7 + -1 == 0) {
          plVar13 = (longlong *)0x0;
          (**(code **)(plVar14[1] + 0x30))(plVar14);
          uStack_88 = 0x25;
          plStack_a0 = (longlong *)0x0;
          plStack_a8 = (longlong *)0x0;
        }
        else {
          plStack_a0 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          uStack_88 = 0x25;
          plStack_a8 = (longlong *)0x0;
        }
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x24;
      plStack_70 = plVar13;
      plStack_78 = plVar10;
      plVar13 = (longlong *)FUN_23e9186b0(param_1,plVar14,&plStack_78,uVar4);
      lVar7 = *plVar14;
      *plVar14 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      lVar7 = *plVar10;
      *plVar10 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar13 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x24;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a8 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_a0 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      lVar7 = *plVar13;
      *plVar13 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plStack_c0,DAT_23ed6ce40);
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x2a;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_a8 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x2a;
      plStack_b8 = (longlong *)FUN_23e9557e0(param_1,plVar10);
      lVar7 = *plVar10;
      *plVar10 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plStack_b8 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x2a;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e121880;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eea8b88);
      if (plVar14 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x2b;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_a0 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      iVar16 = FUN_23a35f020(plStack_b8);
      if (iVar16 == -1) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar7 = *plVar14;
        *plVar14 = lVar7 + -1;
        if (lVar7 + -1 == 0) {
          plVar13 = (longlong *)0x0;
          FUN_23a334bc0(plVar14);
          uStack_88 = 0x2c;
          plStack_a0 = (longlong *)0x0;
          plStack_a8 = (longlong *)0x0;
        }
        else {
          uStack_88 = 0x2c;
          plVar13 = (longlong *)0x0;
          plStack_a0 = (longlong *)0x0;
          plStack_a8 = (longlong *)0x0;
        }
        goto LAB_23e121880;
      }
      lVar7 = *(longlong *)(param_1 + 0x10);
      plVar10 = DAT_23eea8b98;
      if (iVar16 != 0) {
        plVar10 = DAT_23eea8b90;
      }
      plVar13 = *(longlong **)(lVar7 + 0xe20);
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar17 = plVar13[3];
        *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
        *(longlong *)(lVar7 + 0xe20) = lVar17;
        *plVar13 = 1;
      }
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar17 = plVar13[-1];
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = plVar13 + -2;
      plVar15 = DAT_23eea8bf0;
      plVar13[-2] = lVar7;
      plVar13[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar7 + 8) = plVar13 + -2;
      *plVar10 = *plVar10 + 1;
      plVar13[3] = (longlong)plVar10;
      *plVar15 = *plVar15 + 1;
      plVar13[4] = (longlong)plVar15;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar13 = DAT_23eea8bf8;
      uVar4 = DAT_23eea8bb0;
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar7 = *plVar14;
        *plVar14 = lVar7 + -1;
        plStack_a8 = (longlong *)0x0;
        if (lVar7 + -1 == 0) {
          plVar13 = (longlong *)0x0;
          (**(code **)(plVar14[1] + 0x30))();
          uStack_88 = 0x2c;
          plStack_a0 = (longlong *)0x0;
        }
        else {
          plStack_a0 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          uStack_88 = 0x2c;
        }
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x2b;
      plStack_70 = plVar13;
      plStack_78 = plVar10;
      plVar13 = (longlong *)FUN_23e9186b0(param_1,plVar14,&plStack_78,uVar4);
      lVar7 = *plVar14;
      *plVar14 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      lVar7 = *plVar10;
      *plVar10 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar13 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plStack_a0 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x2b;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plStack_c0,DAT_23ed6ce40);
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x31;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_a0 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x31;
      plStack_a8 = (longlong *)FUN_23e9557e0(param_1,plVar10,DAT_23eea8c00);
      lVar7 = *plVar10;
      *plVar10 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plStack_a8 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x31;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_a0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e121880;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eea8b88);
      if (plVar14 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x32;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_a0 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      iVar16 = FUN_23a35f020();
      if (iVar16 == -1) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        lVar7 = *plVar14;
        *plVar14 = lVar7 + -1;
        if (lVar7 + -1 == 0) {
          plVar13 = (longlong *)0x0;
          FUN_23a334bc0(plVar14);
          uStack_88 = 0x33;
          plStack_a0 = (longlong *)0x0;
        }
        else {
          uStack_88 = 0x33;
          plVar13 = (longlong *)0x0;
          plStack_a0 = (longlong *)0x0;
        }
        goto LAB_23e121880;
      }
      lVar7 = *(longlong *)(param_1 + 0x10);
      plVar10 = DAT_23eea8b98;
      if (iVar16 != 0) {
        plVar10 = DAT_23eea8b90;
      }
      plVar13 = *(longlong **)(lVar7 + 0xe20);
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar17 = plVar13[3];
        *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
        *(longlong *)(lVar7 + 0xe20) = lVar17;
        *plVar13 = 1;
      }
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar17 = plVar13[-1];
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = plVar13 + -2;
      plVar15 = DAT_23eea8c08;
      plVar13[-2] = lVar7;
      plVar13[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar7 + 8) = plVar13 + -2;
      *plVar10 = *plVar10 + 1;
      plVar13[3] = (longlong)plVar10;
      *plVar15 = *plVar15 + 1;
      plVar13[4] = (longlong)plVar15;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar13 = DAT_23eea8c10;
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar7 = *plVar14;
        *plVar14 = lVar7 + -1;
        plVar13 = (longlong *)0x0;
        if (lVar7 + -1 == 0) {
          FUN_23a334bc0();
          uStack_88 = 0x33;
          plStack_a0 = (longlong *)0x0;
        }
        else {
          uStack_88 = 0x33;
          plStack_a0 = (longlong *)0x0;
        }
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x32;
      plStack_70 = plVar13;
      plStack_78 = plVar10;
      plVar13 = (longlong *)FUN_23e9186b0(param_1,plVar14,&plStack_78);
      lVar7 = *plVar14;
      *plVar14 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar13 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x32;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_a0 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plStack_c0,DAT_23ed6ce40);
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plStack_a0 = (longlong *)0x0;
        uStack_88 = 0x38;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e121880;
      }
      *(undefined4 *)(plVar3 + 5) = 0x38;
      plStack_a0 = (longlong *)FUN_23e9557e0(param_1,plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plStack_a0 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x38;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e121880;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar9);
      if (plVar14 == (longlong *)0x0) {
LAB_23e122afd:
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x39;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e121880;
      }
      iVar16 = FUN_23a35f020(plStack_a0);
      if (iVar16 == -1) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          plVar13 = (longlong *)0x0;
          FUN_23a334bc0(plVar14);
          uStack_88 = 0x3a;
        }
        else {
          uStack_88 = 0x3a;
          plVar13 = (longlong *)0x0;
        }
        goto LAB_23e121880;
      }
      lVar7 = *(longlong *)(param_1 + 0x10);
      plVar10 = DAT_23eea8b98;
      if (iVar16 != 0) {
        plVar10 = DAT_23eea8b90;
      }
      plVar13 = *(longlong **)(lVar7 + 0xe20);
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar17 = plVar13[3];
        *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
        *(longlong *)(lVar7 + 0xe20) = lVar17;
        *plVar13 = 1;
      }
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar17 = plVar13[-1];
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = plVar13 + -2;
      plVar15 = DAT_23eea8c20;
      plVar13[-2] = lVar7;
      plVar13[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar7 + 8) = plVar13 + -2;
      *plVar10 = *plVar10 + 1;
      plVar13[3] = (longlong)plVar10;
      *plVar15 = *plVar15 + 1;
      plVar13[4] = (longlong)plVar15;
      plVar10 = (longlong *)PyUnicode_Join();
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))();
      }
      plVar13 = DAT_23eea8c28;
      uVar4 = DAT_23eea8bb0;
      if (plVar10 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0x3a;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        lVar7 = *plVar14;
        plVar13 = (longlong *)0x0;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0x39;
        plStack_70 = plVar13;
        plStack_78 = plVar10;
        plVar13 = (longlong *)FUN_23e9186b0(param_1,plVar14,&plStack_78,uVar4);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar13 == (longlong *)0x0) goto LAB_23e122afd;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(plStack_c0,DAT_23ed6ce40);
        if (plVar10 == (longlong *)0x0) {
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar10 = *(longlong **)(param_1 + 0x70);
          plVar13 = (longlong *)0x0;
          uStack_88 = 0x3f;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          goto LAB_23e121880;
        }
        *(undefined4 *)(plVar3 + 5) = 0x3f;
        plVar13 = (longlong *)FUN_23e9557e0(param_1,plVar10,DAT_23eea8c30);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          FUN_23a334bc0(plVar10);
        }
        if (plVar13 == (longlong *)0x0) {
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar10 = *(longlong **)(param_1 + 0x70);
          uStack_88 = 0x3f;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          goto LAB_23e121880;
        }
        plVar14 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eea8b88);
        if (plVar14 == (longlong *)0x0) {
LAB_23e122e82:
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar10 = *(longlong **)(param_1 + 0x70);
          uStack_88 = 0x40;
          plStack_90 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          goto LAB_23e121880;
        }
        iVar16 = FUN_23a35f020(plVar13);
        if (iVar16 != -1) {
          lVar7 = *(longlong *)(param_1 + 0x10);
          plVar10 = DAT_23eea8b98;
          if (iVar16 != 0) {
            plVar10 = DAT_23eea8b90;
          }
          plVar15 = *(longlong **)(lVar7 + 0xe20);
          if (plVar15 == (longlong *)0x0) {
            plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar17 = plVar15[3];
            *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
            *(longlong *)(lVar7 + 0xe20) = lVar17;
            *plVar15 = 1;
          }
          lVar7 = *(longlong *)
                   (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar17 = plVar15[-1];
          puVar2 = *(undefined8 **)(lVar7 + 8);
          *puVar2 = plVar15 + -2;
          plVar5 = DAT_23eea8c38;
          plVar15[-2] = lVar7;
          plVar15[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar7 + 8) = plVar15 + -2;
          *plVar10 = *plVar10 + 1;
          plVar15[3] = (longlong)plVar10;
          *plVar5 = *plVar5 + 1;
          plVar15[4] = (longlong)plVar5;
          plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            FUN_23a334bc0(plVar15);
          }
          plVar15 = DAT_23eea8c40;
          uVar4 = DAT_23eea8bb0;
          if (plVar10 != (longlong *)0x0) {
            *(undefined4 *)(plVar3 + 5) = 0x40;
            plStack_70 = plVar15;
            plStack_78 = plVar10;
            plVar15 = (longlong *)FUN_23e9186b0(param_1,plVar14,&plStack_78,uVar4);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              FUN_23a334bc0(plVar14);
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              FUN_23a334bc0(plVar10);
            }
            if (plVar15 == (longlong *)0x0) goto LAB_23e122e82;
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              FUN_23a334bc0(plVar15);
            }
            lVar7 = DAT_23eea8c50;
            *(undefined4 *)(plVar3 + 5) = 0x45;
            plVar10 = (longlong *)
                      FUN_23e915840(param_1,plVar9,DAT_23eea8c48,*(undefined8 *)(lVar7 + 0x18));
            if (plVar10 == (longlong *)0x0) {
              plStack_98 = *(longlong **)(param_1 + 0x60);
              plVar10 = *(longlong **)(param_1 + 0x70);
              uStack_88 = 0x45;
              plStack_90 = *(longlong **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              goto LAB_23e121880;
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              FUN_23a334bc0(plVar10);
            }
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eea8c58);
            if (plVar10 == (longlong *)0x0) {
LAB_23e122ec3:
              plStack_98 = *(longlong **)(param_1 + 0x60);
              plVar10 = *(longlong **)(param_1 + 0x70);
              uStack_88 = 0x46;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_90 = *(longlong **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              lVar7 = *(longlong *)(DAT_23eea8b50 + 0x20);
              if (*(char *)(lVar7 + 10) == '\0') {
                plVar14 = (longlong *)FUN_23a37a020(DAT_23eea8b50,DAT_23eea8c60);
                if (plVar14 == (longlong *)0x0) goto LAB_23e122da1;
                lVar17 = *plVar14;
LAB_23e122d98:
                if (lVar17 == 0) goto LAB_23e122da1;
LAB_23e121515:
                lVar7 = DAT_23eea8c68;
                *(undefined4 *)(plVar3 + 5) = 0x46;
                plVar14 = (longlong *)FUN_23e9186b0(param_1,lVar17,lVar7 + 0x18);
                if (plVar14 != (longlong *)0x0) {
                  *(undefined4 *)(plVar3 + 5) = 0x46;
                  plVar15 = (longlong *)FUN_23e914090(param_1,plVar10,plVar14);
                  lVar7 = *plVar10;
                  *plVar10 = lVar7 + -1;
                  if (lVar7 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    FUN_23a334bc0(plVar14);
                  }
                  if (plVar15 != (longlong *)0x0) {
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      FUN_23a334bc0(plVar15);
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x48;
                    lVar7 = FUN_23e91bfe0(param_1,plVar9,DAT_23eea8c70);
                    if (lVar7 != 0) {
                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        FUN_23a334bc0(plVar8);
                      }
                      lVar17 = *plStack_c0;
                      *plStack_c0 = lVar17 + -1;
                      if (lVar17 + -1 == 0) {
                        FUN_23a334bc0(plStack_c0);
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        FUN_23a334bc0(plVar9);
                      }
                      lVar17 = *plStack_b0;
                      *plStack_b0 = lVar17 + -1;
                      if (lVar17 + -1 == 0) {
                        FUN_23a334bc0(plStack_b0);
                      }
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        FUN_23a334bc0(plVar11);
                      }
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0(plVar12);
                      }
                      lVar17 = *plStack_b8;
                      *plStack_b8 = lVar17 + -1;
                      if (lVar17 + -1 == 0) {
                        FUN_23a334bc0(plStack_b8);
                      }
                      lVar17 = *plStack_a8;
                      *plStack_a8 = lVar17 + -1;
                      if (lVar17 + -1 == 0) {
                        FUN_23a334bc0(plStack_a8);
                      }
                      lVar17 = *plStack_a0;
                      *plStack_a0 = lVar17 + -1;
                      if (lVar17 + -1 == 0) {
                        FUN_23a334bc0(plStack_a0);
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                        return lVar7;
                      }
                      return lVar7;
                    }
                    plStack_98 = *(longlong **)(param_1 + 0x60);
                    plVar10 = *(longlong **)(param_1 + 0x70);
                    uStack_88 = 0x48;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_90 = *(longlong **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e121880;
                  }
                  goto LAB_23e122ec3;
                }
                plStack_98 = *(longlong **)(param_1 + 0x60);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_90 = *(longlong **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                lVar7 = *plVar10 + -1;
                *plVar10 = lVar7;
              }
              else {
                iVar16 = *(int *)(lVar7 + 0xc);
                if (*(int *)(lVar7 + 0xc) == 0) {
                  *(int *)(lVar7 + 0xc) = DAT_23ec14c64;
                  iVar16 = DAT_23ec14c64;
                  DAT_23ec14c64 = DAT_23ec14c64 + 1;
                }
                if (DAT_23ec14c68 != iVar16) {
                  DAT_23ec14c68 = iVar16;
                  DAT_23eeaafc0 =
                       FUN_23e8cbd60(lVar7,DAT_23eea8c60,*(undefined8 *)(DAT_23eea8c60 + 0x18));
                }
                if (-1 < DAT_23eeaafc0) {
                  lVar1 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
                  lVar17 = *(longlong *)(lVar1 + 8 + DAT_23eeaafc0 * 0x10);
                  if (lVar17 != 0) goto LAB_23e121515;
                  DAT_23eeaafc0 =
                       FUN_23e8cbd60(lVar7,DAT_23eea8c60,*(undefined8 *)(DAT_23eea8c60 + 0x18));
                  if (-1 < DAT_23eeaafc0) {
                    lVar17 = *(longlong *)(lVar1 + 8 + DAT_23eeaafc0 * 0x10);
                    goto LAB_23e122d98;
                  }
                }
LAB_23e122da1:
                plVar14 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea8c60);
                if ((plVar14 != (longlong *)0x0) && (lVar17 = *plVar14, lVar17 != 0))
                goto LAB_23e121515;
                FUN_23e915740(param_1,&plStack_78,DAT_23eea8c60);
                lVar7 = *plVar10 + -1;
                *plVar10 = lVar7;
                plStack_98 = plStack_78;
                plStack_90 = plStack_70;
              }
              uStack_88 = 0x46;
              plVar10 = plStack_68;
              if (lVar7 == 0) {
                FUN_23a334bc0();
                uStack_88 = 0x46;
              }
            }
            goto LAB_23e121880;
          }
        }
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        uStack_88 = 0x41;
        plStack_90 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar14 = *plVar14 + -1;
        lVar7 = *plVar14;
      }
      if (lVar7 == 0) {
        FUN_23a334bc0(plVar14);
      }
      goto LAB_23e121880;
    }
    plStack_98 = *(longlong **)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_90 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  plStack_b8 = (longlong *)0x0;
  plVar13 = (longlong *)0x0;
  plVar12 = (longlong *)0x0;
  plVar9 = (longlong *)0x0;
  plStack_a0 = (longlong *)0x0;
  plVar11 = (longlong *)0x0;
  uStack_88 = 0xf;
  plStack_a8 = (longlong *)0x0;
  plStack_b0 = (longlong *)0x0;
  plStack_c0 = (longlong *)0x0;
LAB_23e121880:
  plVar14 = DAT_23ed6a4f8;
  if (plVar10 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar7 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uStack_88;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar17 = plVar14[-1];
    puVar2 = *(undefined8 **)(lVar7 + 8);
    *puVar2 = plVar14 + -2;
    plVar14[-2] = lVar7;
    plVar14[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar7 + 8) = plVar14 + -2;
    plVar15 = plVar14;
  }
  else {
    plVar15 = plVar10;
    if ((longlong *)plVar10[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar14[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      *(undefined4 *)((longlong)plVar14 + 0x24) = uStack_88;
      pcVar6 = _PyRuntime_exref;
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
      lVar17 = plVar14[-1];
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = plVar14 + -2;
      plVar14[-2] = lVar7;
      plVar14[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
      lVar17 = *plVar10;
      *(longlong **)(lVar7 + 8) = plVar14 + -2;
      plVar14[2] = (longlong)plVar10;
      plVar15 = plVar14;
      if (lVar17 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar3,"oooooooooo",plVar8,plStack_c0,plVar9,plStack_b0,plVar11,plVar12,plStack_b8,
                plStack_a8,plStack_a0,plVar13);
  if (DAT_23eeaafd8 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eeaafd8 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar7 + 0x28);
  plVar3 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plStack_c0 != (longlong *)0x0) &&
     (lVar7 = *plStack_c0, *plStack_c0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plStack_b0 != (longlong *)0x0) &&
     (lVar7 = *plStack_b0, *plStack_b0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plStack_b8 != (longlong *)0x0) &&
     (lVar7 = *plStack_b8, *plStack_b8 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
  }
  if ((plStack_a8 != (longlong *)0x0) &&
     (lVar7 = *plStack_a8, *plStack_a8 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_a8[1] + 0x30))(plStack_a8);
  }
  if ((plStack_a0 != (longlong *)0x0) &&
     (lVar7 = *plStack_a0, *plStack_a0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  FUN_23a33aa70(param_1,plStack_98,plStack_90,plVar15);
  return 0;
}
