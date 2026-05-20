/* ===== 23e2f26d0 ui.ios_toggle:c746 ===== */
/* ghidra_name=forced_23e2f26d0 entry=23e2f26d0 size=5201 */

code * forced_23e2f26d0(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  undefined8 uVar8;
  code *pcVar9;
  char cVar10;
  int iVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong lVar17;
  undefined4 uVar18;
  code *pcStack_88;
  undefined8 uStack_80;
  longlong *aplStack_78 [2];
  longlong *plStack_68;
  longlong *plStack_60;
  longlong *plStack_58;
  undefined4 uVar19;
  
  plVar12 = DAT_23eeb0080;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  plVar4 = (longlong *)param_3[2];
  plVar5 = (longlong *)param_3[3];
  aplStack_78[0] = (longlong *)0x0;
  pcStack_88 = (code *)0x0;
  uStack_80 = 0;
  if (DAT_23eeb0080 == (longlong *)0x0) {
LAB_23e2f2735:
    DAT_23eeb0080 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0070,DAT_23eeb0078,0x28);
  }
  else {
    lVar15 = *DAT_23eeb0080;
    if (1 < lVar15) {
      *DAT_23eeb0080 = lVar15 + -1;
      goto LAB_23e2f2735;
    }
    if (DAT_23eeb0080[2] != 0) {
      *DAT_23eeb0080 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e2f2735;
    }
  }
  plVar7 = DAT_23eeb0080;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar12 = DAT_23eeb0080 + 9;
  lVar17 = *(longlong *)(lVar15 + 8);
  DAT_23eeb0080[0xf] = lVar17;
  *(longlong **)(lVar15 + 8) = plVar12;
  if ((lVar17 != 0) &&
     (((*(char *)(lVar17 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar17 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar17 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar17 + 0x38))) && (plVar7[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar17 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  *(undefined4 *)(plVar7 + 8) = 0;
  lVar15 = *(longlong *)(*(longlong *)(param_2 + 0xd8) + 0x10);
  if (lVar15 == 0) {
    if (((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x40) == 0) ||
       ((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x20) == 0)) {
      lVar15 = *(longlong *)(DAT_23ed6cd40 + 0x38);
    }
    else {
      lVar15 = DAT_23ed6cd40 + 0x30;
    }
    uStack_80 = PyUnicode_FromFormat
                          ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                           ,lVar15);
    pcStack_88 = *(code **)PyExc_NameError_exref;
    *(longlong *)pcStack_88 = *(longlong *)pcStack_88 + 1;
    aplStack_78[0] = (longlong *)0x0;
    if (pcStack_88 != _Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,&pcStack_88,&uStack_80,aplStack_78);
    }
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),uStack_80);
    uVar19 = 0xd;
    plVar12 = aplStack_78[0];
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e2f2bcb;
  }
  plVar12 = (longlong *)FUN_23e954510(param_1,DAT_23eead078,lVar15,plVar2);
  if (plVar12 != (longlong *)0x0) {
    *(undefined4 *)(plVar7 + 5) = 0xd;
    plVar13 = (longlong *)FUN_23e915840(param_1,plVar12,DAT_23ed6cdb0,plVar3);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd20,plVar4);
      if (cVar10 == '\0') {
        plVar12 = *(longlong **)(param_1 + 0x70);
        pcStack_88 = *(code **)(param_1 + 0x60);
        uStack_80 = *(undefined8 *)(param_1 + 0x68);
        uVar19 = 0xe;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = DAT_23ed6a4f8;
        goto joined_r0x00023e2f2bcb;
      }
      cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd28,plVar5);
      if (cVar10 == '\0') {
        pcStack_88 = *(code **)(param_1 + 0x60);
        uStack_80 = *(undefined8 *)(param_1 + 0x68);
        plVar12 = *(longlong **)(param_1 + 0x70);
        uVar19 = 0xf;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = DAT_23ed6a4f8;
        goto joined_r0x00023e2f2bcb;
      }
      iVar11 = FUN_23a35f020(plVar5);
      if (iVar11 == -1) {
        pcStack_88 = *(code **)(param_1 + 0x60);
        uStack_80 = *(undefined8 *)(param_1 + 0x68);
        plVar12 = *(longlong **)(param_1 + 0x70);
        uVar19 = 0x11;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = DAT_23ed6a4f8;
        goto joined_r0x00023e2f2bcb;
      }
      if (iVar11 == 0) {
        iVar11 = FUN_23a35f020(plVar4);
        if (iVar11 == -1) {
          pcStack_88 = *(code **)(param_1 + 0x60);
          uStack_80 = *(undefined8 *)(param_1 + 0x68);
          plVar12 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0x18;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2f2bcb;
        }
        if (iVar11 == 0) {
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd38,DAT_23eeacd98);
          if (cVar10 == '\0') {
            pcStack_88 = *(code **)(param_1 + 0x60);
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x21;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e2f2bcb;
          }
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd48,DAT_23eeacda0);
          if (cVar10 == '\0') {
            pcStack_88 = *(code **)(param_1 + 0x60);
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x22;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e2f2bcb;
          }
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd58,DAT_23eeacda8);
          if (cVar10 == '\0') {
            pcStack_88 = *(code **)(param_1 + 0x60);
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x23;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e2f2bcb;
          }
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd68,DAT_23eeacd60);
          if (cVar10 == '\0') {
            pcStack_88 = *(code **)(param_1 + 0x60);
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x24;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e2f2bcb;
          }
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd78,DAT_23eeacd40);
          if (cVar10 == '\0') {
            pcStack_88 = *(code **)(param_1 + 0x60);
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x25;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e2f2bcb;
          }
        }
        else {
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd38,DAT_23eeacd80);
          if (cVar10 == '\0') {
            pcStack_88 = *(code **)(param_1 + 0x60);
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x1a;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e2f2bcb;
          }
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd48,DAT_23eeacd88);
          if (cVar10 == '\0') {
            pcStack_88 = *(code **)(param_1 + 0x60);
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x1b;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e2f2bcb;
          }
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd58,DAT_23eeacd40);
          if (cVar10 == '\0') {
            pcStack_88 = *(code **)(param_1 + 0x60);
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x1c;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e2f2bcb;
          }
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd68,DAT_23eeacd60);
          if (cVar10 == '\0') {
            pcStack_88 = *(code **)(param_1 + 0x60);
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x1d;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e2f2bcb;
          }
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd78,DAT_23eeacd90);
          if (cVar10 == '\0') {
            pcStack_88 = *(code **)(param_1 + 0x60);
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x1e;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e2f2bcb;
          }
        }
      }
      else {
        cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd38,DAT_23eeacd30);
        if (cVar10 == '\0') {
          pcStack_88 = *(code **)(param_1 + 0x60);
          uStack_80 = *(undefined8 *)(param_1 + 0x68);
          plVar12 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0x13;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2f2bcb;
        }
        cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd48,DAT_23eeacd40);
        if (cVar10 == '\0') {
          pcStack_88 = *(code **)(param_1 + 0x60);
          uStack_80 = *(undefined8 *)(param_1 + 0x68);
          plVar12 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0x14;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2f2bcb;
        }
        cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd58,DAT_23eeacd50);
        if (cVar10 == '\0') {
          pcStack_88 = *(code **)(param_1 + 0x60);
          uStack_80 = *(undefined8 *)(param_1 + 0x68);
          plVar12 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0x15;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2f2bcb;
        }
        cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd68,DAT_23eeacd60);
        if (cVar10 == '\0') {
          pcStack_88 = *(code **)(param_1 + 0x60);
          uStack_80 = *(undefined8 *)(param_1 + 0x68);
          plVar12 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0x16;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2f2bcb;
        }
        cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacd78,DAT_23eeacd70);
        if (cVar10 == '\0') {
          pcStack_88 = *(code **)(param_1 + 0x60);
          uStack_80 = *(undefined8 *)(param_1 + 0x68);
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          uVar19 = 0x17;
          goto joined_r0x00023e2f2bcb;
        }
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacdb0);
      if (plVar14 == (longlong *)0x0) {
LAB_23e2f3750:
        pcStack_88 = *(code **)(param_1 + 0x60);
        uStack_80 = *(undefined8 *)(param_1 + 0x68);
        plVar12 = *(longlong **)(param_1 + 0x70);
        uVar19 = 0x27;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = DAT_23ed6a4f8;
        goto joined_r0x00023e2f2bcb;
      }
      lVar15 = FUN_23e8f5c20();
      if (lVar15 == 0) {
        FUN_23e915740(param_1,&pcStack_88,DAT_23eeacdb8);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
          uVar19 = 0x27;
          plVar12 = aplStack_78[0];
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2f2bcb;
        }
