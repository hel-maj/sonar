/* ===== 23e31fa60 ui.telegram_tab:220 ===== */
/* ghidra_name=FUN_23e31fa60 entry=23e31fa60 size=10009 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e31fa60(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  code *pcVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong lVar16;
  code *pcVar17;
  longlong lVar18;
  code *pcVar19;
  longlong lVar20;
  code *pcVar21;
  ulonglong uVar22;
  undefined4 uVar23;
  longlong lVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  longlong *plStack_d0;
  code *pcStack_c0;
  longlong *plStack_b8;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar8 = _DAT_23eeb4c70;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb4c70 == (longlong *)0x0) {
LAB_23e31faaa:
    _DAT_23eeb4c70 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb4c68,DAT_23eeb4cf0);
  }
  else {
    lVar14 = *_DAT_23eeb4c70;
    if (1 < lVar14) {
      *_DAT_23eeb4c70 = lVar14 + -1;
      goto LAB_23e31faaa;
    }
    if (_DAT_23eeb4c70[2] != 0) {
      *_DAT_23eeb4c70 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e31faaa;
    }
  }
  plVar2 = _DAT_23eeb4c70;
  lVar14 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeb4c70 + 9;
  lVar18 = *(longlong *)(lVar14 + 8);
  _DAT_23eeb4c70[0xf] = lVar18;
  *(longlong **)(lVar14 + 8) = plVar8;
  if ((lVar18 != 0) &&
     (((*(char *)(lVar18 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar18 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar18 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar25 = _DAT_23eeb3b10;
  *(undefined4 *)(plVar2 + 8) = 0;
  plStack_d0 = (longlong *)FUN_23e8bc2f0(plVar1,uVar25);
  if (plStack_d0 == (longlong *)0x0) {
LAB_23e31ff00:
    plStack_b8 = *(longlong **)(param_1 + 0x60);
    pcVar17 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar21 = _PyRuntime_exref;
    if (pcVar17 == (code *)0x0) {
      plVar9 = (longlong *)0x0;
      pcVar19 = (code *)0x0;
      plVar8 = (longlong *)0x0;
      iVar7 = 0xde;
      goto LAB_23e3208b0;
    }
    if (*(longlong **)(pcVar17 + 0x18) == plVar2) {
      plVar9 = (longlong *)0x0;
      pcVar19 = (code *)0x0;
      plVar8 = (longlong *)0x0;
      pcVar10 = pcVar17;
      goto LAB_23e31ffe0;
    }
    plVar9 = (longlong *)0x0;
    pcVar19 = (code *)0x0;
    plVar8 = (longlong *)0x0;
    uVar23 = 0xde;
    goto LAB_23e31ff4d;
  }
  *(undefined4 *)(plVar2 + 5) = 0xde;
  plVar8 = (longlong *)FUN_23e91bfe0(param_1,plStack_d0,_DAT_23eeb3c08);
  lVar14 = *plStack_d0;
  *plStack_d0 = lVar14 + -1;
  if (lVar14 + -1 == 0) {
    (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
    if (plVar8 == (longlong *)0x0) goto LAB_23e31fdeb;
LAB_23e31fb89:
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeb3c10);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 == (longlong *)0x0) {
      plStack_b8 = *(longlong **)(param_1 + 0x60);
      pcVar17 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_c0 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar19 = (code *)0x0;
      pcVar21 = _PyRuntime_exref;
      if (pcVar17 == (code *)0x0) {
        plStack_d0 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        iVar7 = 0xde;
        goto LAB_23e3208b0;
      }
      if (*(longlong **)(pcVar17 + 0x18) == plVar2) {
        plStack_d0 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcVar10 = pcVar17;
        goto LAB_23e31ffe0;
      }
      plStack_d0 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar23 = 0xde;
      goto LAB_23e31ff4d;
    }
    *(undefined4 *)(plVar2 + 5) = 0xde;
    plStack_d0 = (longlong *)FUN_23e91a870(param_1,plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plStack_d0 == (longlong *)0x0) goto LAB_23e31ff00;
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b58);
    plVar8 = (longlong *)0x0;
    if (plVar9 == (longlong *)0x0) {
LAB_23e3201e0:
      plStack_b8 = *(longlong **)(param_1 + 0x60);
      pcVar17 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_c0 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar21 = _PyRuntime_exref;
      if (pcVar17 != (code *)0x0) {
        if (*(longlong **)(pcVar17 + 0x18) != plVar2) {
          plVar9 = (longlong *)0x0;
          pcVar19 = (code *)0x0;
          uVar23 = 0xdf;
          goto LAB_23e31ff4d;
        }
LAB_23e320260:
        plVar9 = (longlong *)0x0;
        pcVar19 = (code *)0x0;
        pcVar10 = pcVar17;
        goto LAB_23e31ffe0;
      }
      plVar9 = (longlong *)0x0;
      pcVar19 = (code *)0x0;
      iVar7 = 0xdf;
      goto LAB_23e3208b0;
    }
    *(undefined4 *)(plVar2 + 5) = 0xdf;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar9,_DAT_23eeb3c08);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar8 != (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeb3c10);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar9 == (longlong *)0x0) {
        plStack_b8 = *(longlong **)(param_1 + 0x60);
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = (longlong *)0x0;
        pcVar21 = _PyRuntime_exref;
        if (pcVar17 == (code *)0x0) {
          pcVar19 = (code *)0x0;
          plVar8 = (longlong *)0x0;
          iVar7 = 0xdf;
          goto LAB_23e3208b0;
        }
        if (plVar2 == *(longlong **)(pcVar17 + 0x18)) {
          pcVar19 = (code *)0x0;
          plVar8 = (longlong *)0x0;
          pcVar10 = pcVar17;
          goto LAB_23e31ffe0;
        }
        pcVar19 = (code *)0x0;
        plVar8 = (longlong *)0x0;
        uVar23 = 0xdf;
        goto LAB_23e31ff4d;
      }
      *(undefined4 *)(plVar2 + 5) = 0xdf;
      plVar8 = (longlong *)FUN_23e91a870(param_1,plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar8 == (longlong *)0x0) goto LAB_23e3201e0;
      iVar7 = FUN_23a35f020(plStack_d0);
      lVar14 = _DAT_23eeb3c68;
      if (iVar7 == -1) {
        plStack_b8 = *(longlong **)(param_1 + 0x60);
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar21 = _PyRuntime_exref;
        if (pcVar17 == (code *)0x0) {
          plVar9 = (longlong *)0x0;
          pcVar19 = (code *)0x0;
          iVar7 = 0xe1;
          goto LAB_23e3208b0;
        }
        if (*(longlong **)(pcVar17 + 0x18) != plVar2) {
          plVar9 = (longlong *)0x0;
          pcVar19 = (code *)0x0;
          uVar23 = 0xe1;
          goto LAB_23e31ff4d;
        }
        goto LAB_23e320260;
      }
      if (iVar7 == 0) {
        *(undefined4 *)(plVar2 + 5) = 0xe2;
        plVar9 = (longlong *)
                 FUN_23e915840(param_1,plVar1,_DAT_23eeb3c60,*(undefined8 *)(lVar14 + 0x18));
        if (plVar9 != (longlong *)0x0) {
LAB_23e31fcc7:
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          pcVar17 = _Py_NoneStruct_exref;
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          goto LAB_23e31fce3;
        }
        plStack_b8 = *(longlong **)(param_1 + 0x60);
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar21 = _PyRuntime_exref;
        if (pcVar17 == (code *)0x0) {
          plVar9 = (longlong *)0x0;
          iVar7 = 0xe2;
          pcVar19 = (code *)0x0;
          goto LAB_23e3208b0;
        }
        if (*(longlong **)(pcVar17 + 0x18) != plVar2) {
          plVar9 = (longlong *)0x0;
          uVar23 = 0xe2;
          pcVar19 = (code *)0x0;
          goto LAB_23e31ff4d;
        }
LAB_23e321600:
        pcVar19 = (code *)0x0;
LAB_23e321603:
        plVar9 = (longlong *)0x0;
        pcVar10 = pcVar17;
        goto LAB_23e31ffe0;
      }
      iVar7 = FUN_23a35f020(plVar8);
      lVar14 = _DAT_23eeb3c70;
      if (iVar7 == -1) {
        plStack_b8 = *(longlong **)(param_1 + 0x60);
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar21 = _PyRuntime_exref;
        if (pcVar17 == (code *)0x0) {
          plVar9 = (longlong *)0x0;
          pcVar19 = (code *)0x0;
          iVar7 = 0xe5;
          goto LAB_23e3208b0;
        }
        if (*(longlong **)(pcVar17 + 0x18) == plVar2) goto LAB_23e320260;
        plVar9 = (longlong *)0x0;
        pcVar19 = (code *)0x0;
        uVar23 = 0xe5;
        goto LAB_23e31ff4d;
      }
      if (iVar7 == 0) {
        *(undefined4 *)(plVar2 + 5) = 0xe6;
        plVar9 = (longlong *)
                 FUN_23e915840(param_1,plVar1,_DAT_23eeb3c60,*(undefined8 *)(lVar14 + 0x18));
        if (plVar9 != (longlong *)0x0) goto LAB_23e31fcc7;
        plStack_b8 = *(longlong **)(param_1 + 0x60);
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar21 = _PyRuntime_exref;
        if (pcVar17 == (code *)0x0) {
          plVar9 = (longlong *)0x0;
          iVar7 = 0xe6;
          pcVar19 = (code *)0x0;
          goto LAB_23e3208b0;
        }
        if (*(longlong **)(pcVar17 + 0x18) == plVar2) goto LAB_23e321600;
        plVar9 = (longlong *)0x0;
        uVar23 = 0xe6;
        pcVar19 = (code *)0x0;
        goto LAB_23e31ff4d;
      }
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6d020);
      if (plVar9 == (longlong *)0x0) {
LAB_23e3205e0:
        pcVar17 = *(code **)(param_1 + 0x70);
        uVar25 = *(undefined8 *)(param_1 + 0x60);
        uVar26 = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar21 = _PyRuntime_exref;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        *(undefined4 *)(plVar2 + 5) = 0xeb;
        plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar9,_DAT_23eeb3c78);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar11 == (longlong *)0x0) goto LAB_23e3205e0;
        plVar9 = (longlong *)FUN_23ebf7180(plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23e3205e0;
        lVar14 = *(longlong *)(param_1 + 0x10);
        if (*(int *)(lVar14 + 0x1188) == 0) {
          pcVar19 = (code *)FUN_23a33a530(PyList_Type_exref);
        }
        else {
          iVar7 = *(int *)(lVar14 + 0x1188) + -1;
          *(int *)(lVar14 + 0x1188) = iVar7;
          pcVar19 = *(code **)(lVar14 + 0xf08 + (longlong)iVar7 * 8);
          *(longlong *)pcVar19 = 1;
        }
        pcVar21 = _PyRuntime_exref;
        *(longlong *)(pcVar19 + 0x10) = 0;
        *(longlong *)(pcVar19 + 0x20) = 0;
        lVar14 = *(longlong *)(pcVar21 + 0x1f8);
        *(longlong *)(pcVar19 + 0x18) = 0;
        lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
        lVar18 = *(longlong *)(pcVar19 + -8);
        puVar3 = *(undefined8 **)(lVar14 + 8);
        *puVar3 = pcVar19 + -0x10;
        *(longlong *)(pcVar19 + -0x10) = lVar14;
        *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar3;
        *(code **)(lVar14 + 8) = pcVar19 + -0x10;
        plVar11 = (longlong *)0x0;
LAB_23e32054d:
        do {
          pcVar17 = *(code **)(plVar9[1] + 0xe0);
          if (pcVar17 == (code *)0x0) {
            PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                         *(undefined8 *)(plVar9[1] + 0x18));
LAB_23e320ebf:
            cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar6 == '\0') {
              uVar25 = *(undefined8 *)(param_1 + 0x60);
              uVar26 = *(undefined8 *)(param_1 + 0x68);
              pcVar17 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e320b2e;
            }
            *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
            lVar14 = *plVar9;
            *plVar9 = lVar14 + -1;
            if (lVar14 + -1 == 0) {
              FUN_23a334bc0();
            }
            *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
            if (*(longlong *)pcVar19 == 0) {
              FUN_23a334bc0(pcVar19);
            }
            if (plVar11 != (longlong *)0x0) {
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
            }
            *(undefined4 *)(plVar2 + 5) = 0xf1;
            plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,_DAT_23eeb3c88);
            if (plVar9 == (longlong *)0x0) {
              plStack_b8 = *(longlong **)(param_1 + 0x60);
              pcVar17 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcStack_c0 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar9 = (longlong *)0x0;
              if (pcVar17 == (code *)0x0) {
                iVar7 = 0xf1;
                goto LAB_23e3208b0;
              }
              pcVar10 = pcVar17;
              if (*(longlong **)(pcVar17 + 0x18) == plVar2) goto LAB_23e31ffe0;
              uVar23 = 0xf1;
              goto LAB_23e31ff4d;
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              FUN_23a334bc0(plVar9);
            }
            plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeb3998);
            if (plVar9 == (longlong *)0x0) {
              plStack_b8 = *(longlong **)(param_1 + 0x60);
              pcVar17 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcStack_c0 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar9 = (longlong *)0x0;
              if (pcVar17 == (code *)0x0) goto LAB_23e321b81;
              pcVar10 = pcVar17;
              if (*(longlong **)(pcVar17 + 0x18) == plVar2) goto LAB_23e31ffe0;
              uVar23 = 0xf4;
              goto LAB_23e31ff4d;
            }
            iVar7 = FUN_23a35f020(plVar9);
            lVar14 = *plVar9 + -1;
            if (iVar7 == -1) {
              plStack_b8 = *(longlong **)(param_1 + 0x60);
              pcVar17 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcStack_c0 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar9 = lVar14;
              if (lVar14 == 0) {
                FUN_23a334bc0(plVar9);
                if (pcVar17 == (code *)0x0) {
LAB_23e321b81:
                  plVar9 = (longlong *)0x0;
                  iVar7 = 0xf4;
                  goto LAB_23e3208b0;
                }
                plVar9 = *(longlong **)(pcVar17 + 0x18);
              }
              else {
                if (pcVar17 == (code *)0x0) goto LAB_23e321b81;
                plVar9 = *(longlong **)(pcVar17 + 0x18);
              }
              if (plVar2 == plVar9) goto LAB_23e321603;
              plVar9 = (longlong *)0x0;
              uVar23 = 0xf4;
              goto LAB_23e31ff4d;
            }
            *plVar9 = lVar14;
            if (lVar14 == 0) {
              FUN_23a334bc0(plVar9);
            }
            plVar9 = (longlong *)0x0;
            if (iVar7 != 0) {
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeb3998);
              if (plVar11 != (longlong *)0x0) {
                *(undefined4 *)(plVar2 + 5) = 0xf5;
                plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  FUN_23a334bc0(plVar11);
                }
                if (plVar9 != (longlong *)0x0) {
                  iVar7 = FUN_23a35f020(plVar9);
                  if (iVar7 == -1) {
                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcStack_c0 = *(code **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (pcVar17 == (code *)0x0) {
                      iVar7 = 0xf6;
                      goto LAB_23e3208b0;
                    }
                    pcVar10 = pcVar17;
                    if (*(longlong **)(pcVar17 + 0x18) == plVar2) goto LAB_23e31ffe0;
                    uVar23 = 0xf6;
                    goto LAB_23e31ff4d;
                  }
                  if (iVar7 == 0) goto LAB_23e321017;
                  lVar14 = *(longlong *)(DAT_23eeb3ee0 + 0x20);
                  if (*(char *)(lVar14 + 10) == '\0') {
                    plVar11 = (longlong *)FUN_23a37a020(DAT_23eeb3ee0,_DAT_23eeb3c98);
                    if (plVar11 == (longlong *)0x0) goto LAB_23e321de7;
                    lVar18 = *plVar11;
LAB_23e321dde:
                    if (lVar18 == 0) goto LAB_23e321de7;
LAB_23e321a6a:
                    *(undefined4 *)(plVar2 + 5) = 0xf7;
                    plVar11 = (longlong *)FUN_23e914090(param_1,lVar18,plVar9);
                    if (plVar11 != (longlong *)0x0) {
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        FUN_23a334bc0();
                      }
                      goto LAB_23e321017;
                    }
                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcStack_c0 = *(code **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (pcVar17 == (code *)0x0) goto LAB_23e321eba;
                    plVar11 = *(longlong **)(pcVar17 + 0x18);
                  }
                  else {
                    iVar7 = *(int *)(lVar14 + 0xc);
                    if (*(int *)(lVar14 + 0xc) == 0) {
                      *(int *)(lVar14 + 0xc) = DAT_23ec1506c;
                      iVar7 = DAT_23ec1506c;
                      DAT_23ec1506c = DAT_23ec1506c + 1;
                    }
                    if (_DAT_23ec15058 != iVar7) {
                      _DAT_23ec15058 = iVar7;
                      _DAT_23eeb4c58 =
                           FUN_23e8cbd60(lVar14,_DAT_23eeb3c98,
                                         *(undefined8 *)(_DAT_23eeb3c98 + 0x18));
                    }
                    if (-1 < _DAT_23eeb4c58) {
                      lVar24 = lVar14 + 0x20 + (1L << (*(byte *)(lVar14 + 9) & 0x3f));
                      lVar18 = *(longlong *)(lVar24 + 8 + _DAT_23eeb4c58 * 0x10);
                      if (lVar18 != 0) goto LAB_23e321a6a;
                      _DAT_23eeb4c58 =
                           FUN_23e8cbd60(lVar14,_DAT_23eeb3c98,
                                         *(undefined8 *)(_DAT_23eeb3c98 + 0x18));
                      if (-1 < _DAT_23eeb4c58) {
                        lVar18 = *(longlong *)(lVar24 + 8 + _DAT_23eeb4c58 * 0x10);
                        goto LAB_23e321dde;
                      }
                    }
LAB_23e321de7:
                    plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeb3c98);
                    if ((plVar11 != (longlong *)0x0) && (lVar18 = *plVar11, lVar18 != 0))
                    goto LAB_23e321a6a;
                    FUN_23e915740(param_1,&plStack_78,_DAT_23eeb3c98);
                    plStack_b8 = plStack_78;
                    pcStack_c0 = pcStack_70;
                    if (pcStack_68 == (code *)0x0) {
LAB_23e321eba:
                      iVar7 = 0xf7;
                      goto LAB_23e3208b0;
                    }
                    plVar11 = *(longlong **)(pcStack_68 + 0x18);
                    pcVar17 = pcStack_68;
                  }
                  pcVar10 = pcVar17;
                  if (plVar11 == plVar2) goto LAB_23e31ffe0;
                  uVar23 = 0xf7;
                  goto LAB_23e31ff4d;
                }
              }
              plStack_b8 = *(longlong **)(param_1 + 0x60);
              pcVar17 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcStack_c0 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (pcVar17 == (code *)0x0) {
                iVar7 = 0xf5;
                goto LAB_23e3208b0;
              }
              pcVar10 = pcVar17;
              if (*(longlong **)(pcVar17 + 0x18) == plVar2) goto LAB_23e31ffe0;
              uVar23 = 0xf5;
              goto LAB_23e31ff4d;
            }
LAB_23e321017:
            lVar14 = *(longlong *)(DAT_23eeb3ee0 + 0x20);
            if (*(char *)(lVar14 + 10) != '\0') {
              iVar7 = *(int *)(lVar14 + 0xc);
              if (*(int *)(lVar14 + 0xc) == 0) {
                *(int *)(lVar14 + 0xc) = DAT_23ec1506c;
                iVar7 = DAT_23ec1506c;
                DAT_23ec1506c = DAT_23ec1506c + 1;
              }
              if (_DAT_23ec1505c != iVar7) {
                _DAT_23ec1505c = iVar7;
                _DAT_23eeb4c60 =
                     FUN_23e8cbd60(lVar14,_DAT_23eeb3ca0,*(undefined8 *)(_DAT_23eeb3ca0 + 0x18));
              }
              if (-1 < _DAT_23eeb4c60) {
                lVar18 = lVar14 + 0x20 + (1L << (*(byte *)(lVar14 + 9) & 0x3f));
                lVar24 = *(longlong *)(lVar18 + 8 + _DAT_23eeb4c60 * 0x10);
                if (lVar24 != 0) goto LAB_23e3210ae;
                _DAT_23eeb4c60 =
                     FUN_23e8cbd60(lVar14,_DAT_23eeb3ca0,*(undefined8 *)(_DAT_23eeb3ca0 + 0x18));
                if (-1 < _DAT_23eeb4c60) {
                  lVar24 = *(longlong *)(lVar18 + 8 + _DAT_23eeb4c60 * 0x10);
                  goto LAB_23e3218a4;
                }
              }
LAB_23e3218ad:
              plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeb3ca0);
              if ((plVar11 != (longlong *)0x0) && (lVar24 = *plVar11, lVar24 != 0))
              goto LAB_23e3210ae;
              FUN_23e915740(param_1,&plStack_78,_DAT_23eeb3ca0);
              plStack_b8 = plStack_78;
              pcStack_c0 = pcStack_70;
              pcVar10 = pcStack_68;
              if (pcStack_68 == (code *)0x0) goto LAB_23e321aeb;
LAB_23e32192a:
              pcVar17 = pcVar10;
              if (*(longlong **)(pcVar10 + 0x18) == plVar2) goto LAB_23e31ffe0;
LAB_23e321934:
              uVar23 = 0xfa;
              goto LAB_23e31ff4d;
            }
            plVar11 = (longlong *)FUN_23a37a020(DAT_23eeb3ee0,_DAT_23eeb3ca0);
            if (plVar11 == (longlong *)0x0) goto LAB_23e3218ad;
            lVar24 = *plVar11;
LAB_23e3218a4:
            if (lVar24 == 0) goto LAB_23e3218ad;
LAB_23e3210ae:
            pcVar17 = (code *)FUN_23e8bc2f0(plVar1);
            if (pcVar17 == (code *)0x0) {
              plStack_b8 = *(longlong **)(param_1 + 0x60);
              pcVar17 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcStack_c0 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (pcVar17 == (code *)0x0) {
                iVar7 = 0xfd;
                goto LAB_23e3208b0;
              }
              pcVar10 = pcVar17;
              if (*(longlong **)(pcVar17 + 0x18) == plVar2) goto LAB_23e31ffe0;
              uVar23 = 0xfd;
              goto LAB_23e31ff4d;
            }
            *(undefined4 *)(plVar2 + 5) = 0xfa;
            plStack_78 = plStack_d0;
            pcStack_70 = pcVar19;
            pcStack_68 = pcVar17;
            plVar11 = (longlong *)FUN_23e9186b0(param_1,lVar24,&plStack_78,_DAT_23eeb3ca8);
            *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
            if (*(longlong *)pcVar17 == 0) {
              FUN_23a334bc0(pcVar17);
            }
            if (plVar11 == (longlong *)0x0) {
              plStack_b8 = *(longlong **)(param_1 + 0x60);
              pcVar10 = *(code **)(param_1 + 0x70);
              pcStack_c0 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              if (pcVar10 != (code *)0x0) {
                pcVar17 = pcVar10;
                if (plVar2 != *(longlong **)(pcVar10 + 0x18)) goto LAB_23e321934;
                goto LAB_23e31ffe0;
              }
            }
            else {
              cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eeb3990,plVar11);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              if (cVar6 != '\0') {
                plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeb3990);
                if (plVar11 == (longlong *)0x0) {
                  plStack_b8 = *(longlong **)(param_1 + 0x60);
                  pcVar17 = *(code **)(param_1 + 0x70);
                  pcStack_c0 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
joined_r0x00023e321c34:
                  if (pcVar17 == (code *)0x0) {
LAB_23e3220c1:
                    iVar7 = 0x100;
                    goto LAB_23e3208b0;
                  }
                  plVar11 = *(longlong **)(pcVar17 + 0x18);
                }
                else {
                  *(undefined4 *)(plVar2 + 5) = 0x100;
                  plVar15 = (longlong *)FUN_23e91bfe0(param_1,plVar11,_DAT_23eeb3cb0);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
                  if (plVar15 != (longlong *)0x0) {
                    iVar7 = FUN_23a35f020(plVar15);
                    lVar14 = *plVar15 + -1;
                    if (iVar7 == -1) {
                      plStack_b8 = *(longlong **)(param_1 + 0x60);
                      pcVar17 = *(code **)(param_1 + 0x70);
                      pcStack_c0 = *(code **)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *plVar15 = lVar14;
                      if (lVar14 == 0) {
                        FUN_23a334bc0(plVar15);
                      }
                      goto joined_r0x00023e321c34;
                    }
                    *plVar15 = lVar14;
                    if (lVar14 == 0) {
                      FUN_23a334bc0(plVar15);
                    }
                    pcVar17 = _Py_NoneStruct_exref;
                    if (iVar7 != 0) {
                      plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b78);
                      lVar14 = _DAT_23eeb3cb8;
                      if (plVar11 == (longlong *)0x0) {
                        plStack_b8 = *(longlong **)(param_1 + 0x60);
                        pcVar17 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        pcStack_c0 = *(code **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (pcVar17 == (code *)0x0) {
LAB_23e32206e:
                          iVar7 = 0x101;
                          goto LAB_23e3208b0;
                        }
                        plVar11 = *(longlong **)(pcVar17 + 0x18);
                      }
                      else {
                        *(undefined4 *)(plVar2 + 5) = 0x101;
                        plVar15 = (longlong *)
                                  FUN_23e915840(param_1,plVar11,_DAT_23eeb3be0,
                                                *(undefined8 *)(lVar14 + 0x18));
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          FUN_23a334bc0(plVar11);
                        }
                        if (plVar15 != (longlong *)0x0) {
                          *plVar15 = *plVar15 + -1;
                          if (*plVar15 == 0) {
                            FUN_23a334bc0(plVar15);
                          }
                          plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b78);
                          if (plVar11 != (longlong *)0x0) {
                            *(undefined4 *)(plVar2 + 5) = 0x102;
                            plVar15 = (longlong *)FUN_23e915840(param_1,plVar11);
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              FUN_23a334bc0(plVar11);
                            }
                            if (plVar15 != (longlong *)0x0) {
                              *plVar15 = *plVar15 + -1;
                              if (*plVar15 == 0) {
                                FUN_23a334bc0(plVar15);
                              }
                              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b78);
                              if (plVar11 == (longlong *)0x0) {
LAB_23e321fd6:
                                plStack_b8 = *(longlong **)(param_1 + 0x60);
                                pcVar17 = *(code **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pcStack_c0 = *(code **)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023e321ffd:
                                if (pcVar17 == (code *)0x0) {
LAB_23e321fff:
                                  iVar7 = 0x103;
                                  goto LAB_23e3208b0;
                                }
                                plVar11 = *(longlong **)(pcVar17 + 0x18);
                              }
                              else {
                                plVar15 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeb3cc8);
                                *plVar11 = *plVar11 + -1;
                                if (*plVar11 == 0) {
                                  FUN_23a334bc0(plVar11);
                                }
                                if (plVar15 != (longlong *)0x0) {
                                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b78);
                                  if (plVar11 != (longlong *)0x0) {
                                    *(undefined4 *)(plVar2 + 5) = 0x103;
                                    plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar11);
                                    *plVar11 = *plVar11 + -1;
                                    if (*plVar11 == 0) {
                                      FUN_23a334bc0(plVar11);
                                    }
                                    if (plVar12 != (longlong *)0x0) {
                                      *(undefined4 *)(plVar2 + 5) = 0x103;
                                      plVar11 = (longlong *)FUN_23e914090(param_1,plVar15,plVar12);
                                      *plVar15 = *plVar15 + -1;
                                      if (*plVar15 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      *plVar12 = *plVar12 + -1;
                                      if (*plVar12 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      if (plVar11 == (longlong *)0x0) goto LAB_23e321fd6;
                                      *plVar11 = *plVar11 + -1;
                                      if (*plVar11 == 0) {
                                        FUN_23a334bc0(plVar11);
                                      }
                                      lVar14 = _DAT_23eeb3cd8;
                                      *(undefined4 *)(plVar2 + 5) = 0x104;
                                      plVar11 = (longlong *)
                                                FUN_23e915840(param_1,plVar1,_DAT_23eeb3c60,
                                                              *(undefined8 *)(lVar14 + 0x18));
                                      if (plVar11 != (longlong *)0x0) {
                                        *plVar11 = *plVar11 + -1;
                                        pcVar17 = _Py_NoneStruct_exref;
                                        if (*plVar11 == 0) {
                                          FUN_23a334bc0(plVar11);
                                          pcVar17 = _Py_NoneStruct_exref;
                                        }
                                        goto LAB_23e3214d4;
                                      }
                                      plStack_b8 = *(longlong **)(param_1 + 0x60);
                                      pcVar17 = *(code **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      pcStack_c0 = *(code **)(param_1 + 0x68);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      if (pcVar17 == (code *)0x0) {
                                        iVar7 = 0x104;
                                        goto LAB_23e3208b0;
                                      }
                                      pcVar10 = pcVar17;
                                      if (*(longlong **)(pcVar17 + 0x18) == plVar2)
                                      goto LAB_23e31ffe0;
                                      uVar23 = 0x104;
                                      goto LAB_23e31ff4d;
                                    }
                                  }
                                  plStack_b8 = *(longlong **)(param_1 + 0x60);
                                  pcVar17 = *(code **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  pcStack_c0 = *(code **)(param_1 + 0x68);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *plVar15 = *plVar15 + -1;
                                  if (*plVar15 == 0) {
                                    FUN_23a334bc0(plVar15);
                                  }
                                  goto joined_r0x00023e321ffd;
                                }
                                plStack_b8 = *(longlong **)(param_1 + 0x60);
                                pcVar17 = *(code **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pcStack_c0 = *(code **)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                if (pcVar17 == (code *)0x0) goto LAB_23e321fff;
                                plVar11 = *(longlong **)(pcVar17 + 0x18);
                              }
                              pcVar10 = pcVar17;
                              if (plVar2 == plVar11) goto LAB_23e31ffe0;
                              uVar23 = 0x103;
                              goto LAB_23e31ff4d;
                            }
                          }
                          plStack_b8 = *(longlong **)(param_1 + 0x60);
                          pcVar17 = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          pcStack_c0 = *(code **)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (pcVar17 == (code *)0x0) {
                            iVar7 = 0x102;
                            goto LAB_23e3208b0;
                          }
                          pcVar10 = pcVar17;
                          if (*(longlong **)(pcVar17 + 0x18) == plVar2) goto LAB_23e31ffe0;
                          uVar23 = 0x102;
                          goto LAB_23e31ff4d;
                        }
                        plStack_b8 = *(longlong **)(param_1 + 0x60);
                        pcVar17 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        pcStack_c0 = *(code **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (pcVar17 == (code *)0x0) goto LAB_23e32206e;
                        plVar11 = *(longlong **)(pcVar17 + 0x18);
                      }
                      pcVar10 = pcVar17;
                      if (plVar2 == plVar11) goto LAB_23e31ffe0;
                      uVar23 = 0x101;
                      goto LAB_23e31ff4d;
                    }
                    cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eeb3990,_Py_NoneStruct_exref);
                    if (cVar6 == '\0') {
                      plStack_b8 = *(longlong **)(param_1 + 0x60);
                      pcVar17 = *(code **)(param_1 + 0x70);
                      pcStack_c0 = *(code **)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      if (pcVar17 == (code *)0x0) {
                        iVar7 = 0x106;
                        goto LAB_23e3208b0;
                      }
                      pcVar10 = pcVar17;
                      if (*(longlong **)(pcVar17 + 0x18) == plVar2) goto LAB_23e31ffe0;
                      uVar23 = 0x106;
                      goto LAB_23e31ff4d;
                    }
LAB_23e3214d4:
                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                    *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                    goto LAB_23e31fd39;
                  }
                  plStack_b8 = *(longlong **)(param_1 + 0x60);
                  pcVar17 = *(code **)(param_1 + 0x70);
                  pcStack_c0 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  if (pcVar17 == (code *)0x0) goto LAB_23e3220c1;
                  plVar11 = *(longlong **)(pcVar17 + 0x18);
                }
                pcVar10 = pcVar17;
                if (plVar2 == plVar11) goto LAB_23e31ffe0;
                uVar23 = 0x100;
                goto LAB_23e31ff4d;
              }
              plStack_b8 = *(longlong **)(param_1 + 0x60);
              pcVar10 = *(code **)(param_1 + 0x70);
              pcStack_c0 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              if (pcVar10 != (code *)0x0) goto LAB_23e32192a;
            }
LAB_23e321aeb:
            iVar7 = 0xfa;
            goto LAB_23e3208b0;
          }
          plVar15 = (longlong *)(*pcVar17)(plVar9);
          if (plVar15 == (longlong *)0x0) goto LAB_23e320ebf;
          if (plVar11 == (longlong *)0x0) {
            *plVar15 = *plVar15 + 1;
          }
          else {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
              lVar14 = *plVar15;
            }
            else {
              lVar14 = *plVar15;
            }
            *plVar15 = lVar14 + 1;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
          }
          plVar12 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eeb3c10);
          plVar11 = plVar15;
          if (plVar12 == (longlong *)0x0) goto LAB_23e320b15;
          *(undefined4 *)(plVar2 + 5) = 0xeb;
          plVar13 = (longlong *)FUN_23e91a870(param_1,plVar12);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if (plVar13 == (longlong *)0x0) goto LAB_23e320b15;
          iVar7 = FUN_23a35f020(plVar13);
          lVar14 = *plVar13 + -1;
          if (iVar7 == -1) {
            uVar25 = *(undefined8 *)(param_1 + 0x60);
            uVar26 = *(undefined8 *)(param_1 + 0x68);
            pcVar17 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar13 = lVar14;
            if (lVar14 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            goto LAB_23e320b2e;
          }
          *plVar13 = lVar14;
          if (lVar14 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (iVar7 != 0) {
            plVar15 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eeb3c10);
            if (plVar15 == (longlong *)0x0) goto LAB_23e320b15;
            *(undefined4 *)(plVar2 + 5) = 0xeb;
            plVar12 = (longlong *)FUN_23e91a870(param_1,plVar15);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (plVar12 == (longlong *)0x0) goto LAB_23e320b15;
            lVar14 = PyNumber_Long(plVar12);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (lVar14 == 0) goto LAB_23e320b15;
            lVar24 = *(longlong *)(pcVar19 + 0x10);
            lVar16 = *(longlong *)(pcVar19 + 0x18);
            lVar18 = lVar24 + 1;
            if ((*(longlong *)(pcVar19 + 0x20) < lVar18) ||
               (lVar18 < *(longlong *)(pcVar19 + 0x20) >> 1)) {
              if (lVar18 == 0) {
                lVar20 = 0;
                uVar22 = 0;
              }
              else {
                uVar22 = lVar24 + 7 + (lVar18 >> 3) & 0xfffffffffffffffc;
                lVar20 = uVar22 * 8;
              }
              lVar16 = (*DAT_23ed6e610)(0,lVar16,lVar20);
              if (lVar16 == 0) {
                PyErr_NoMemory();
                uVar25 = *(undefined8 *)(param_1 + 0x60);
                uVar26 = *(undefined8 *)(param_1 + 0x68);
                pcVar17 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e320b2e;
              }
              *(longlong *)(pcVar19 + 0x18) = lVar16;
              *(longlong *)(pcVar19 + 0x10) = lVar18;
              *(ulonglong *)(pcVar19 + 0x20) = uVar22;
            }
            else {
              *(longlong *)(pcVar19 + 0x10) = lVar18;
            }
            *(longlong *)(lVar16 + lVar24 * 8) = lVar14;
          }
          lVar14 = *(longlong *)(param_1 + 0x10);
          if ((((*(int *)(*(longlong *)(lVar14 + 0x28) + 0x160) != 0) ||
               (*(int *)(lVar14 + 0x78) != 0)) && (iVar7 = Py_MakePendingCalls(), iVar7 < 0)) &&
             (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e320b15;
          if (*(int *)(lVar14 + 0x68) == 0) {
            plVar15 = *(longlong **)(param_1 + 0x90);
            if (plVar15 != (longlong *)0x0) break;
            goto LAB_23e32054d;
          }
          PyEval_SaveThread();
          PyEval_AcquireThread(param_1);
          plVar15 = *(longlong **)(param_1 + 0x90);
        } while (plVar15 == (longlong *)0x0);
        plVar12 = *(longlong **)(param_1 + 0x60);
        plVar13 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar4 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar15;
        *plVar15 = *plVar15 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
          (**(code **)(plVar12[1] + 0x30))();
        }
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
          (**(code **)(plVar4[1] + 0x30))(plVar4);
        }
LAB_23e320b15:
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar25 = *(undefined8 *)(param_1 + 0x60);
        uVar26 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e320b2e:
        lVar14 = *plVar9;
        *plVar9 = lVar14 + -1;
        if (lVar14 + -1 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
        if (*(longlong *)pcVar19 == 0) {
          (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
        }
        if (plVar11 != (longlong *)0x0) {
          lVar14 = *plVar11 + -1;
          *plVar11 = lVar14;
          if (lVar14 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
            lVar14 = *plVar11;
          }
          *plVar11 = lVar14 + -1;
          if (lVar14 + -1 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
        }
      }
      plVar9 = *(longlong **)(param_1 + 0x138);
      auStack_98._8_8_ = uVar26;
      auStack_98._0_8_ = uVar25;
      if (plVar9 != (longlong *)0x0) {
        *plVar9 = *plVar9 + 1;
      }
      pcVar19 = DAT_23ed6a4f8;
      apcStack_88[0] = pcVar17;
      if (pcVar17 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar17 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar17;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong *)(pcVar19 + 0x10) = 0;
        *(longlong **)(pcVar19 + 0x18) = plVar2;
        *plVar2 = *plVar2 + 1;
        *(longlong *)(pcVar19 + 0x20) = 0xebffffffff;
        lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar21 + 0x1f8) + 0x10) + 0x2e8);
        lVar18 = *(longlong *)(pcVar19 + -8);
        puVar3 = *(undefined8 **)(lVar14 + 8);
        *puVar3 = pcVar19 + -0x10;
        *(longlong *)(pcVar19 + -0x10) = lVar14;
        *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar3;
        *(code **)(lVar14 + 8) = pcVar19 + -0x10;
        if ((apcStack_88[0] != (code *)0x0) &&
           (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
           *(longlong *)apcStack_88[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar10 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar10;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar19 + 0x18) = plVar2;
        *plVar2 = *plVar2 + 1;
        *(longlong *)(pcVar19 + 0x20) = 0xebffffffff;
        lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar21 + 0x1f8) + 0x10) + 0x2e8);
        lVar18 = *(longlong *)(pcVar19 + -8);
        puVar3 = *(undefined8 **)(lVar14 + 8);
        *puVar3 = pcVar19 + -0x10;
        *(longlong *)(pcVar19 + -0x10) = lVar14;
        *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar3;
        *(code **)(lVar14 + 8) = pcVar19 + -0x10;
        *(code **)(pcVar19 + 0x10) = pcVar17;
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        if ((apcStack_88[0] != (code *)0x0) &&
           (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
           *(longlong *)apcStack_88[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
        }
      }
      pcVar17 = _Py_NoneStruct_exref;
      apcStack_88[0] = pcVar19;
      if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
         ((code *)auStack_98._0_8_ != (code *)0x0)) {
        FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
      }
      plVar11 = *(longlong **)(auStack_98._8_8_ + 0x28);
      if (apcStack_88[0] == pcVar17) {
        pcVar19 = (code *)0x0;
      }
      else {
        pcVar19 = apcStack_88[0];
        if (apcStack_88[0] != (code *)0x0) {
          *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
        }
      }
      *(code **)(auStack_98._8_8_ + 0x28) = pcVar19;
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))();
      }
      plVar11 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))();
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
      iVar7 = FUN_23a444d40(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                            *(undefined8 *)PyExc_ValueError_exref);
      lVar14 = _DAT_23eeb3c80;
      if (iVar7 != 0) {
        *(undefined4 *)(plVar2 + 5) = 0xed;
        plVar11 = (longlong *)
                  FUN_23e915840(param_1,plVar1,_DAT_23eeb3c60,*(undefined8 *)(lVar14 + 0x18));
        if (plVar11 != (longlong *)0x0) {
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          plVar2 = *(longlong **)(param_1 + 0x138);
          *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
          *(longlong **)(param_1 + 0x138) = plVar9;
          if ((plVar2 != (longlong *)0x0) && (*plVar2 = *plVar2 + -1, *plVar2 == 0)) {
            (**(code **)(plVar2[1] + 0x30))();
          }
LAB_23e31fce3:
          lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar2 = *(longlong **)(lVar14 + 0x28);
          plVar9 = (longlong *)plVar2[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
          *(undefined4 *)(plVar2 + 8) = 0xffffffff;
          if (plVar9 != (longlong *)0x0) {
            plVar2[2] = 0;
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))();
            }
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))(plVar2);
          }
          plVar2[0xf] = 0;
          plVar9 = (longlong *)0x0;
          pcVar19 = (code *)0x0;
LAB_23e31fd39:
          lVar14 = *plStack_d0;
          *plStack_d0 = lVar14 + -1;
          if (lVar14 + -1 == 0) {
            (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if ((pcVar19 != (code *)0x0) &&
             (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, *(longlong *)pcVar19 == 0)) {
            (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
          }
          if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          lVar14 = *plVar1;
          *plVar1 = lVar14 + -1;
          if (lVar14 + -1 != 0) {
            return pcVar17;
          }
          (**(code **)(plVar1[1] + 0x30))(plVar1);
          return pcVar17;
        }
        plStack_b8 = *(longlong **)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x138);
        *(longlong **)(param_1 + 0x138) = plVar9;
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar19 = (code *)0x0;
        if (plVar11 == (longlong *)0x0) {
          if (pcVar17 == (code *)0x0) {
LAB_23e321ab0:
            plVar9 = (longlong *)0x0;
            iVar7 = 0xed;
            goto LAB_23e3208b0;
          }
          if (plVar2 == *(longlong **)(pcVar17 + 0x18)) {
            plVar9 = (longlong *)0x0;
            pcVar10 = pcVar17;
            goto LAB_23e31ffe0;
          }
        }
        else {
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
            if (pcVar17 != (code *)0x0) {
              iVar7 = 0xed;
              goto LAB_23e320e6d;
            }
            iVar7 = 0xed;
LAB_23e321f21:
            plVar9 = (longlong *)0x0;
            pcVar19 = (code *)0x0;
            goto LAB_23e3208b0;
          }
          if (pcVar17 == (code *)0x0) goto LAB_23e321ab0;
          if (plVar2 == *(longlong **)(pcVar17 + 0x18)) goto LAB_23e321600;
        }
        plVar9 = (longlong *)0x0;
        uVar23 = 0xed;
        goto LAB_23e31ff4d;
      }
      pcVar19 = *(code **)(param_1 + 0x138);
      if ((pcVar19 == pcVar17) || (pcVar19 == (code *)0x0)) {
        plStack_b8 = *(longlong **)PyExc_RuntimeError_exref;
        pcStack_c0 = (code *)PyUnicode_FromString("No active exception to reraise");
        *plStack_b8 = *plStack_b8 + 1;
        pcVar19 = *(code **)(param_1 + 0x138);
        *(longlong **)(param_1 + 0x138) = plVar9;
        if (pcVar19 != (code *)0x0) {
          lVar14 = *(longlong *)pcVar19;
          iVar7 = 0xea;
          *(longlong *)pcVar19 = lVar14 + -1;
          if (lVar14 + -1 == 0) goto LAB_23e3216fb;
        }
        plVar9 = (longlong *)0x0;
        pcVar19 = (code *)0x0;
        iVar7 = 0xea;
        goto LAB_23e3208b0;
      }
      plStack_b8 = *(longlong **)(pcVar19 + 8);
      pcVar17 = *(code **)(pcVar19 + 0x28);
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      *plStack_b8 = *plStack_b8 + 1;
      pcStack_c0 = pcVar19;
      if (pcVar17 != (code *)0x0) {
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        if (plVar2 == *(longlong **)(pcVar17 + 0x18)) {
          *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar17 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar9;
        lVar14 = *(longlong *)pcVar19;
        *(longlong *)pcVar19 = lVar14 + -1;
        if (lVar14 + -1 == 0) {
          (*(code *)plStack_b8[6])(pcVar19);
          iVar7 = 0;
LAB_23e320e6d:
          if (*(longlong **)(pcVar17 + 0x18) == plVar2) goto LAB_23e320260;
          if (iVar7 != 0) {
            plVar9 = (longlong *)0x0;
            pcVar19 = (code *)0x0;
            uVar23 = 0xed;
            goto LAB_23e31ff4d;
          }
        }
        else if (plVar2 == *(longlong **)(pcVar17 + 0x18)) goto LAB_23e320260;
        uVar23 = (undefined4)plVar2[5];
        plVar9 = (longlong *)0x0;
        pcVar19 = (code *)0x0;
        goto LAB_23e31ff4d;
      }
      lVar14 = *(longlong *)pcVar19;
      *(longlong **)(param_1 + 0x138) = plVar9;
      *(longlong *)pcVar19 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        iVar7 = 0;
LAB_23e3216fb:
        (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
        if (iVar7 != 0) goto LAB_23e321f21;
      }
      iVar7 = (int)plVar2[5];
      plVar9 = (longlong *)0x0;
      pcVar19 = (code *)0x0;
      goto LAB_23e3208b0;
    }
    plStack_b8 = *(longlong **)(param_1 + 0x60);
    pcVar17 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar19 = (code *)0x0;
    pcVar21 = _PyRuntime_exref;
    if (pcVar17 == (code *)0x0) {
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      iVar7 = 0xdf;
      goto LAB_23e3208b0;
    }
    if (*(longlong **)(pcVar17 + 0x18) == plVar2) {
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcVar10 = pcVar17;
      goto LAB_23e31ffe0;
    }
    plVar9 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar23 = 0xdf;
  }
  else {
    if (plVar8 != (longlong *)0x0) goto LAB_23e31fb89;
LAB_23e31fdeb:
    plStack_b8 = *(longlong **)(param_1 + 0x60);
    pcVar17 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar21 = _PyRuntime_exref;
    if (pcVar17 == (code *)0x0) {
      plStack_d0 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar19 = (code *)0x0;
      iVar7 = 0xde;
LAB_23e3208b0:
      pcVar10 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar10 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar17 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar10 + 0x10) = 0;
      *(longlong **)(pcVar10 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      lVar14 = *(longlong *)(pcVar21 + 0x1f8);
      *(int *)(pcVar10 + 0x24) = iVar7;
      lVar14 = *(longlong *)(lVar14 + 0x10);
      *(undefined4 *)(pcVar10 + 0x20) = 0xffffffff;
      lVar14 = *(longlong *)(lVar14 + 0x2e8);
      lVar18 = *(longlong *)(pcVar10 + -8);
      puVar3 = *(undefined8 **)(lVar14 + 8);
      *puVar3 = pcVar10 + -0x10;
      *(longlong *)(pcVar10 + -0x10) = lVar14;
      *(ulonglong *)(pcVar10 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar3;
      *(code **)(lVar14 + 8) = pcVar10 + -0x10;
      goto LAB_23e31ffe0;
    }
    if (*(longlong **)(pcVar17 + 0x18) == plVar2) {
      plStack_d0 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar19 = (code *)0x0;
      pcVar10 = pcVar17;
      goto LAB_23e31ffe0;
    }
    plStack_d0 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    pcVar19 = (code *)0x0;
    uVar23 = 0xde;
  }
LAB_23e31ff4d:
  pcVar10 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar10 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar5 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar5;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar10 + 0x18) = plVar2;
  *plVar2 = *plVar2 + 1;
  lVar14 = *(longlong *)(pcVar21 + 0x1f8);
  *(undefined4 *)(pcVar10 + 0x20) = 0xffffffff;
  lVar14 = *(longlong *)(lVar14 + 0x10);
  *(undefined4 *)(pcVar10 + 0x24) = uVar23;
  lVar14 = *(longlong *)(lVar14 + 0x2e8);
  lVar18 = *(longlong *)(pcVar10 + -8);
  puVar3 = *(undefined8 **)(lVar14 + 8);
  *puVar3 = pcVar10 + -0x10;
  *(longlong *)(pcVar10 + -0x10) = lVar14;
  *(ulonglong *)(pcVar10 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar3;
  lVar18 = *(longlong *)pcVar17;
  *(code **)(lVar14 + 8) = pcVar10 + -0x10;
  *(code **)(pcVar10 + 0x10) = pcVar17;
  if (lVar18 == 0) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
  }
LAB_23e31ffe0:
  FUN_23e8bba40(plVar2,"ooooo",plVar1,plStack_d0,plVar8,pcVar19,plVar9);
  if (_DAT_23eeb4c70 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eeb4c70 = (longlong *)0x0;
  }
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar14 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
  plVar11 = (longlong *)plVar2[2];
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  plVar2[0xf] = 0;
  if ((plStack_d0 != (longlong *)0x0) &&
     (lVar14 = *plStack_d0, *plStack_d0 = lVar14 + -1, lVar14 + -1 == 0)) {
    (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((pcVar19 != (code *)0x0) &&
     (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, *(longlong *)pcVar19 == 0)) {
    (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar14 = *plVar1;
  *plVar1 = lVar14 + -1;
  if (lVar14 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plStack_b8,pcStack_c0,pcVar10);
  return (code *)0x0;
}
