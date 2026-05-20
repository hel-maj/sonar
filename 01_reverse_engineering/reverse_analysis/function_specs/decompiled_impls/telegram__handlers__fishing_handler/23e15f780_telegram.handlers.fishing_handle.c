/* ===== 23e15f780 telegram.handlers.fishing_handle:55 ===== */
/* ghidra_name=FUN_23e15f780 entry=23e15f780 size=18026 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e15f780(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  char cVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 uVar12;
  code *pcVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined8 *puVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong lVar20;
  int iVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  longlong lVar24;
  undefined8 uVar25;
  longlong *plStack_118;
  longlong *plStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
  code *pcStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong *plStack_c8;
  longlong *plStack_c0;
  longlong *plStack_b8;
  longlong *plStack_98;
  code *pcStack_90;
  undefined1 auStack_88 [16];
  longlong *plStack_78;
  
  plVar6 = _DAT_23eeab170;
  plVar1 = (longlong *)*param_3;
  plStack_78 = (longlong *)0x0;
  auStack_88 = (undefined1  [16])0x0;
  if (_DAT_23eeab170 == (longlong *)0x0) {
LAB_23e15f7ed:
    _DAT_23eeab170 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeab168,DAT_23eeab180,0x80);
  }
  else {
    lVar5 = *_DAT_23eeab170;
    if (1 < lVar5) {
      *_DAT_23eeab170 = lVar5 + -1;
      goto LAB_23e15f7ed;
    }
    if (_DAT_23eeab170[2] != 0) {
      *_DAT_23eeab170 = lVar5 + -1;
      if (lVar5 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e15f7ed;
    }
  }
  plVar2 = _DAT_23eeab170;
  lVar5 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eeab170 + 9;
  lVar20 = *(longlong *)(lVar5 + 8);
  _DAT_23eeab170[0xf] = lVar20;
  *(longlong **)(lVar5 + 8) = plVar6;
  if ((lVar20 != 0) &&
     (((*(char *)(lVar20 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar20 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar20 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar20 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar20 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar5 = FUN_23e9013c0();
  if (lVar5 == 0) {
    FUN_23e915740(param_1,auStack_88,DAT_23eea9210);
    plVar6 = (longlong *)0x0;
LAB_23e160f39:
    pcStack_f0 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    plVar7 = (longlong *)0x0;
    uVar22 = 0x39;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
LAB_23e1607f0:
    uVar23 = uVar22;
    if (plStack_78 == (longlong *)0x0) {
LAB_23e160de0:
      plVar10 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar10[2] = 0;
      plVar10[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      *(undefined4 *)((longlong)plVar10 + 0x24) = uVar23;
      pcVar13 = _PyRuntime_exref;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
      lVar20 = plVar10[-1];
      puVar17 = *(undefined8 **)(lVar5 + 8);
      *puVar17 = plVar10 + -2;
      plVar10[-2] = lVar5;
      plVar10[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar17;
      *(longlong **)(lVar5 + 8) = plVar10 + -2;
      if ((plStack_78 != (longlong *)0x0) && (*plStack_78 = *plStack_78 + -1, *plStack_78 == 0)) {
        (**(code **)(plStack_78[1] + 0x30))(plStack_78);
      }
      goto LAB_23e1608c8;
    }
  }
  else {
    *(undefined4 *)(plVar2 + 5) = 0x39;
    plVar6 = (longlong *)FUN_23e91bfe0(param_1,lVar5,DAT_23eea9218);
    if (plVar6 == (longlong *)0x0) {
      plStack_78 = *(longlong **)(param_1 + 0x70);
      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e160f39;
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar6,DAT_23ed6ce40);
    plVar8 = DAT_23eea9340;
    lVar5 = DAT_23ed6cce8;
    if (plVar7 == (longlong *)0x0) {
      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_78 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_b8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar22 = 0x3a;
      pcStack_f0 = (code *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar7 = (longlong *)0x0;
      goto LAB_23e1607f0;
    }
    lVar20 = *(longlong *)(param_1 + 0x10);
    plVar9 = *(longlong **)(DAT_23ed6cce8 + 0x20);
    iVar21 = *(int *)(lVar20 + 0x1410);
    *plVar9 = *plVar9 + 1;
    if (iVar21 == 0) {
      pcVar13 = (code *)FUN_23a33a530(PyDict_Type_exref);
      plVar9 = *(longlong **)(lVar5 + 0x20);
    }
    else {
      iVar21 = iVar21 + -1;
      *(int *)(lVar20 + 0x1410) = iVar21;
      pcVar13 = *(code **)(lVar20 + 0x1190 + (longlong)iVar21 * 8);
      *(longlong *)pcVar13 = 1;
    }
    lVar5 = *(longlong *)(lVar5 + 0x28);
    *(longlong *)(pcVar13 + 0x10) = 0;
    *(longlong **)(pcVar13 + 0x20) = plVar9;
    *(longlong *)(pcVar13 + 0x28) = lVar5;
    *(longlong *)(pcVar13 + 0x18) = 1;
    *(undefined4 *)(plVar2 + 5) = 0x3a;
    plStack_98 = plVar8;
    pcStack_90 = pcVar13;
    plStack_118 = (longlong *)FUN_23e94ed00(param_1,plVar7,&plStack_98);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
    if (*(longlong *)pcVar13 == 0) {
      (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
    }
    if (plStack_118 == (longlong *)0x0) {
      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_78 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_b8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      uVar22 = 0x3a;
      pcStack_f0 = (code *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e1607f0;
    }
    lVar5 = *(longlong *)(DAT_23eea91e8 + 0x20);
    if (*(char *)(lVar5 + 10) != '\0') {
      iVar21 = *(int *)(lVar5 + 0xc);
      if (*(int *)(lVar5 + 0xc) == 0) {
        *(int *)(lVar5 + 0xc) = _DAT_23ec14c90;
        iVar21 = _DAT_23ec14c90;
        _DAT_23ec14c90 = _DAT_23ec14c90 + 1;
      }
      if (_DAT_23ec14c88 != iVar21) {
        _DAT_23ec14c88 = iVar21;
        _DAT_23eeab150 = FUN_23e8cbd60(lVar5,DAT_23eea9348,*(undefined8 *)(DAT_23eea9348 + 0x18));
      }
      if (-1 < _DAT_23eeab150) {
        lVar20 = lVar5 + 0x20 + (1L << (*(byte *)(lVar5 + 9) & 0x3f));
        lVar24 = *(longlong *)(lVar20 + 8 + _DAT_23eeab150 * 0x10);
        if (lVar24 != 0) goto LAB_23e15fa19;
        _DAT_23eeab150 = FUN_23e8cbd60(lVar5,DAT_23eea9348,*(undefined8 *)(DAT_23eea9348 + 0x18));
        if (-1 < _DAT_23eeab150) {
          lVar24 = *(longlong *)(lVar20 + 8 + _DAT_23eeab150 * 0x10);
          goto LAB_23e1611f8;
        }
      }
LAB_23e160739:
      plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea9348);
      lVar5 = DAT_23eea9348;
      if ((plVar8 != (longlong *)0x0) && (lVar24 = *plVar8, lVar24 != 0)) goto LAB_23e15fa19;
LAB_23e16076f:
      plVar11 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      FUN_23e915740(param_1,auStack_88,lVar5);
      plVar8 = (longlong *)0x0;
      uVar22 = 0x3d;
      plVar7 = (longlong *)0x0;
      pcStack_f0 = (code *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      goto LAB_23e1607f0;
    }
    plVar8 = (longlong *)FUN_23a37a020(DAT_23eea91e8,DAT_23eea9348);
    if (plVar8 == (longlong *)0x0) goto LAB_23e160739;
    lVar24 = *plVar8;
LAB_23e1611f8:
    if (lVar24 == 0) goto LAB_23e160739;
LAB_23e15fa19:
    lVar5 = *(longlong *)(DAT_23eea91e8 + 0x20);
    if (*(char *)(lVar5 + 10) == '\0') {
      plVar8 = (longlong *)FUN_23a37a020(DAT_23eea91e8,DAT_23ed6cd80);
      if (plVar8 == (longlong *)0x0) goto LAB_23e160cb9;
      lVar5 = *plVar8;
LAB_23e161288:
      if (lVar5 == 0) goto LAB_23e160cb9;
    }
    else {
      iVar21 = *(int *)(lVar5 + 0xc);
      if (*(int *)(lVar5 + 0xc) == 0) {
        *(int *)(lVar5 + 0xc) = _DAT_23ec14c90;
        iVar21 = _DAT_23ec14c90;
        _DAT_23ec14c90 = _DAT_23ec14c90 + 1;
      }
      if (_DAT_23ec14c8c != iVar21) {
        _DAT_23ec14c8c = iVar21;
        _DAT_23eeab158 = FUN_23e8cbd60(lVar5,DAT_23ed6cd80,*(undefined8 *)(DAT_23ed6cd80 + 0x18));
      }
      if (-1 < _DAT_23eeab158) {
        lVar20 = lVar5 + 0x20 + (1L << (*(byte *)(lVar5 + 9) & 0x3f));
        if (*(longlong *)(lVar20 + 8 + _DAT_23eeab158 * 0x10) != 0) goto LAB_23e15fa86;
        _DAT_23eeab158 = FUN_23e8cbd60(lVar5,DAT_23ed6cd80,*(undefined8 *)(DAT_23ed6cd80 + 0x18));
        if (-1 < _DAT_23eeab158) {
          lVar5 = *(longlong *)(lVar20 + 8 + _DAT_23eeab158 * 0x10);
          goto LAB_23e161288;
        }
      }
LAB_23e160cb9:
      plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cd80);
      lVar5 = DAT_23ed6cd80;
      if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) goto LAB_23e16076f;
    }
LAB_23e15fa86:
    *(undefined4 *)(plVar2 + 5) = 0x3d;
    plVar8 = (longlong *)FUN_23e914090(param_1,lVar24);
    plVar7 = (longlong *)0x0;
    if (plVar8 != (longlong *)0x0) {
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6cfb0);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar7 == (longlong *)0x0) {
LAB_23e160fb0:
        plVar8 = (longlong *)0x0;
        auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_78 = *(longlong **)(param_1 + 0x70);
        plVar11 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_b8 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        uVar22 = 0x3d;
        pcStack_f0 = (code *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e1607f0;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6cfb0);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      plVar7 = (longlong *)0x0;
      if (plVar8 != (longlong *)0x0) {
        plVar7 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6cfb0);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar7 == (longlong *)0x0) goto LAB_23e160fb0;
        plVar8 = (longlong *)FUN_23e8c6f80(plVar7,_DAT_23eea9350);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        plVar7 = (longlong *)0x0;
        if (plVar8 != (longlong *)0x0) {
          plVar9 = (longlong *)FUN_23e8c6f80(plVar8,_DAT_23eea9358);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (plVar9 == (longlong *)0x0) goto LAB_23e160fb0;
          plVar7 = (longlong *)FUN_23e8c6f80(plVar9,_DAT_23eea9360);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar7 != (longlong *)0x0) {
            lVar5 = *(longlong *)(param_1 + 0x10);
            if (*(int *)(lVar5 + 0x1188) == 0) {
              plVar8 = (longlong *)FUN_23a33a530(PyList_Type_exref);
            }
            else {
              iVar21 = *(int *)(lVar5 + 0x1188) + -1;
              *(int *)(lVar5 + 0x1188) = iVar21;
              plVar8 = *(longlong **)(lVar5 + 0xf08 + (longlong)iVar21 * 8);
              *plVar8 = 1;
            }
            pcVar13 = _PyRuntime_exref;
            plVar8[2] = 0;
            plVar8[4] = 0;
            lVar5 = *(longlong *)(pcVar13 + 0x1f8);
            plVar8[3] = 0;
            lVar5 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x2e8);
            lVar20 = plVar8[-1];
            puVar17 = *(undefined8 **)(lVar5 + 8);
            *puVar17 = plVar8 + -2;
            uVar12 = DAT_23ed6cee0;
            plVar8[-2] = lVar5;
            plVar8[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar17;
            *(longlong **)(lVar5 + 8) = plVar8 + -2;
            *(undefined4 *)(plVar2 + 5) = 0x40;
            plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar7,uVar12);
            if (plVar10 == (longlong *)0x0) {
              auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_78 = *(longlong **)(param_1 + 0x70);
              plVar11 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_b8 = (longlong *)0x0;
              uVar22 = 0x40;
              pcStack_f0 = (code *)0x0;
              plStack_f8 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              plStack_e8 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_108 = (longlong *)0x0;
            }
            else {
              iVar21 = FUN_23a35f020(plVar10);
              lVar5 = *plVar10 + -1;
              if (iVar21 == -1) {
                auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_78 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar10 = lVar5;
                if (lVar5 == 0) {
                  plVar11 = (longlong *)0x0;
                  plStack_b8 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  (**(code **)(plVar10[1] + 0x30))();
                  pcStack_f0 = (code *)0x0;
                  plStack_f8 = (longlong *)0x0;
                  uVar22 = 0x40;
                  plStack_d8 = (longlong *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  plStack_100 = (longlong *)0x0;
                  plStack_e8 = (longlong *)0x0;
                  plStack_108 = (longlong *)0x0;
                }
                else {
                  pcStack_f0 = (code *)0x0;
                  plVar11 = (longlong *)0x0;
                  plStack_b8 = (longlong *)0x0;
                  uVar22 = 0x40;
                  plStack_f8 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  plStack_d8 = (longlong *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  plStack_100 = (longlong *)0x0;
                  plStack_e8 = (longlong *)0x0;
                  plStack_108 = (longlong *)0x0;
                }
              }
              else {
                *plVar10 = lVar5;
                if (lVar5 == 0) {
                  (**(code **)(plVar10[1] + 0x30))();
                }
                if (iVar21 == 0) {
                  plStack_e8 = (longlong *)0x0;
                  plStack_b8 = (longlong *)0x0;
                  plStack_108 = (longlong *)0x0;
LAB_23e15fd25:
                  plVar9 = (longlong *)FUN_23e8bd600(param_1,plVar8);
                  if (plVar9 == (longlong *)0x0) {
                    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_78 = *(longlong **)(param_1 + 0x70);
                    plVar11 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar22 = 0x49;
                    pcStack_f0 = (code *)0x0;
                    plStack_f8 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_100 = (longlong *)0x0;
                  }
                  else {
                    plVar11 = (longlong *)FUN_23e8c0100(plVar9,8);
                    lVar5 = *plVar9;
                    *plVar9 = lVar5 + -1;
                    if (lVar5 + -1 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    plVar9 = (longlong *)FUN_23e8c6340(plVar11,1);
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    plStack_100 = (longlong *)FUN_23e8c1ee0(plVar9,_DAT_23eea9398);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    if (plStack_100 == (longlong *)0x0) {
                      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_78 = *(longlong **)(param_1 + 0x70);
                      plVar11 = (longlong *)0x0;
                      plVar9 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar22 = 0x48;
                      pcStack_f0 = (code *)0x0;
                      plStack_f8 = (longlong *)0x0;
                      plStack_d8 = (longlong *)0x0;
                      plStack_e0 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
                      if ((code *)plVar1[1] == PyLong_Type_exref) {
                        plStack_e0 = (longlong *)
                                     (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0x10))
                                               (plVar1,_DAT_23eea9398);
                      }
                      else {
                        plStack_e0 = (longlong *)FUN_23e8c3200(plVar1);
                      }
                      if (plStack_e0 == (longlong *)0x0) {
                        auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                        plStack_78 = *(longlong **)(param_1 + 0x70);
                        uVar22 = 0x48;
                        plVar11 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plVar9 = (longlong *)0x0;
                        pcStack_f0 = (code *)0x0;
                        plStack_f8 = (longlong *)0x0;
                        plStack_d8 = (longlong *)0x0;
                        plStack_e0 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        uVar12 = FUN_23a3a0d40(_DAT_23eea93a0);
                        plVar10 = (longlong *)FUN_23e8bf9b0(plStack_e0,_DAT_23eea9398);
                        if (plVar10 == (longlong *)0x0) {
                          auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                          plStack_78 = *(longlong **)(param_1 + 0x70);
                          plVar11 = (longlong *)0x0;
                          uVar22 = 0x48;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          pcStack_f0 = (code *)0x0;
                          plStack_f8 = (longlong *)0x0;
                          plStack_d8 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar9 = (longlong *)0x0;
                        }
                        else {
                          pcVar13 = (code *)FUN_23e8bd600(param_1,plVar8);
                          if (pcVar13 == (code *)0x0) {
                            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_78 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar10 = *plVar10 + -1;
                            plStack_f8 = (longlong *)0x0;
                            if (*plVar10 == 0) {
                              plVar11 = (longlong *)0x0;
                              plVar9 = (longlong *)0x0;
                              (**(code **)(plVar10[1] + 0x30))(plVar10);
                              pcStack_f0 = (code *)0x0;
                              plStack_d8 = (longlong *)0x0;
                              uVar22 = 0x4b;
                            }
                            else {
                              plVar11 = (longlong *)0x0;
                              plVar9 = (longlong *)0x0;
                              uVar22 = 0x4b;
                              pcStack_f0 = (code *)0x0;
                              plStack_d8 = (longlong *)0x0;
                            }
                          }
                          else {
                            *(undefined4 *)(plVar2 + 5) = 0x4b;
                            plStack_98 = plVar10;
                            pcStack_90 = pcVar13;
                            plStack_d8 = (longlong *)FUN_23e94ed00(param_1,uVar12,&plStack_98);
                            *plVar10 = *plVar10 + -1;
                            if (*plVar10 == 0) {
                              (**(code **)(plVar10[1] + 0x30))(plVar10);
                            }
                            lVar5 = *(longlong *)pcVar13;
                            *(longlong *)pcVar13 = lVar5 + -1;
                            if (lVar5 + -1 == 0) {
                              (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                            }
                            if (plStack_d8 == (longlong *)0x0) {
                              auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                              plStack_78 = *(longlong **)(param_1 + 0x70);
                              plVar11 = (longlong *)0x0;
                              plVar9 = (longlong *)0x0;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar22 = 0x4b;
                              pcStack_f0 = (code *)0x0;
                              plStack_f8 = (longlong *)0x0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            }
                            else {
                              lVar5 = FUN_23e901140();
                              if (lVar5 == 0) {
                                plVar11 = (longlong *)0x0;
                                plVar9 = (longlong *)0x0;
                                FUN_23e915740(param_1,auStack_88,DAT_23eea92b0);
                                uVar22 = 0x4d;
                                pcStack_f0 = (code *)0x0;
                                plStack_f8 = (longlong *)0x0;
                              }
                              else {
                                *(undefined4 *)(plVar2 + 5) = 0x4d;
                                plStack_f8 = (longlong *)FUN_23e91a870(param_1,lVar5);
                                if (plStack_f8 == (longlong *)0x0) {
                                  auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  plStack_78 = *(longlong **)(param_1 + 0x70);
                                  plVar11 = (longlong *)0x0;
                                  plVar9 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar22 = 0x4d;
                                  pcStack_f0 = (code *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                }
                                else {
                                  plVar9 = (longlong *)
                                           FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plStack_e0,
                                                         plStack_d8);
                                  plVar11 = (longlong *)FUN_23a38cc10(param_1,plVar8,plVar9);
                                  *plVar9 = *plVar9 + -1;
                                  if (*plVar9 == 0) {
                                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                                  }
                                  if (plVar11 == (longlong *)0x0) {
                                    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    plStack_78 = *(longlong **)(param_1 + 0x70);
                                    plVar11 = (longlong *)0x0;
                                    uVar22 = 0x4f;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    pcStack_f0 = (code *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plVar9 = (longlong *)0x0;
                                  }
                                  else {
                                    plVar10 = (longlong *)FUN_23ebf7180(plVar11);
                                    *plVar11 = *plVar11 + -1;
                                    if (*plVar11 == 0) {
                                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                                    }
                                    plVar11 = (longlong *)0x0;
                                    plVar9 = (longlong *)0x0;
                                    plStack_c8 = (longlong *)0x0;
                                    if (plVar10 == (longlong *)0x0) {
                                      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                      plStack_78 = *(longlong **)(param_1 + 0x70);
                                      uVar22 = 0x4f;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      pcStack_f0 = (code *)0x0;
                                    }
                                    else {
                                      do {
                                        pcVar13 = *(code **)(plVar10[1] + 0xe0);
                                        if (pcVar13 == (code *)0x0) {
                                          PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                                                       "\'%s\' object is not an iterator",
                                                       *(undefined8 *)(plVar10[1] + 0x18));
LAB_23e162358:
                                          cVar4 = FUN_23a3591a0(param_1,*(undefined8 *)
                                                                         PyExc_StopIteration_exref);
                                          if (cVar4 == '\0') {
                                            plVar14 = *(longlong **)(param_1 + 0x70);
                                            uVar12 = *(undefined8 *)(param_1 + 0x60);
                                            uVar25 = *(undefined8 *)(param_1 + 0x68);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            plStack_78 = (longlong *)0x0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            auStack_88 = (undefined1  [16])0x0;
                                            if (plStack_c8 != (longlong *)0x0) {
                                              uVar22 = 0x4f;
                                              goto LAB_23e161e80;
                                            }
                                            uVar22 = 0x4f;
                                            goto LAB_23e161ec1;
                                          }
                                          if ((plStack_c8 != (longlong *)0x0) &&
                                             (*plStack_c8 = *plStack_c8 + -1, *plStack_c8 == 0)) {
                                            FUN_23a334bc0(plStack_c8);
                                          }
                                          lVar5 = *plVar10;
                                          *plVar10 = lVar5 + -1;
                                          if (lVar5 + -1 == 0) {
                                            FUN_23a334bc0(plVar10);
                                          }
                                          lVar5 = _DAT_23eea93d8;
                                          *(undefined4 *)(plVar2 + 5) = 0x57;
                                          plVar10 = (longlong *)
                                                    FUN_23e915840(param_1,plStack_f8,DAT_23eea9320,
                                                                  *(undefined8 *)(lVar5 + 0x18));
                                          if (plVar10 == (longlong *)0x0) {
                                            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                            plStack_78 = *(longlong **)(param_1 + 0x70);
                                            uVar22 = 0x57;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            pcStack_f0 = (code *)0x0;
                                            goto LAB_23e1607f0;
                                          }
                                          lVar5 = *plVar10;
                                          *plVar10 = lVar5 + -1;
                                          if (lVar5 + -1 == 0) {
                                            FUN_23a334bc0(plVar10);
                                          }
                                          pcStack_f0 = (code *)FUN_23e8d6340(*(undefined8 *)
                                                                              (param_1 + 0x10),0);
                                          iVar21 = FUN_23e97de20(plVar1,DAT_23ed6ccf0);
                                          if (iVar21 == -1) {
                                            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                            plStack_78 = *(longlong **)(param_1 + 0x70);
                                            uVar22 = 0x5b;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            goto LAB_23e1607f0;
                                          }
                                          if (iVar21 == 1) {
                                            lVar5 = FUN_23e900ff0();
                                            plVar14 = _DAT_23eea93f0;
                                            plVar10 = _DAT_23eea93e8;
                                            if (lVar5 == 0) {
                                              FUN_23e915740(param_1,auStack_88,DAT_23eea93e0);
                                              uVar22 = 0x5c;
                                              goto LAB_23e1607f0;
                                            }
                                            plVar15 = (longlong *)
                                                      FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),
                                                                    2);
                                            *plVar14 = *plVar14 + 1;
                                            plVar15[3] = (longlong)plVar14;
                                            plVar14 = (longlong *)
                                                      FUN_23e8c5d90(plVar1,DAT_23ed6ccf8);
                                            if (plVar14 != (longlong *)0x0) {
                                              lVar20 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                                              *plVar14 = *plVar14 + -1;
                                              if (*plVar14 == 0) {
                                                FUN_23a334bc0(plVar14);
                                              }
                                              if (lVar20 != 0) {
                                                plVar15[4] = lVar20;
                                                pcVar13 = (code *)PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar15);
                                                *plVar15 = *plVar15 + -1;
                                                if (*plVar15 == 0) {
                                                  FUN_23a334bc0(plVar15);
                                                }
                                                if (pcVar13 != (code *)0x0) {
                                                  *(undefined4 *)(plVar2 + 5) = 0x5c;
                                                  plStack_98 = plVar10;
                                                  pcStack_90 = pcVar13;
                                                  lVar5 = FUN_23e9186b0(param_1,lVar5,&plStack_98,
                                                                        DAT_23eea92c8);
                                                  *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                                                  if (*(longlong *)pcVar13 == 0) {
                                                    FUN_23a334bc0(pcVar13);
                                                  }
                                                  if (lVar5 != 0) {
                                                    FUN_23e8ba4b0(pcStack_f0);
                                                    goto LAB_23e1624a5;
                                                  }
                                                }
                                                auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                plStack_78 = *(longlong **)(param_1 + 0x70);
                                                uVar22 = 0x5c;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                goto LAB_23e1607f0;
                                              }
                                            }
                                            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                            plStack_78 = *(longlong **)(param_1 + 0x70);
                                            uVar22 = 0x5c;
                                            uVar23 = 0x5c;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *plVar15 = *plVar15 + -1;
                                            lVar5 = *plVar15;
                                          }
                                          else {
LAB_23e1624a5:
                                            plVar10 = (longlong *)FUN_23e8c6340(plStack_100,1);
                                            iVar21 = FUN_23e97c2c0(plVar1,plVar10);
                                            *plVar10 = *plVar10 + -1;
                                            if (*plVar10 == 0) {
                                              FUN_23a334bc0(plVar10);
                                            }
                                            if (iVar21 == -1) {
                                              auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                              plStack_78 = *(longlong **)(param_1 + 0x70);
                                              uVar22 = 0x5d;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              goto LAB_23e1607f0;
                                            }
                                            if (iVar21 != 1) {
LAB_23e162525:
                                              iVar21 = FUN_23a35f020(pcStack_f0);
                                              if (iVar21 == 1) {
                                                plVar10 = (longlong *)
                                                          FUN_23e8bc2f0(plStack_f8,_DAT_23eea9400);
                                                if (plVar10 != (longlong *)0x0) {
                                                  *(longlong *)pcStack_f0 =
                                                       *(longlong *)pcStack_f0 + 1;
                                                  plStack_98 = plVar10;
                                                  pcStack_90 = pcStack_f0;
                                                  plVar10 = (longlong *)
                                                            FUN_23ab01810(param_1,&plStack_98);
                                                  if (plVar10 != (longlong *)0x0) {
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0(plVar10);
                                                    }
                                                    goto LAB_23e16254b;
                                                  }
                                                }
                                                auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                plStack_78 = *(longlong **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                uVar22 = 0x61;
                                                goto LAB_23e1607f0;
                                              }
LAB_23e16254b:
                                              plVar10 = (longlong *)FUN_23e8bc2f0(plStack_f8);
                                              if (plVar10 != (longlong *)0x0) {
                                                lVar20 = FUN_23e900ff0();
                                                lVar5 = _DAT_23eea9408;
                                                if (lVar20 == 0) {
                                                  FUN_23e915740(param_1,auStack_88,DAT_23eea93e0);
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                    uVar22 = 99;
                                                  }
                                                  else {
                                                    uVar22 = 99;
                                                  }
                                                  goto LAB_23e1607f0;
                                                }
                                                *(undefined4 *)(plVar2 + 5) = 99;
                                                plVar14 = (longlong *)
                                                          FUN_23e9186b0(param_1,lVar20,lVar5 + 0x18,
                                                                        DAT_23eea92c8);
                                                if (plVar14 == (longlong *)0x0) {
                                                  auStack_88 = *(undefined1 (*) [16])
                                                                (param_1 + 0x60);
                                                  plStack_78 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar10 = *plVar10 + -1;
                                                  uVar22 = 99;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                    uVar22 = 99;
                                                  }
                                                  goto LAB_23e1607f0;
                                                }
                                                *(undefined4 *)(plVar2 + 5) = 99;
                                                plVar15 = (longlong *)
                                                          FUN_23e914090(param_1,plVar10,plVar14);
                                                *plVar10 = *plVar10 + -1;
                                                if (*plVar10 == 0) {
                                                  FUN_23a334bc0(plVar10);
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
                                                  *(undefined4 *)(plVar2 + 5) = 0x65;
                                                  lVar5 = FUN_23e91bfe0(param_1,plStack_f8,
                                                                        DAT_23eea9330);
                                                  if (lVar5 != 0) {
                                                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                                    *plVar6 = *plVar6 + -1;
                                                    if (*plVar6 == 0) {
                                                      FUN_23a334bc0(plVar6);
                                                    }
                                                    lVar20 = *plStack_118;
                                                    *plStack_118 = lVar20 + -1;
                                                    if (lVar20 + -1 == 0) {
                                                      FUN_23a334bc0(plStack_118);
                                                    }
                                                    *plVar7 = *plVar7 + -1;
                                                    if (*plVar7 == 0) {
                                                      FUN_23a334bc0(plVar7);
                                                    }
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    if ((plStack_108 != (longlong *)0x0) &&
                                                       (lVar20 = *plStack_108,
                                                       *plStack_108 = lVar20 + -1, lVar20 + -1 == 0)
                                                       ) {
                                                      FUN_23a334bc0(plStack_108);
                                                    }
                                                    if ((plStack_b8 != (longlong *)0x0) &&
                                                       (*plStack_b8 = *plStack_b8 + -1,
                                                       *plStack_b8 == 0)) {
                                                      FUN_23a334bc0(plStack_b8);
                                                    }
                                                    if ((plStack_e8 != (longlong *)0x0) &&
                                                       (lVar20 = *plStack_e8,
                                                       *plStack_e8 = lVar20 + -1, lVar20 + -1 == 0))
                                                    {
                                                      FUN_23a334bc0(plStack_e8);
                                                    }
                                                    lVar20 = *plStack_100;
                                                    *plStack_100 = lVar20 + -1;
                                                    if (lVar20 + -1 == 0) {
                                                      FUN_23a334bc0(plStack_100);
                                                    }
                                                    lVar20 = *plStack_e0;
                                                    *plStack_e0 = lVar20 + -1;
                                                    if (lVar20 + -1 == 0) {
                                                      FUN_23a334bc0(plStack_e0);
                                                    }
                                                    lVar20 = *plStack_d8;
                                                    *plStack_d8 = lVar20 + -1;
                                                    if (lVar20 + -1 == 0) {
                                                      FUN_23a334bc0(plStack_d8);
                                                    }
                                                    lVar20 = *plStack_f8;
                                                    *plStack_f8 = lVar20 + -1;
                                                    if (lVar20 + -1 == 0) {
                                                      FUN_23a334bc0(plStack_f8);
                                                    }
                                                    if ((plVar9 != (longlong *)0x0) &&
                                                       (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                                      FUN_23a334bc0(plVar9);
                                                    }
                                                    if ((plVar11 != (longlong *)0x0) &&
                                                       (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                    lVar20 = *(longlong *)pcStack_f0;
                                                    *(longlong *)pcStack_f0 = lVar20 + -1;
                                                    if (lVar20 + -1 == 0) {
                                                      FUN_23a334bc0(pcStack_f0);
                                                    }
                                                    lVar20 = *plVar1;
                                                    *plVar1 = lVar20 + -1;
                                                    if (lVar20 + -1 != 0) {
                                                      return lVar5;
                                                    }
                                                    FUN_23a334bc0(plVar1);
                                                    return lVar5;
                                                  }
                                                  auStack_88 = *(undefined1 (*) [16])
                                                                (param_1 + 0x60);
                                                  plStack_78 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  uVar22 = 0x65;
                                                  goto LAB_23e1607f0;
                                                }
                                              }
                                              auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                              plStack_78 = *(longlong **)(param_1 + 0x70);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              uVar22 = 99;
                                              goto LAB_23e1607f0;
                                            }
                                            lVar5 = FUN_23e900ff0();
                                            plVar14 = _DAT_23eea93f8;
                                            plVar10 = _DAT_23eea93f0;
                                            if (lVar5 == 0) {
                                              FUN_23e915740(param_1,auStack_88,DAT_23eea93e0);
                                              uVar22 = 0x5e;
                                              goto LAB_23e1607f0;
                                            }
                                            plVar15 = (longlong *)
                                                      FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),
                                                                    2);
                                            *plVar10 = *plVar10 + 1;
                                            plVar15[3] = (longlong)plVar10;
                                            plVar10 = (longlong *)
                                                      FUN_23e8bf9b0(plVar1,DAT_23ed6ccf8);
                                            if (plVar10 != (longlong *)0x0) {
                                              lVar20 = FUN_23e94f9d0(param_1,plVar10,DAT_23ed6cd28);
                                              *plVar10 = *plVar10 + -1;
                                              if (*plVar10 == 0) {
                                                FUN_23a334bc0(plVar10);
                                              }
                                              if (lVar20 != 0) {
                                                plVar15[4] = lVar20;
                                                pcVar13 = (code *)PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar15);
                                                *plVar15 = *plVar15 + -1;
                                                if (*plVar15 == 0) {
                                                  FUN_23a334bc0(plVar15);
                                                }
                                                if (pcVar13 != (code *)0x0) {
                                                  *(undefined4 *)(plVar2 + 5) = 0x5e;
                                                  plStack_98 = plVar14;
                                                  pcStack_90 = pcVar13;
                                                  lVar5 = FUN_23e9186b0(param_1,lVar5);
                                                  *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                                                  if (*(longlong *)pcVar13 == 0) {
                                                    FUN_23a334bc0(pcVar13);
                                                  }
                                                  if (lVar5 != 0) {
                                                    FUN_23e8ba4b0(pcStack_f0);
                                                    goto LAB_23e162525;
                                                  }
                                                }
                                                auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                plStack_78 = *(longlong **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                uVar22 = 0x5e;
                                                goto LAB_23e1607f0;
                                              }
                                            }
                                            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                            plStack_78 = *(longlong **)(param_1 + 0x70);
                                            uVar22 = 0x5e;
                                            uVar23 = 0x5e;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *plVar15 = *plVar15 + -1;
                                            lVar5 = *plVar15;
                                          }
                                          if (lVar5 == 0) {
                                            FUN_23a334bc0(plVar15);
                                            uVar22 = uVar23;
                                          }
                                          goto LAB_23e1607f0;
                                        }
                                        plVar14 = (longlong *)(*pcVar13)(plVar10);
                                        if (plVar14 == (longlong *)0x0) goto LAB_23e162358;
                                        if ((plStack_c8 != (longlong *)0x0) &&
                                           (*plStack_c8 = *plStack_c8 + -1, *plStack_c8 == 0)) {
                                          (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
                                        }
                                        plVar15 = (longlong *)FUN_23a388310(plVar14);
                                        plStack_c8 = plVar14;
                                        if (plVar15 == (longlong *)0x0) {
                                          uVar12 = *(undefined8 *)(param_1 + 0x60);
                                          uVar25 = *(undefined8 *)(param_1 + 0x68);
                                          plVar14 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
LAB_23e162b73:
                                          uVar22 = 0x4f;
                                          goto LAB_23e161e80;
                                        }
                                        plStack_d0 = (longlong *)
                                                     (**(code **)(plVar15[1] + 0xe0))(plVar15);
                                        if ((plStack_d0 == (longlong *)0x0) &&
                                           (plStack_d0 = (longlong *)
                                                         FUN_23a3c1b70(param_1,auStack_88,0,2),
                                           plStack_d0 == (longlong *)0x0)) {
                                          plStack_c0 = (longlong *)0x0;
                                          lVar5 = *plVar15;
LAB_23e162a99:
                                          plVar14 = plStack_78;
                                          uVar12 = auStack_88._0_8_;
                                          uVar25 = auStack_88._8_8_;
                                          auStack_88 = (undefined1  [16])0x0;
                                          plStack_78 = (longlong *)0x0;
                                          *plVar15 = lVar5 + -1;
                                          if (lVar5 + -1 == 0) {
                                            (**(code **)(plVar15[1] + 0x30))(plVar15);
                                          }
                                          plStack_78 = (longlong *)0x0;
                                          auStack_88 = (undefined1  [16])0x0;
                                          if ((plStack_d0 != (longlong *)0x0) &&
                                             (lVar5 = *plStack_d0, *plStack_d0 = lVar5 + -1,
                                             lVar5 + -1 == 0)) {
                                            (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
                                          }
                                          if ((plStack_c0 != (longlong *)0x0) &&
                                             (lVar5 = *plStack_c0, *plStack_c0 = lVar5 + -1,
                                             lVar5 + -1 == 0)) {
                                            (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
                                          }
                                          goto LAB_23e162b73;
                                        }
                                        plStack_c0 = (longlong *)
                                                     (**(code **)(plVar15[1] + 0xe0))(plVar15);
                                        if ((plStack_c0 == (longlong *)0x0) &&
                                           (plStack_c0 = (longlong *)
                                                         FUN_23a3c1b70(param_1,auStack_88,1,2),
                                           plStack_c0 == (longlong *)0x0)) {
                                          lVar5 = *plVar15;
                                          goto LAB_23e162a99;
                                        }
                                        cVar4 = FUN_23a3884a0(param_1,auStack_88,plVar15);
                                        lVar5 = *plVar15;
                                        if (cVar4 == '\0') goto LAB_23e162a99;
                                        *plVar15 = lVar5 + -1;
                                        if (lVar5 + -1 == 0) {
                                          (**(code **)(plVar15[1] + 0x30))(plVar15);
                                        }
                                        lVar5 = *plStack_d0;
                                        *plStack_d0 = lVar5 + 1;
                                        if (plStack_b8 != (longlong *)0x0) {
                                          lVar5 = *plStack_b8;
                                          *plStack_b8 = lVar5 + -1;
                                          if (lVar5 + -1 == 0) {
                                            (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
                                          }
                                          lVar5 = *plStack_d0 + -1;
                                        }
                                        *plStack_d0 = lVar5;
                                        if (lVar5 == 0) {
                                          (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
                                        }
                                        lVar5 = *plStack_c0;
                                        *plStack_c0 = lVar5 + 1;
                                        if (plStack_e8 != (longlong *)0x0) {
                                          *plStack_e8 = *plStack_e8 + -1;
                                          if (*plStack_e8 == 0) {
                                            (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
                                          }
                                          lVar5 = *plStack_c0 + -1;
                                        }
                                        *plStack_c0 = lVar5;
                                        if (lVar5 == 0) {
                                          (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
                                        }
                                        plVar14 = (longlong *)
                                                  FUN_23e8bc2f0(plStack_118,DAT_23ed6ce40);
                                        plStack_b8 = plStack_d0;
                                        plStack_e8 = plStack_c0;
                                        if (plVar14 == (longlong *)0x0) {
                                          plVar14 = *(longlong **)(param_1 + 0x70);
                                          uVar12 = *(undefined8 *)(param_1 + 0x60);
                                          uVar25 = *(undefined8 *)(param_1 + 0x68);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uVar22 = 0x50;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e161e80;
                                        }
                                        *(undefined4 *)(plVar2 + 5) = 0x50;
                                        pcStack_90 = _Py_TrueStruct_exref;
                                        plStack_98 = plStack_d0;
                                        plVar15 = (longlong *)FUN_23e94ed00(param_1,plVar14);
                                        *plVar14 = *plVar14 + -1;
                                        if (*plVar14 == 0) {
                                          (**(code **)(plVar14[1] + 0x30))(plVar14);
                                        }
                                        if (plVar15 == (longlong *)0x0) {
                                          uVar12 = *(undefined8 *)(param_1 + 0x60);
                                          uVar25 = *(undefined8 *)(param_1 + 0x68);
                                          uVar22 = 0x50;
                                          plVar14 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e161e80;
                                        }
                                        if ((plVar9 != (longlong *)0x0) &&
                                           (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                                        }
                                        iVar21 = FUN_23a35f020();
                                        plVar9 = plVar15;
                                        if (iVar21 == -1) {
                                          uVar12 = *(undefined8 *)(param_1 + 0x60);
                                          uVar25 = *(undefined8 *)(param_1 + 0x68);
                                          plVar14 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uVar22 = 0x51;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e161e80;
                                        }
                                        plVar15 = _DAT_23eea93a8;
                                        if (iVar21 == 0) {
                                          plVar15 = _DAT_23eea93b0;
                                        }
                                        *plVar15 = *plVar15 + 1;
                                        if ((plVar11 != (longlong *)0x0) &&
                                           (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                                        }
                                        plVar14 = (longlong *)
                                                  FUN_23e8bc2f0(plStack_f8,DAT_23eea92b8);
                                        if (plVar14 == (longlong *)0x0) {
LAB_23e162fae:
                                          uVar12 = *(undefined8 *)(param_1 + 0x60);
                                          plVar14 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uVar22 = 0x52;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plVar11 = plVar15;
                                          uVar25 = *(undefined8 *)(param_1 + 0x68);
                                          goto LAB_23e161e80;
                                        }
                                        lVar5 = *(longlong *)(param_1 + 0x10);
                                        plVar16 = *(longlong **)(lVar5 + 0xe28);
                                        if (plVar16 == (longlong *)0x0) {
                                          plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                                        }
                                        else {
                                          lVar20 = plVar16[3];
                                          *(int *)(lVar5 + 0xec0) = *(int *)(lVar5 + 0xec0) + -1;
                                          *(longlong *)(lVar5 + 0xe28) = lVar20;
                                          *plVar16 = 1;
                                        }
                                        pcVar13 = _PyRuntime_exref;
                                        plVar16[5] = 0;
                                        lVar5 = *(longlong *)
                                                 (*(longlong *)
                                                   (*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
                                        lVar20 = plVar16[-1];
                                        puVar17 = *(undefined8 **)(lVar5 + 8);
                                        *puVar17 = plVar16 + -2;
                                        plVar19 = _DAT_23eea93c0;
                                        plVar16[-2] = lVar5;
                                        plVar16[-1] = (ulonglong)((uint)lVar20 & 3) |
                                                      (ulonglong)puVar17;
                                        *(longlong **)(lVar5 + 8) = plVar16 + -2;
                                        *plVar15 = *plVar15 + 1;
                                        plVar16[3] = (longlong)plVar15;
                                        *plVar19 = *plVar19 + 1;
                                        plVar16[4] = (longlong)plVar19;
                                        pcVar13 = DAT_23ed6cd28;
                                        if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                          plVar19 = (longlong *)
                                                    PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                          if (plVar19 != (longlong *)0x0) {
                                            *plVar19 = *plVar19 + 1;
                                            DAT_23ed6a4c0 = plVar19;
                                            goto LAB_23e1603da;
                                          }
LAB_23e162e7d:
                                          PyErr_PrintEx(0);
                                          Py_Exit(1);
                                          goto LAB_23e162e90;
                                        }
LAB_23e1603da:
                                        pcStack_90 = pcVar13;
                                        plStack_98 = plStack_c0;
                                        lVar5 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                                        if (lVar5 == 0) {
                                          auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          plStack_78 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            FUN_23a334bc0(plVar14);
                                          }
                                          *plVar16 = *plVar16 + -1;
                                          if (*plVar16 == 0) {
                                            FUN_23a334bc0(plVar16);
LAB_23e163542:
                                            uVar22 = 0x53;
                                            plVar11 = plVar15;
                                            plVar14 = plStack_78;
                                            uVar12 = auStack_88._0_8_;
                                            uVar25 = auStack_88._8_8_;
                                          }
                                          else {
                                            uVar22 = 0x53;
                                            plVar11 = plVar15;
                                            plVar14 = plStack_78;
                                            uVar12 = auStack_88._0_8_;
                                            uVar25 = auStack_88._8_8_;
                                          }
                                          goto LAB_23e161e80;
                                        }
                                        plVar16[5] = lVar5;
                                        plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                                        *plVar16 = *plVar16 + -1;
                                        if (*plVar16 == 0) {
                                          (**(code **)(plVar16[1] + 0x30))(plVar16);
                                        }
                                        plVar19 = _DAT_23eea93c8;
                                        if (plVar11 == (longlong *)0x0) {
                                          auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          plStack_78 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            FUN_23a334bc0(plVar14);
                                            goto LAB_23e163542;
                                          }
                                          uVar22 = 0x53;
                                          plVar11 = plVar15;
                                          plVar14 = plStack_78;
                                          uVar12 = auStack_88._0_8_;
                                          uVar25 = auStack_88._8_8_;
                                          goto LAB_23e161e80;
                                        }
                                        lVar5 = *(longlong *)(param_1 + 0x10);
                                        plVar16 = *(longlong **)(lVar5 + 0xe30);
                                        if (plVar16 == (longlong *)0x0) {
                                          plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
                                        }
                                        else {
                                          lVar20 = plVar16[3];
                                          *(int *)(lVar5 + 0xec4) = *(int *)(lVar5 + 0xec4) + -1;
                                          *(longlong *)(lVar5 + 0xe30) = lVar20;
                                          *plVar16 = 1;
                                        }
                                        pcVar13 = _PyRuntime_exref;
                                        plVar16[6] = 0;
                                        *(undefined1 (*) [16])(plVar16 + 4) = (undefined1  [16])0x0;
                                        lVar5 = *(longlong *)
                                                 (*(longlong *)
                                                   (*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
                                        lVar20 = plVar16[-1];
                                        puVar17 = *(undefined8 **)(lVar5 + 8);
                                        *puVar17 = plVar16 + -2;
                                        plVar16[-2] = lVar5;
                                        plVar16[-1] = (ulonglong)((uint)lVar20 & 3) |
                                                      (ulonglong)puVar17;
                                        *(longlong **)(lVar5 + 8) = plVar16 + -2;
                                        plVar18 = DAT_23ed6a4c0;
                                        *plVar19 = *plVar19 + 1;
                                        plVar16[3] = (longlong)plVar19;
                                        pcVar13 = DAT_23ed6cd28;
                                        if (plVar18 == (longlong *)0x0) {
                                          plVar18 = (longlong *)
                                                    PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                          if (plVar18 == (longlong *)0x0) goto LAB_23e162e7d;
                                          *plVar18 = *plVar18 + 1;
                                          DAT_23ed6a4c0 = plVar18;
                                        }
                                        pcStack_90 = pcVar13;
                                        plStack_98 = plStack_d0;
                                        lVar5 = FUN_23e94ed00(param_1,plVar18,&plStack_98);
                                        if (lVar5 == 0) {
LAB_23e162e90:
                                          auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_78 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            FUN_23a334bc0(plVar14);
                                          }
                                          *plVar11 = *plVar11 + -1;
                                          if (*plVar11 == 0) {
                                            FUN_23a334bc0(plVar11);
                                          }
                                          *plVar16 = *plVar16 + -1;
                                          lVar5 = *plVar16;
                                          plVar11 = plVar16;
joined_r0x00023e162f35:
                                          if (lVar5 == 0) {
                                            FUN_23a334bc0(plVar11);
                                            uVar22 = 0x54;
                                            plVar11 = plVar15;
                                            plVar14 = plStack_78;
                                            uVar12 = auStack_88._0_8_;
                                            uVar25 = auStack_88._8_8_;
                                          }
                                          else {
                                            uVar22 = 0x54;
                                            plVar11 = plVar15;
                                            plVar14 = plStack_78;
                                            uVar12 = auStack_88._0_8_;
                                            uVar25 = auStack_88._8_8_;
                                          }
                                          goto LAB_23e161e80;
                                        }
                                        plVar16[4] = lVar5;
                                        plVar19 = _DAT_23eea93d0;
                                        *_DAT_23eea93d0 = *_DAT_23eea93d0 + 1;
                                        plVar16[5] = (longlong)plVar19;
                                        pcVar13 = DAT_23ed6cd28;
                                        if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                          plVar19 = (longlong *)
                                                    PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                          if (plVar19 == (longlong *)0x0) goto LAB_23e162e7d;
                                          *plVar19 = *plVar19 + 1;
                                          DAT_23ed6a4c0 = plVar19;
                                        }
                                        pcStack_90 = pcVar13;
                                        plStack_98 = plVar1;
                                        lVar5 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                                        if (lVar5 == 0) goto LAB_23e162e90;
                                        plVar16[6] = lVar5;
                                        pcVar13 = (code *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                                        *plVar16 = *plVar16 + -1;
                                        if (*plVar16 == 0) {
                                          (**(code **)(plVar16[1] + 0x30))(plVar16);
                                        }
                                        uVar12 = DAT_23eea92c8;
                                        if (pcVar13 == (code *)0x0) {
                                          auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_78 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            FUN_23a334bc0(plVar14);
                                          }
                                          *plVar11 = *plVar11 + -1;
                                          lVar5 = *plVar11;
                                          goto joined_r0x00023e162f35;
                                        }
                                        *(undefined4 *)(plVar2 + 5) = 0x52;
                                        plStack_98 = plVar11;
                                        pcStack_90 = pcVar13;
                                        plVar16 = (longlong *)
                                                  FUN_23e9186b0(param_1,plVar14,&plStack_98,uVar12);
                                        *plVar14 = *plVar14 + -1;
                                        if (*plVar14 == 0) {
                                          (**(code **)(plVar14[1] + 0x30))();
                                        }
                                        *plVar11 = *plVar11 + -1;
                                        if (*plVar11 == 0) {
                                          (**(code **)(plVar11[1] + 0x30))();
                                        }
                                        *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                                        if (*(longlong *)pcVar13 == 0) {
                                          (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
                                        }
                                        if (plVar16 == (longlong *)0x0) goto LAB_23e162fae;
                                        *plVar16 = *plVar16 + -1;
                                        if (*plVar16 == 0) {
                                          (**(code **)(plVar16[1] + 0x30))();
                                        }
                                        lVar5 = *(longlong *)(param_1 + 0x10);
                                        if ((((*(int *)(*(longlong *)(lVar5 + 0x28) + 0x160) != 0)
                                             || (*(int *)(lVar5 + 0x78) != 0)) &&
                                            (iVar21 = Py_MakePendingCalls(), iVar21 < 0)) &&
                                           (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e161e1d;
                                        if (*(int *)(lVar5 + 0x68) == 0) {
                                          plVar14 = *(longlong **)(param_1 + 0x90);
                                        }
                                        else {
                                          PyEval_SaveThread();
                                          PyEval_AcquireThread(param_1);
                                          plVar14 = *(longlong **)(param_1 + 0x90);
                                        }
                                        plVar11 = plVar15;
                                      } while (plVar14 == (longlong *)0x0);
                                      plVar11 = *(longlong **)(param_1 + 0x60);
                                      plVar16 = *(longlong **)(param_1 + 0x68);
                                      *(longlong **)(param_1 + 0x60) = plVar14;
                                      *(undefined8 *)(param_1 + 0x90) = 0;
                                      plVar19 = *(longlong **)(param_1 + 0x70);
                                      *plVar14 = *plVar14 + 1;
                                      *(undefined8 *)(param_1 + 0x68) = 0;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      if ((plVar11 != (longlong *)0x0) &&
                                         (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                                        (**(code **)(plVar11[1] + 0x30))();
                                      }
                                      if ((plVar16 != (longlong *)0x0) &&
                                         (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                        (**(code **)(plVar16[1] + 0x30))();
                                      }
                                      if ((plVar19 != (longlong *)0x0) &&
                                         (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                                        (**(code **)(plVar19[1] + 0x30))();
                                      }
LAB_23e161e1d:
                                      uVar12 = *(undefined8 *)(param_1 + 0x60);
                                      plVar14 = *(longlong **)(param_1 + 0x70);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      uVar22 = 0x4f;
                                      plVar11 = plVar15;
                                      uVar25 = *(undefined8 *)(param_1 + 0x68);
LAB_23e161e80:
                                      plStack_78 = (longlong *)0x0;
                                      auStack_88 = (undefined1  [16])0x0;
                                      lVar5 = *plStack_c8;
                                      *plStack_c8 = lVar5 + -1;
                                      if (lVar5 + -1 == 0) {
                                        (**(code **)(plStack_c8[1] + 0x30))();
                                      }
LAB_23e161ec1:
                                      lVar5 = *plVar10;
                                      *plVar10 = lVar5 + -1;
                                      if (lVar5 + -1 == 0) {
                                        (**(code **)(plVar10[1] + 0x30))();
                                      }
                                      pcStack_f0 = (code *)0x0;
                                      auStack_88._8_8_ = uVar25;
                                      auStack_88._0_8_ = uVar12;
                                      plStack_78 = plVar14;
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
                else {
                  uVar12 = FUN_23a3a0d40(_DAT_23eea9368);
                  *(undefined4 *)(plVar2 + 5) = 0x41;
                  plVar9 = (longlong *)FUN_23e915840(param_1,plVar7,_DAT_23eea9370);
                  if (plVar9 == (longlong *)0x0) {
                    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_78 = *(longlong **)(param_1 + 0x70);
                    plVar11 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_b8 = (longlong *)0x0;
                    uVar22 = 0x41;
                    pcStack_f0 = (code *)0x0;
                    plStack_f8 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_100 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_108 = (longlong *)0x0;
                  }
                  else {
                    *(undefined4 *)(plVar2 + 5) = 0x41;
                    plVar11 = (longlong *)FUN_23e914090(param_1,uVar12,plVar9);
                    lVar5 = *plVar9;
                    *plVar9 = lVar5 + -1;
                    if (lVar5 + -1 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    if (plVar11 == (longlong *)0x0) {
                      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_78 = *(longlong **)(param_1 + 0x70);
                      plVar11 = (longlong *)0x0;
                      plVar9 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar22 = 0x41;
                      pcStack_f0 = (code *)0x0;
                      plStack_f8 = (longlong *)0x0;
                      plStack_d8 = (longlong *)0x0;
                      plStack_e0 = (longlong *)0x0;
                      plStack_100 = (longlong *)0x0;
                      plStack_e8 = (longlong *)0x0;
                      plStack_108 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plStack_b8 = (longlong *)0x0;
                    }
                    else {
                      plVar9 = (longlong *)FUN_23ebf7180(plVar11);
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      plStack_e8 = (longlong *)0x0;
                      if (plVar9 == (longlong *)0x0) {
                        auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                        plStack_78 = *(longlong **)(param_1 + 0x70);
                        plVar11 = (longlong *)0x0;
                        plVar9 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plStack_b8 = (longlong *)0x0;
                        uVar22 = 0x41;
                        pcStack_f0 = (code *)0x0;
                        plStack_f8 = (longlong *)0x0;
                        plStack_d8 = (longlong *)0x0;
                        plStack_e0 = (longlong *)0x0;
                        plStack_108 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plStack_100 = (longlong *)0x0;
                      }
                      else {
                        lVar5 = plVar9[1];
                        pcVar13 = *(code **)(lVar5 + 0xe0);
                        plVar11 = (longlong *)0x0;
                        plStack_e8 = (longlong *)0x0;
                        plStack_b8 = (longlong *)0x0;
                        while (pcVar13 != (code *)0x0) {
                          plStack_108 = (longlong *)(*pcVar13)(plVar9);
                          if (plStack_108 == (longlong *)0x0) goto LAB_23e16167e;
                          if (plVar11 == (longlong *)0x0) {
                            *plStack_108 = *plStack_108 + 1;
                          }
                          else {
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              (**(code **)(plVar11[1] + 0x30))(plVar11);
                              lVar5 = *plStack_108;
                            }
                            else {
                              lVar5 = *plStack_108;
                            }
                            *plStack_108 = lVar5 + 1;
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              (**(code **)(plVar11[1] + 0x30))(plVar11);
                            }
                          }
                          plVar11 = (longlong *)FUN_23e8bc2f0(plStack_108,_DAT_23eea9380);
                          if (plVar11 == (longlong *)0x0) {
                            uVar12 = *(undefined8 *)(param_1 + 0x60);
                            uVar25 = *(undefined8 *)(param_1 + 0x68);
                            plVar10 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            uVar22 = 0x42;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            goto LAB_23e161804;
                          }
                          if ((plStack_b8 != (longlong *)0x0) &&
                             (*plStack_b8 = *plStack_b8 + -1, *plStack_b8 == 0)) {
                            (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
                          }
                          lVar5 = *(longlong *)(DAT_23eea91e8 + 0x20);
                          plStack_b8 = plVar11;
                          if (*(char *)(lVar5 + 10) == '\0') {
                            plVar10 = (longlong *)FUN_23a37a020(DAT_23eea91e8,DAT_23eea9388);
                            if (plVar10 == (longlong *)0x0) goto LAB_23e161760;
                            lVar20 = *plVar10;
LAB_23e16174c:
                            if (lVar20 == 0) goto LAB_23e161760;
                          }
                          else {
                            iVar21 = *(int *)(lVar5 + 0xc);
                            if (*(int *)(lVar5 + 0xc) == 0) {
                              *(int *)(lVar5 + 0xc) = _DAT_23ec14c90;
                              iVar21 = _DAT_23ec14c90;
                              _DAT_23ec14c90 = _DAT_23ec14c90 + 1;
                            }
                            if (_DAT_23ec14c94 != iVar21) {
                              _DAT_23ec14c94 = iVar21;
                              _DAT_23eeab160 =
                                   FUN_23e8cbd60(lVar5,DAT_23eea9388,
                                                 *(undefined8 *)(DAT_23eea9388 + 0x18));
                            }
                            if (-1 < _DAT_23eeab160) {
                              lVar24 = lVar5 + 0x20 + (1L << (*(byte *)(lVar5 + 9) & 0x3f));
                              lVar20 = *(longlong *)(lVar24 + 8 + _DAT_23eeab160 * 0x10);
                              if (lVar20 != 0) goto LAB_23e16150c;
                              _DAT_23eeab160 =
                                   FUN_23e8cbd60(lVar5,DAT_23eea9388,
                                                 *(undefined8 *)(DAT_23eea9388 + 0x18));
                              if (-1 < _DAT_23eeab160) {
                                lVar20 = *(longlong *)(lVar24 + 8 + _DAT_23eeab160 * 0x10);
                                goto LAB_23e16174c;
                              }
                            }
LAB_23e161760:
                            plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea9388);
                            if ((plVar10 == (longlong *)0x0) || (lVar20 = *plVar10, lVar20 == 0)) {
                              FUN_23e915740(param_1,auStack_88,DAT_23eea9388);
                              uVar22 = 0x44;
                              plVar10 = plStack_78;
                              uVar12 = auStack_88._0_8_;
                              uVar25 = auStack_88._8_8_;
                              goto LAB_23e161804;
                            }
                          }
LAB_23e16150c:
                          *(undefined4 *)(plVar2 + 5) = 0x44;
                          plVar10 = (longlong *)FUN_23e914090(param_1,lVar20,plVar11);
                          if (plVar10 == (longlong *)0x0) {
                            plVar10 = *(longlong **)(param_1 + 0x70);
                            uVar12 = *(undefined8 *)(param_1 + 0x60);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            uVar22 = 0x44;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar25 = *(undefined8 *)(param_1 + 0x68);
                            goto LAB_23e161804;
                          }
                          if ((plStack_e8 != (longlong *)0x0) &&
                             (*plStack_e8 = *plStack_e8 + -1, *plStack_e8 == 0)) {
                            (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
                          }
                          lVar5 = *(longlong *)(param_1 + 0x10);
                          puVar17 = *(undefined8 **)(lVar5 + 0xe20);
                          if (puVar17 == (undefined8 *)0x0) {
                            puVar17 = (undefined8 *)FUN_23e916a20(PyTuple_Type_exref,2);
                          }
                          else {
                            uVar12 = puVar17[3];
                            *(int *)(lVar5 + 0xebc) = *(int *)(lVar5 + 0xebc) + -1;
                            *(undefined8 *)(lVar5 + 0xe20) = uVar12;
                            *puVar17 = 1;
                          }
                          lVar5 = *(longlong *)
                                   (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) +
                                   0x2e8);
                          uVar12 = puVar17[-1];
                          puVar3 = *(undefined8 **)(lVar5 + 8);
                          *puVar3 = puVar17 + -2;
                          puVar17[-2] = lVar5;
                          puVar17[-1] = (ulonglong)((uint)uVar12 & 3) | (ulonglong)puVar3;
                          *(undefined8 **)(lVar5 + 8) = puVar17 + -2;
                          *plVar11 = *plVar11 + 1;
                          puVar17[3] = plVar11;
                          *plVar10 = *plVar10 + 1;
                          puVar17[4] = plVar10;
                          FUN_23e8ba4b0(plVar8);
                          lVar5 = *(longlong *)(param_1 + 0x10);
                          plStack_e8 = plVar10;
                          if ((((*(int *)(*(longlong *)(lVar5 + 0x28) + 0x160) != 0) ||
                               (*(int *)(lVar5 + 0x78) != 0)) &&
                              (iVar21 = Py_MakePendingCalls(), iVar21 < 0)) &&
                             (*(longlong *)(param_1 + 0x60) != 0)) {
LAB_23e1619e2:
                            plVar10 = *(longlong **)(param_1 + 0x70);
                            uVar12 = *(undefined8 *)(param_1 + 0x60);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar22 = 0x41;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            uVar25 = *(undefined8 *)(param_1 + 0x68);
                            goto LAB_23e161804;
                          }
                          if (*(int *)(lVar5 + 0x68) == 0) {
                            plVar11 = *(longlong **)(param_1 + 0x90);
                          }
                          else {
                            PyEval_SaveThread();
                            PyEval_AcquireThread(param_1);
                            plVar11 = *(longlong **)(param_1 + 0x90);
                          }
                          if (plVar11 != (longlong *)0x0) {
                            plVar10 = *(longlong **)(param_1 + 0x60);
                            plVar14 = *(longlong **)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x90) = 0;
                            plVar15 = *(longlong **)(param_1 + 0x70);
                            *(longlong **)(param_1 + 0x60) = plVar11;
                            *plVar11 = *plVar11 + 1;
                            *(undefined8 *)(param_1 + 0x68) = 0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            if ((plVar10 != (longlong *)0x0) &&
                               (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                              (**(code **)(plVar10[1] + 0x30))();
                            }
                            if ((plVar14 != (longlong *)0x0) &&
                               (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                            if ((plVar15 != (longlong *)0x0) &&
                               (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                              (**(code **)(plVar15[1] + 0x30))(plVar15);
                            }
                            goto LAB_23e1619e2;
                          }
                          lVar5 = plVar9[1];
                          plVar11 = plStack_108;
                          pcVar13 = *(code **)(lVar5 + 0xe0);
                        }
                        PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                                     "\'%s\' object is not an iterator",
                                     *(undefined8 *)(lVar5 + 0x18));
LAB_23e16167e:
                        cVar4 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                        plStack_108 = plVar11;
                        if (cVar4 != '\0') {
                          if ((plVar11 != (longlong *)0x0) &&
                             (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                            FUN_23a334bc0(plVar11);
                          }
                          lVar5 = *plVar9;
                          *plVar9 = lVar5 + -1;
                          if (lVar5 + -1 == 0) {
                            FUN_23a334bc0(plVar9);
                          }
                          goto LAB_23e15fd25;
                        }
                        uVar12 = *(undefined8 *)(param_1 + 0x60);
                        uVar25 = *(undefined8 *)(param_1 + 0x68);
                        plStack_78 = (longlong *)0x0;
                        plVar10 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        auStack_88 = (undefined1  [16])0x0;
                        if (plVar11 == (longlong *)0x0) {
                          uVar22 = 0x41;
                          plStack_108 = (longlong *)0x0;
                        }
                        else {
                          uVar22 = 0x41;
LAB_23e161804:
                          plStack_78 = (longlong *)0x0;
                          auStack_88 = (undefined1  [16])0x0;
                          lVar5 = *plStack_108;
                          *plStack_108 = lVar5 + -1;
                          if (lVar5 + -1 == 0) {
                            (**(code **)(plStack_108[1] + 0x30))(plStack_108);
                          }
                        }
                        lVar5 = *plVar9;
                        *plVar9 = lVar5 + -1;
                        if (lVar5 + -1 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        plVar11 = (longlong *)0x0;
                        plVar9 = (longlong *)0x0;
                        pcStack_f0 = (code *)0x0;
                        plStack_f8 = (longlong *)0x0;
                        plStack_d8 = (longlong *)0x0;
                        plStack_e0 = (longlong *)0x0;
                        plStack_100 = (longlong *)0x0;
                        auStack_88._8_8_ = uVar25;
                        auStack_88._0_8_ = uVar12;
                        plStack_78 = plVar10;
                      }
                    }
                  }
                }
              }
            }
            goto LAB_23e1607f0;
          }
        }
      }
    }
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_78 = *(longlong **)(param_1 + 0x70);
    plVar11 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar23 = 0x3d;
    uVar22 = 0x3d;
    pcStack_f0 = (code *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_78 == (longlong *)0x0) {
      plStack_78 = (longlong *)0x0;
      goto LAB_23e160de0;
    }
  }
  plVar10 = plStack_78;
  plVar14 = DAT_23ed6a4f8;
  if ((longlong *)plStack_78[3] != plVar2) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar15 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar14[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar22;
    pcVar13 = _PyRuntime_exref;
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
    lVar20 = plVar14[-1];
    puVar17 = *(undefined8 **)(lVar5 + 8);
    *puVar17 = plVar14 + -2;
    plVar14[-2] = lVar5;
    plVar14[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar5 + 8) = plVar14 + -2;
    plVar14[2] = (longlong)plVar10;
    *plVar10 = *plVar10 + 1;
    plVar10 = plVar14;
    if ((plStack_78 != (longlong *)0x0) && (*plStack_78 = *plStack_78 + -1, *plStack_78 == 0)) {
      (**(code **)(plStack_78[1] + 0x30))();
    }
  }
LAB_23e1608c8:
  plStack_78 = plVar10;
  FUN_23e8bba40(plVar2,"ooooooooNooooooo",plVar1,plVar6,plStack_118,plVar7,plVar8,plStack_108,
                plStack_b8,plStack_e8,0,plStack_100,plStack_e0,plStack_d8,plStack_f8,plVar9,plVar11,
                pcStack_f0);
  if (_DAT_23eeab170 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eeab170 = (longlong *)0x0;
  }
  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar5 + 0x28);
  plVar10 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar5 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  plVar10 = plStack_78;
  plVar2[0xf] = 0;
  uVar12 = auStack_88._0_8_;
  uVar25 = auStack_88._8_8_;
  auStack_88 = (undefined1  [16])0x0;
  plStack_78 = (longlong *)0x0;
  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  if ((plStack_118 != (longlong *)0x0) &&
     (lVar5 = *plStack_118, *plStack_118 = lVar5 + -1, lVar5 + -1 == 0)) {
    (**(code **)(plStack_118[1] + 0x30))();
  }
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar5 = *plStack_108, *plStack_108 = lVar5 + -1, lVar5 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((plStack_b8 != (longlong *)0x0) && (*plStack_b8 = *plStack_b8 + -1, *plStack_b8 == 0)) {
    (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar5 = *plStack_e8, *plStack_e8 = lVar5 + -1, lVar5 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))();
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar5 = *plStack_100, *plStack_100 = lVar5 + -1, lVar5 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar5 = *plStack_e0, *plStack_e0 = lVar5 + -1, lVar5 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plStack_d8 != (longlong *)0x0) &&
     (lVar5 = *plStack_d8, *plStack_d8 = lVar5 + -1, lVar5 + -1 == 0)) {
    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar5 = *plStack_f8, *plStack_f8 = lVar5 + -1, lVar5 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))();
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((pcStack_f0 != (code *)0x0) &&
     (lVar5 = *(longlong *)pcStack_f0, *(longlong *)pcStack_f0 = lVar5 + -1, lVar5 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_f0 + 8) + 0x30))(pcStack_f0);
  }
  lVar5 = *plVar1;
  *plVar1 = lVar5 + -1;
  plStack_78 = plVar10;
  auStack_88._0_8_ = uVar12;
  auStack_88._8_8_ = uVar25;
  if (lVar5 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_88._0_8_,auStack_88._8_8_,plStack_78);
  return 0;
}