LAB_23e2f3914:
        uVar19 = 0x27;
        plVar12 = aplStack_78[0];
        plVar13 = DAT_23ed6a4f8;
        goto joined_r0x00023e2f2bcb;
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacd38);
      if (plVar12 == (longlong *)0x0) {
LAB_23e2f36a0:
        pcStack_88 = *(code **)(param_1 + 0x60);
        uStack_80 = *(undefined8 *)(param_1 + 0x68);
        aplStack_78[0] = *(longlong **)(param_1 + 0x70);
        uVar19 = 0x27;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        plVar12 = aplStack_78[0];
        plVar13 = DAT_23ed6a4f8;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
          uVar19 = 0x27;
          plVar12 = aplStack_78[0];
          plVar13 = DAT_23ed6a4f8;
        }
        goto joined_r0x00023e2f2bcb;
      }
      plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacd48);
      if (plVar13 == (longlong *)0x0) {
        pcStack_88 = *(code **)(param_1 + 0x60);
        uStack_80 = *(undefined8 *)(param_1 + 0x68);
        aplStack_78[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          uVar19 = 0x27;
          plVar12 = aplStack_78[0];
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2f2bcb;
        }
        goto LAB_23e2f3914;
      }
      *(undefined4 *)(plVar7 + 5) = 0x27;
      plStack_68 = plVar12;
      plStack_60 = plVar13;
      plVar16 = (longlong *)FUN_23e94ed00(param_1,lVar15,&plStack_68);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (plVar16 == (longlong *)0x0) goto LAB_23e2f36a0;
      *(undefined4 *)(plVar7 + 5) = 0x27;
      plVar12 = (longlong *)FUN_23e914090(param_1,plVar14,plVar16);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      if (plVar12 == (longlong *)0x0) goto LAB_23e2f3750;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacd68);
      if (plVar12 != (longlong *)0x0) {
        cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacdc0,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (cVar10 != '\0') {
          lVar15 = *(longlong *)(DAT_23eead078 + 0x20);
          if (*(char *)(lVar15 + 10) == '\0') {
            plVar12 = (longlong *)FUN_23a37a020(DAT_23eead078,DAT_23eeacdc8);
            if (plVar12 == (longlong *)0x0) goto LAB_23e2f3846;
            lVar17 = *plVar12;
LAB_23e2f383d:
            if (lVar17 == 0) goto LAB_23e2f3846;
          }
          else {
            iVar11 = *(int *)(lVar15 + 0xc);
            if (*(int *)(lVar15 + 0xc) == 0) {
              *(int *)(lVar15 + 0xc) = DAT_23ec14e28;
              iVar11 = DAT_23ec14e28;
              DAT_23ec14e28 = DAT_23ec14e28 + 1;
            }
            if (DAT_23ec14e24 != iVar11) {
              DAT_23ec14e24 = iVar11;
              DAT_23eeb0060 =
                   FUN_23e8cbd60(lVar15,DAT_23eeacdc8,*(undefined8 *)(DAT_23eeacdc8 + 0x18));
            }
            if (-1 < DAT_23eeb0060) {
              lVar1 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
              lVar17 = *(longlong *)(lVar1 + 8 + DAT_23eeb0060 * 0x10);
              if (lVar17 != 0) goto LAB_23e2f30ed;
              DAT_23eeb0060 =
                   FUN_23e8cbd60(lVar15,DAT_23eeacdc8,*(undefined8 *)(DAT_23eeacdc8 + 0x18));
              if (-1 < DAT_23eeb0060) {
                lVar17 = *(longlong *)(lVar1 + 8 + DAT_23eeb0060 * 0x10);
                goto LAB_23e2f383d;
              }
            }
LAB_23e2f3846:
            plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeacdc8);
            if ((plVar12 == (longlong *)0x0) || (lVar17 = *plVar12, lVar17 == 0)) {
              FUN_23e915740(param_1,&pcStack_88,DAT_23eeacdc8);
              uVar19 = 0x29;
              plVar12 = aplStack_78[0];
              plVar13 = DAT_23ed6a4f8;
              goto joined_r0x00023e2f2bcb;
            }
          }
LAB_23e2f30ed:
          plStack_60 = DAT_23eeacdd0;
          *(undefined4 *)(plVar7 + 5) = 0x29;
          plStack_68 = plVar2;
          plStack_58 = plVar2;
          plVar12 = (longlong *)FUN_23e956150(param_1,lVar17,&plStack_68);
          if (plVar12 != (longlong *)0x0) {
            cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eeacdd8,plVar12);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (cVar10 != '\0') {
              plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacdd8);
              if (plVar12 != (longlong *)0x0) {
                plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,DAT_23eeacde0);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if (plVar14 != (longlong *)0x0) {
                  lVar15 = *(longlong *)(DAT_23eead078 + 0x20);
                  if (*(char *)(lVar15 + 10) == '\0') {
                    plVar12 = (longlong *)FUN_23a37a020(DAT_23eead078,DAT_23eeacde8);
                    if (plVar12 == (longlong *)0x0) goto LAB_23e2f39f2;
                    lVar17 = *plVar12;
LAB_23e2f39e9:
                    if (lVar17 == 0) goto LAB_23e2f39f2;
                  }
                  else {
                    iVar11 = *(int *)(lVar15 + 0xc);
                    if (*(int *)(lVar15 + 0xc) == 0) {
                      *(int *)(lVar15 + 0xc) = DAT_23ec14e28;
                      iVar11 = DAT_23ec14e28;
                      DAT_23ec14e28 = DAT_23ec14e28 + 1;
                    }
                    if (DAT_23ec14e2c != iVar11) {
                      DAT_23ec14e2c = iVar11;
                      DAT_23eeb0068 =
                           FUN_23e8cbd60(lVar15,DAT_23eeacde8,*(undefined8 *)(DAT_23eeacde8 + 0x18))
                      ;
                    }
                    if (-1 < DAT_23eeb0068) {
                      lVar1 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
                      lVar17 = *(longlong *)(lVar1 + 8 + DAT_23eeb0068 * 0x10);
                      if (lVar17 != 0) goto LAB_23e2f320f;
                      DAT_23eeb0068 =
                           FUN_23e8cbd60(lVar15,DAT_23eeacde8,*(undefined8 *)(DAT_23eeacde8 + 0x18))
                      ;
                      if (-1 < DAT_23eeb0068) {
                        lVar17 = *(longlong *)(lVar1 + 8 + DAT_23eeb0068 * 0x10);
                        goto LAB_23e2f39e9;
                      }
                    }
LAB_23e2f39f2:
                    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeacde8);
                    if ((plVar12 == (longlong *)0x0) || (lVar17 = *plVar12, lVar17 == 0)) {
                      FUN_23e915740(param_1,&pcStack_88,DAT_23eeacde8);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        FUN_23a334bc0(plVar14);
                      }
                      uVar19 = 0x2a;
                      plVar12 = aplStack_78[0];
                      plVar13 = DAT_23ed6a4f8;
                      goto joined_r0x00023e2f2bcb;
                    }
                  }
