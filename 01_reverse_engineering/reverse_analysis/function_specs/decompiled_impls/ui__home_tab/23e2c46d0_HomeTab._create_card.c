/* ===== 23e2c46d0 ui.home_tab:247 ===== */
/* ghidra_name=FUN_23e2c46d0 entry=23e2c46d0 size=4222 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_23e2c46d0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  code *pcVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  undefined8 *puVar16;
  longlong *plVar17;
  longlong *plStack_98;
  undefined8 uStack_90;
  undefined4 uStack_88;
  longlong *plStack_78;
  undefined8 uStack_70;
  longlong *plStack_68;
  
  plVar11 = _DAT_23eeb0318;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  if (_DAT_23eeb0318 == (longlong *)0x0) {
LAB_23e2c4722:
    _DAT_23eeb0318 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0310,DAT_23eeb0380,0x30);
  }
  else {
    lVar9 = *_DAT_23eeb0318;
    if (1 < lVar9) {
      *_DAT_23eeb0318 = lVar9 + -1;
      goto LAB_23e2c4722;
    }
    if (_DAT_23eeb0318[2] != 0) {
      *_DAT_23eeb0318 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e2c4722;
    }
  }
  plVar5 = _DAT_23eeb0318;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eeb0318 + 9;
  lVar4 = *(longlong *)(lVar9 + 8);
  _DAT_23eeb0318[0xf] = lVar4;
  *(longlong **)(lVar9 + 8) = plVar11;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  lVar9 = FUN_23e8f6fb0();
  if (lVar9 == 0) {
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    FUN_23e915740(param_1,&plStack_78,DAT_23eeada80);
    uStack_88 = 0xf9;
    plStack_98 = plStack_78;
    uStack_90 = uStack_70;
    plVar10 = (longlong *)0x0;
    plVar11 = plStack_68;
    goto LAB_23e2c4ee0;
  }
  *(undefined4 *)(plVar5 + 5) = 0xf9;
  plVar10 = (longlong *)FUN_23e91a870(param_1,lVar9);
  lVar9 = _DAT_23eeada88;
  if (plVar10 == (longlong *)0x0) {
    plStack_98 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    uStack_88 = 0xf9;
    uStack_90 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2c4ee0;
  }
  *(undefined4 *)(plVar5 + 5) = 0xfa;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar10,_DAT_23eead970,*(undefined8 *)(lVar9 + 0x18));
  if (plVar11 == (longlong *)0x0) {
    plStack_98 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = 0xfa;
    uStack_90 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = (longlong *)0x0;
    goto LAB_23e2c4ee0;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar9 = FUN_23e8f6e60();
  if (lVar9 == 0) {
    plVar13 = (longlong *)0x0;
    FUN_23e915740(param_1,&plStack_78,DAT_23eead9e8);
    uStack_88 = 0xfc;
    plStack_98 = plStack_78;
    uStack_90 = uStack_70;
    plVar12 = (longlong *)0x0;
    plVar11 = plStack_68;
    goto LAB_23e2c4ee0;
  }
  *(undefined4 *)(plVar5 + 5) = 0xfc;
  plVar12 = (longlong *)FUN_23e914090(param_1,lVar9,plVar2);
  if (plVar12 == (longlong *)0x0) {
    plStack_98 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = 0xfc;
    uStack_90 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2c4ee0;
  }
  plVar13 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eead9b8);
  plVar11 = _DAT_23eeadca8;
  if (plVar13 == (longlong *)0x0) {
    plStack_98 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = 0xfd;
    uStack_90 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2c4ee0;
  }
  lVar9 = *(longlong *)(param_1 + 0x10);
  plVar14 = *(longlong **)(lVar9 + 0xe28);
  if (plVar14 == (longlong *)0x0) {
    plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
  }
  else {
    lVar4 = plVar14[3];
    *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
    *(longlong *)(lVar9 + 0xe28) = lVar4;
    *plVar14 = 1;
  }
  pcVar8 = _PyRuntime_exref;
  *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
  lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
  lVar4 = plVar14[-1];
  puVar16 = *(undefined8 **)(lVar9 + 8);
  *puVar16 = plVar14 + -2;
  plVar14[-2] = lVar9;
  plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar16;
  *(longlong **)(lVar9 + 8) = plVar14 + -2;
  *plVar11 = *plVar11 + 1;
  plVar14[3] = (longlong)plVar11;
  plVar11 = (longlong *)FUN_23e8f7100();
  uVar6 = DAT_23ed6cd28;
  if (plVar11 == (longlong *)0x0) {
    FUN_23e915740(param_1,&plStack_78,DAT_23eeadb50);
    plStack_98 = plStack_78;
    uStack_90 = uStack_70;
    plVar11 = plStack_68;
  }
  else {
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
        DAT_23ed6a4c0 = plVar15;
        goto LAB_23e2c4922;
      }
LAB_23e2c5767:
      PyErr_PrintEx(0);
      Py_Exit(1);
LAB_23e2c577a:
      plStack_98 = *(longlong **)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      uStack_88 = 0x104;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_90 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2c4ee0;
    }
LAB_23e2c4922:
    uStack_70 = uVar6;
    plStack_78 = plVar11;
    lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
    if (lVar9 != 0) {
      plVar14[4] = lVar9;
      plVar11 = _DAT_23eeadcb0;
      *_DAT_23eeadcb0 = *_DAT_23eeadcb0 + 1;
      plVar14[5] = (longlong)plVar11;
      plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar11 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_90 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
          uStack_88 = 0xfd;
          plVar13 = (longlong *)0x0;
        }
        else {
          plVar13 = (longlong *)0x0;
          uStack_88 = 0xfd;
        }
        goto LAB_23e2c4ee0;
      }
      *(undefined4 *)(plVar5 + 5) = 0xfd;
      plVar14 = (longlong *)FUN_23e914090(param_1,plVar13);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar14 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = 0xfd;
        uStack_90 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e2c4ee0;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      lVar9 = FUN_23e8f6e60();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,&plStack_78,DAT_23eead9e8);
        uStack_88 = 0xff;
        plStack_98 = plStack_78;
        uStack_90 = uStack_70;
        plVar13 = (longlong *)0x0;
        plVar11 = plStack_68;
        goto LAB_23e2c4ee0;
      }
      *(undefined4 *)(plVar5 + 5) = 0xff;
      plVar13 = (longlong *)FUN_23e914090(param_1,lVar9,plVar3);
      if (plVar13 == (longlong *)0x0) {
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        uStack_88 = 0xff;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_90 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e2c4ee0;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23eead9b8);
      plVar11 = _DAT_23eeadca8;
      if (plVar14 == (longlong *)0x0) {
LAB_23e2c55b0:
        plStack_98 = *(longlong **)(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x70);
        uStack_88 = 0x100;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_90 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        lVar9 = *(longlong *)(param_1 + 0x10);
        plVar15 = *(longlong **)(lVar9 + 0xe28);
        if (plVar15 == (longlong *)0x0) {
          plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
        }
        else {
          lVar4 = plVar15[3];
          *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
          *(longlong *)(lVar9 + 0xe28) = lVar4;
          *plVar15 = 1;
        }
        pcVar8 = _PyRuntime_exref;
        *(undefined1 (*) [16])(plVar15 + 4) = (undefined1  [16])0x0;
        lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
        lVar4 = plVar15[-1];
        puVar16 = *(undefined8 **)(lVar9 + 8);
        *puVar16 = plVar15 + -2;
        plVar15[-2] = lVar9;
        plVar15[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar16;
        *(longlong **)(lVar9 + 8) = plVar15 + -2;
        *plVar11 = *plVar11 + 1;
        plVar15[3] = (longlong)plVar11;
        plVar11 = (longlong *)FUN_23e8f73a0();
        uVar6 = DAT_23ed6cd28;
        if (plVar11 == (longlong *)0x0) {
          FUN_23e915740(param_1,&plStack_78,DAT_23eeadac0);
          plStack_98 = plStack_78;
          uStack_90 = uStack_70;
          plVar11 = plStack_68;
        }
        else {
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar17 == (longlong *)0x0) goto LAB_23e2c5767;
            *plVar17 = *plVar17 + 1;
            DAT_23ed6a4c0 = plVar17;
          }
          uStack_70 = uVar6;
          plStack_78 = plVar11;
          lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
          if (lVar9 != 0) {
            plVar15[4] = lVar9;
            plVar11 = _DAT_23eeadcb8;
            *_DAT_23eeadcb8 = *_DAT_23eeadcb8 + 1;
            plVar15[5] = (longlong)plVar11;
            plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (plVar11 == (longlong *)0x0) {
              plStack_98 = *(longlong **)(param_1 + 0x60);
              uStack_88 = 0x100;
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_90 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              lVar9 = *plVar14;
              *plVar14 = lVar9 + -1;
              if (lVar9 + -1 == 0) {
                (**(code **)(plVar14[1] + 0x30))();
                uStack_88 = 0x100;
              }
              goto LAB_23e2c4ee0;
            }
            *(undefined4 *)(plVar5 + 5) = 0x100;
            plVar15 = (longlong *)FUN_23e914090(param_1,plVar14);
            lVar9 = *plVar14;
            *plVar14 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plVar14[1] + 0x30))();
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (plVar15 != (longlong *)0x0) {
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              lVar9 = _DAT_23eead990;
              *(undefined4 *)(plVar5 + 5) = 0x101;
              plVar11 = (longlong *)
                        FUN_23e915840(param_1,plVar13,_DAT_23eead9f8,*(undefined8 *)(lVar9 + 0x18));
              if (plVar11 == (longlong *)0x0) {
                plStack_98 = *(longlong **)(param_1 + 0x60);
                plVar11 = *(longlong **)(param_1 + 0x70);
                uStack_88 = 0x101;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uStack_90 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e2c4ee0;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *(undefined4 *)(plVar5 + 5) = 0x103;
              plVar11 = (longlong *)FUN_23e915840(param_1,plVar10,_DAT_23eeada70,plVar12);
              if (plVar11 == (longlong *)0x0) {
                plStack_98 = *(longlong **)(param_1 + 0x60);
                plVar11 = *(longlong **)(param_1 + 0x70);
                uStack_88 = 0x103;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uStack_90 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e2c4ee0;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *(undefined4 *)(plVar5 + 5) = 0x104;
              uStack_70 = DAT_23ed6ccf8;
              plStack_78 = plVar13;
              plVar11 = (longlong *)FUN_23e954670(param_1,plVar10,_DAT_23eeada70,&plStack_78);
              if (plVar11 != (longlong *)0x0) {
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar11 = *(longlong **)(lVar9 + 0x28);
                plVar5 = (longlong *)plVar11[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
                *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                if (plVar5 != (longlong *)0x0) {
                  plVar11[2] = 0;
                  *plVar5 = *plVar5 + -1;
                  if (*plVar5 == 0) {
                    (**(code **)(plVar5[1] + 0x30))();
                  }
                }
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                lVar9 = *(longlong *)(param_1 + 0x10);
                plVar11[0xf] = 0;
                puVar16 = *(undefined8 **)(lVar9 + 0xe20);
                if (puVar16 == (undefined8 *)0x0) {
                  puVar16 = (undefined8 *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  uVar6 = puVar16[3];
                  *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
                  *(undefined8 *)(lVar9 + 0xe20) = uVar6;
                  *puVar16 = 1;
                }
                lVar9 = *(longlong *)
                         (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
                uVar6 = puVar16[-1];
                puVar7 = *(undefined8 **)(lVar9 + 8);
                *puVar7 = puVar16 + -2;
                puVar16[-2] = lVar9;
                puVar16[-1] = (ulonglong)((uint)uVar6 & 3) | (ulonglong)puVar7;
                *(undefined8 **)(lVar9 + 8) = puVar16 + -2;
                *plVar10 = *plVar10 + 1;
                puVar16[3] = plVar10;
                *plVar13 = *plVar13 + 1;
                puVar16[4] = plVar13;
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                lVar9 = *plVar1;
                *plVar1 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                }
                *plVar2 = *plVar2 + -1;
                if (*plVar2 == 0) {
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                }
                *plVar3 = *plVar3 + -1;
                if (*plVar3 != 0) {
                  return puVar16;
                }
                (**(code **)(plVar3[1] + 0x30))(plVar3);
                return puVar16;
              }
              goto LAB_23e2c577a;
            }
            goto LAB_23e2c55b0;
          }
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar11 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uStack_90 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        lVar9 = *plVar14;
        *plVar14 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))();
        }
        *plVar15 = *plVar15 + -1;
        uStack_88 = 0x100;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
          uStack_88 = 0x100;
        }
      }
      goto LAB_23e2c4ee0;
    }
    plStack_98 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_90 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    plVar13 = (longlong *)0x0;
    (**(code **)(plVar14[1] + 0x30))(plVar14);
    uStack_88 = 0xfd;
  }
  else {
    uStack_88 = 0xfd;
    plVar13 = (longlong *)0x0;
  }
LAB_23e2c4ee0:
  plVar14 = DAT_23ed6a4f8;
  if (plVar11 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar11 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar11;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar8 = _PyRuntime_exref;
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar9 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uStack_88;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar4 = plVar14[-1];
    puVar16 = *(undefined8 **)(lVar9 + 8);
    *puVar16 = plVar14 + -2;
    plVar14[-2] = lVar9;
    plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar16;
    *(longlong **)(lVar9 + 8) = plVar14 + -2;
    plVar15 = plVar14;
  }
  else {
    plVar15 = plVar11;
    if ((longlong *)plVar11[3] != plVar5) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar14[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      *(undefined4 *)((longlong)plVar14 + 0x24) = uStack_88;
      pcVar8 = _PyRuntime_exref;
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
      lVar4 = plVar14[-1];
      puVar16 = *(undefined8 **)(lVar9 + 8);
      *puVar16 = plVar14 + -2;
      plVar14[-2] = lVar9;
      plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar16;
      lVar4 = *plVar11;
      *(longlong **)(lVar9 + 8) = plVar14 + -2;
      plVar14[2] = (longlong)plVar11;
      plVar15 = plVar14;
      if (lVar4 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar5,"oooooo",plVar1,plVar2,plVar3,plVar10,plVar12,plVar13);
  if (_DAT_23eeb0318 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eeb0318 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar9 + 0x28);
  plVar5 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11[0xf] = 0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  lVar9 = *plVar1;
  *plVar1 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,plStack_98,uStack_90,plVar15);
  return (undefined8 *)0x0;
}