LAB_23e2f320f:
                  plVar12 = (longlong *)FUN_23e8bc2f0(lVar17,DAT_23eeacdf0);
                  if (plVar12 == (longlong *)0x0) {
LAB_23e2f3a4a:
                    pcStack_88 = *(code **)(param_1 + 0x60);
                    uStack_80 = *(undefined8 *)(param_1 + 0x68);
                    aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                    uVar19 = 0x2a;
                    uVar18 = 0x2a;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar14 = *plVar14 + -1;
                    lVar15 = *plVar14;
                  }
                  else {
                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar12,DAT_23eeacdf8);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    if (plVar13 == (longlong *)0x0) goto LAB_23e2f3a4a;
                    *(undefined4 *)(plVar7 + 5) = 0x2a;
                    plVar12 = (longlong *)FUN_23e914090(param_1,plVar14);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    if (plVar12 == (longlong *)0x0) goto LAB_23e2f3983;
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeacdd8);
                    lVar15 = DAT_23eeace08;
                    uVar8 = DAT_23eeace00;
                    if (plVar12 == (longlong *)0x0) {
LAB_23e2f3ac1:
                      pcStack_88 = *(code **)(param_1 + 0x60);
                      uStack_80 = *(undefined8 *)(param_1 + 0x68);
                      plVar12 = *(longlong **)(param_1 + 0x70);
                      uVar19 = 0x2b;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar13 = DAT_23ed6a4f8;
                      goto joined_r0x00023e2f2bcb;
                    }
                    *(undefined4 *)(plVar7 + 5) = 0x2b;
                    plVar13 = (longlong *)
                              FUN_23e915840(param_1,plVar12,uVar8,*(undefined8 *)(lVar15 + 0x18));
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    if (plVar13 == (longlong *)0x0) goto LAB_23e2f3ac1;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    plVar12 = (longlong *)FUN_23e8bc2f0(plVar2);
                    if (plVar12 == (longlong *)0x0) {
LAB_23e2f3a96:
                      pcStack_88 = *(code **)(param_1 + 0x60);
                      uStack_80 = *(undefined8 *)(param_1 + 0x68);
                      plVar12 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar13 = DAT_23ed6a4f8;
                      uVar19 = 0x2c;
                      goto joined_r0x00023e2f2bcb;
                    }
                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar12);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      FUN_23a334bc0(plVar12);
                    }
                    if (plVar14 == (longlong *)0x0) goto LAB_23e2f3a96;
                    plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeace20);
                    if (plVar12 != (longlong *)0x0) {
                      *(undefined4 *)(plVar7 + 5) = 0x2c;
                      plVar13 = (longlong *)FUN_23e914090(param_1,plVar14,plVar12);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        FUN_23a334bc0(plVar14);
                      }
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0(plVar12);
                      }
                      if (plVar13 != (longlong *)0x0) {
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                        lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                        plVar12 = *(longlong **)(lVar15 + 0x28);
                        plVar7 = (longlong *)plVar12[2];
                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                             *(undefined8 *)(lVar15 + 0x30);
                        *(undefined4 *)(plVar12 + 8) = 0xffffffff;
                        if (plVar7 != (longlong *)0x0) {
                          plVar12[2] = 0;
                          *plVar7 = *plVar7 + -1;
                          if (*plVar7 == 0) {
                            (**(code **)(plVar7[1] + 0x30))();
                          }
                        }
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        plVar12[0xf] = 0;
                        pcVar9 = _Py_NoneStruct_exref;
                        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                        *plVar2 = *plVar2 + -1;
                        if (*plVar2 == 0) {
                          FUN_23a334bc0(plVar2);
                        }
                        *plVar3 = *plVar3 + -1;
                        if (*plVar3 == 0) {
                          FUN_23a334bc0(plVar3);
                        }
                        *plVar4 = *plVar4 + -1;
                        if (*plVar4 == 0) {
                          FUN_23a334bc0(plVar4);
                        }
                        *plVar5 = *plVar5 + -1;
                        if (*plVar5 != 0) {
                          return pcVar9;
                        }
                        FUN_23a334bc0(plVar5);
                        return pcVar9;
                      }
                      goto LAB_23e2f3a96;
                    }
                    pcStack_88 = *(code **)(param_1 + 0x60);
                    uStack_80 = *(undefined8 *)(param_1 + 0x68);
                    aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                    uVar19 = 0x2c;
                    uVar18 = 0x2c;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar14 = *plVar14 + -1;
                    lVar15 = *plVar14;
                  }
                  plVar12 = aplStack_78[0];
                  plVar13 = DAT_23ed6a4f8;
                  if (lVar15 == 0) {
                    FUN_23a334bc0(plVar14);
                    plVar12 = aplStack_78[0];
                    plVar13 = DAT_23ed6a4f8;
                    uVar19 = uVar18;
                  }
                  goto joined_r0x00023e2f2bcb;
                }
              }
LAB_23e2f3983:
              pcStack_88 = *(code **)(param_1 + 0x60);
              uStack_80 = *(undefined8 *)(param_1 + 0x68);
              plVar12 = *(longlong **)(param_1 + 0x70);
              uVar19 = 0x2a;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar13 = DAT_23ed6a4f8;
              goto joined_r0x00023e2f2bcb;
            }
          }
          pcStack_88 = *(code **)(param_1 + 0x60);
          uStack_80 = *(undefined8 *)(param_1 + 0x68);
          plVar12 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0x29;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e2f2bcb;
        }
      }
      pcStack_88 = *(code **)(param_1 + 0x60);
      uStack_80 = *(undefined8 *)(param_1 + 0x68);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uVar19 = 0x28;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e2f2bcb;
    }
  }
  pcStack_88 = *(code **)(param_1 + 0x60);
  uStack_80 = *(undefined8 *)(param_1 + 0x68);
  plVar12 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar13 = DAT_23ed6a4f8;
  uVar19 = 0xd;
joined_r0x00023e2f2bcb:
  DAT_23ed6a4f8 = plVar13;
  aplStack_78[0] = plVar12;
  if (plVar12 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar15 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar19;
    lVar15 = *(longlong *)(lVar15 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(lVar15 + 0x2e8);
    lVar17 = plVar13[-1];
    puVar6 = *(undefined8 **)(lVar15 + 8);
    *puVar6 = plVar13 + -2;
    plVar13[-2] = lVar15;
    plVar13[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar15 + 8) = plVar13 + -2;
    plVar12 = plVar13;
    if ((aplStack_78[0] != (longlong *)0x0) &&
       (*aplStack_78[0] = *aplStack_78[0] + -1, *aplStack_78[0] == 0)) {
      (**(code **)(aplStack_78[0][1] + 0x30))(aplStack_78[0]);
    }
  }
  else if ((longlong *)plVar12[3] != plVar7) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar13[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar15 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar19;
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
    lVar17 = plVar13[-1];
    puVar6 = *(undefined8 **)(lVar15 + 8);
    *puVar6 = plVar13 + -2;
    plVar13[-2] = lVar15;
    plVar13[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar15 + 8) = plVar13 + -2;
    plVar13[2] = (longlong)plVar12;
    *plVar12 = *plVar12 + 1;
    plVar12 = plVar13;
    if ((aplStack_78[0] != (longlong *)0x0) &&
       (*aplStack_78[0] = *aplStack_78[0] + -1, *aplStack_78[0] == 0)) {
      (**(code **)(aplStack_78[0][1] + 0x30))();
    }
  }
  aplStack_78[0] = plVar12;
  FUN_23e8bba40(plVar7,"ooooc",plVar2,plVar3,plVar4,plVar5,*(undefined8 *)(param_2 + 0xd8));
  if (DAT_23eeb0080 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    DAT_23eeb0080 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar15 + 0x28);
  plVar7 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar12[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  plVar12[0xf] = 0;
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  FUN_23a33aa70(param_1,pcStack_88,uStack_80,aplStack_78[0]);
  return (code *)0x0;
}
