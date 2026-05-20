/* ===== 23e835350 workers.fishing.trigger_monitor:127 ===== */
/* ghidra_name=FUN_23e835350 entry=23e835350 size=6125 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e835350(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  code *pcVar9;
  char cVar10;
  int iVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  undefined4 uVar15;
  longlong lVar16;
  longlong *plVar17;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar12 = _DAT_23eede538;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  plVar4 = (longlong *)param_3[2];
  if (_DAT_23eede538 == (longlong *)0x0) {
LAB_23e835392:
    _DAT_23eede538 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede530,DAT_23eede5a0,0x18);
  }
  else {
    lVar13 = *_DAT_23eede538;
    if (1 < lVar13) {
      *_DAT_23eede538 = lVar13 + -1;
      goto LAB_23e835392;
    }
    if (_DAT_23eede538[2] != 0) {
      *_DAT_23eede538 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e835392;
    }
  }
  plVar5 = _DAT_23eede538;
  lVar13 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23eede538 + 9;
  lVar16 = *(longlong *)(lVar13 + 8);
  _DAT_23eede538[0xf] = lVar16;
  *(longlong **)(lVar13 + 8) = plVar12;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar8 = _DAT_23eedc040;
  *(undefined4 *)(plVar5 + 8) = 0;
  cVar10 = FUN_23e8d9ac0(plVar2,uVar8,plVar3);
  if (cVar10 == '\0') {
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x80;
    uVar8 = *(undefined8 *)(param_1 + 0x60);
    uVar6 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = DAT_23ed6a4f8;
    goto joined_r0x00023e835c94;
  }
  lVar13 = *(longlong *)(DAT_23eedbeb8 + 0x20);
  if (*(char *)(lVar13 + 10) == '\0') {
    plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc048);
    if (plVar12 == (longlong *)0x0) goto LAB_23e835a19;
    lVar16 = *plVar12;
LAB_23e8360f0:
    if (lVar16 == 0) goto LAB_23e835a19;
  }
  else {
    iVar11 = *(int *)(lVar13 + 0xc);
    if (*(int *)(lVar13 + 0xc) == 0) {
      *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
      iVar11 = DAT_23ec1552c;
      DAT_23ec1552c = DAT_23ec1552c + 1;
    }
    if (_DAT_23ec154f8 != iVar11) {
      _DAT_23ec154f8 = iVar11;
      _DAT_23eede4d8 = FUN_23e8cbd60(lVar13,_DAT_23eedc048,*(undefined8 *)(_DAT_23eedc048 + 0x18));
    }
    if (-1 < _DAT_23eede4d8) {
      lVar1 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
      lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eede4d8 * 0x10);
      if (lVar16 != 0) goto LAB_23e8354a0;
      _DAT_23eede4d8 = FUN_23e8cbd60(lVar13,_DAT_23eedc048,*(undefined8 *)(_DAT_23eedc048 + 0x18));
      if (-1 < _DAT_23eede4d8) {
        lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eede4d8 * 0x10);
        goto LAB_23e8360f0;
      }
    }
LAB_23e835a19:
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc048);
    if ((plVar12 == (longlong *)0x0) || (lVar16 = *plVar12, lVar16 == 0)) {
      FUN_23e915740(param_1,&uStack_68,_DAT_23eedc048);
      uVar15 = 0x81;
      plVar12 = plStack_58;
      uVar8 = uStack_68;
      uVar6 = uStack_60;
      plVar14 = DAT_23ed6a4f8;
      goto joined_r0x00023e835c94;
    }
  }
LAB_23e8354a0:
  *(undefined4 *)(plVar5 + 5) = 0x81;
  plVar12 = (longlong *)FUN_23e914090(param_1,lVar16,plVar4);
  if (plVar12 != (longlong *)0x0) {
    cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eedc050,plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (cVar10 != '\0') {
      iVar11 = FUN_23e913250(plVar3,_DAT_23eedc058);
      if (iVar11 == -1) {
        uVar8 = *(undefined8 *)(param_1 + 0x60);
        uVar15 = 0x84;
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar6 = *(undefined8 *)(param_1 + 0x68);
        plVar14 = DAT_23ed6a4f8;
        goto joined_r0x00023e835c94;
      }
      lVar13 = *(longlong *)(DAT_23eedbeb8 + 0x20);
      if (iVar11 == 1) {
        if (*(char *)(lVar13 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc060);
          if (plVar12 == (longlong *)0x0) goto LAB_23e836260;
          lVar13 = *plVar12;
LAB_23e836254:
          if (lVar13 == 0) goto LAB_23e836260;
        }
        else {
          iVar11 = *(int *)(lVar13 + 0xc);
          if (*(int *)(lVar13 + 0xc) == 0) {
            *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
            iVar11 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec154fc != iVar11) {
            _DAT_23ec154fc = iVar11;
            _DAT_23eede4e0 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc060,*(undefined8 *)(_DAT_23eedc060 + 0x18));
          }
          if (-1 < _DAT_23eede4e0) {
            lVar16 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
            if (*(longlong *)(lVar16 + 8 + _DAT_23eede4e0 * 0x10) != 0) goto LAB_23e835dbb;
            _DAT_23eede4e0 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc060,*(undefined8 *)(_DAT_23eedc060 + 0x18));
            if (-1 < _DAT_23eede4e0) {
              lVar13 = *(longlong *)(lVar16 + 8 + _DAT_23eede4e0 * 0x10);
              goto LAB_23e836254;
            }
          }
LAB_23e836260:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc060);
          if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eedc060);
            uVar15 = 0x85;
            plVar12 = plStack_58;
            uVar8 = uStack_68;
            uVar6 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
            goto joined_r0x00023e835c94;
          }
        }
LAB_23e835dbb:
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc068);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x85;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
        lVar13 = *(longlong *)(DAT_23eedbeb8 + 0x20);
        if (*(char *)(lVar13 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc070);
          if (plVar12 == (longlong *)0x0) goto LAB_23e836420;
          lVar13 = *plVar12;
LAB_23e836410:
          if (lVar13 == 0) goto LAB_23e836420;
        }
        else {
          iVar11 = *(int *)(lVar13 + 0xc);
          if (*(int *)(lVar13 + 0xc) == 0) {
            *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
            iVar11 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec15504 != iVar11) {
            _DAT_23ec15504 = iVar11;
            _DAT_23eede4f0 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc070,*(undefined8 *)(_DAT_23eedc070 + 0x18));
          }
          if (-1 < _DAT_23eede4f0) {
            lVar16 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
            if (*(longlong *)(lVar16 + 8 + _DAT_23eede4f0 * 0x10) != 0) goto LAB_23e835e43;
            _DAT_23eede4f0 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc070,*(undefined8 *)(_DAT_23eedc070 + 0x18));
            if (-1 < _DAT_23eede4f0) {
              lVar13 = *(longlong *)(lVar16 + 8 + _DAT_23eede4f0 * 0x10);
              goto LAB_23e836410;
            }
          }
LAB_23e836420:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc070);
          if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eedc070);
            uVar15 = 0x86;
            plVar12 = plStack_58;
            uVar8 = uStack_68;
            uVar6 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
            goto joined_r0x00023e835c94;
          }
        }
LAB_23e835e43:
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc078);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x86;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
        lVar13 = *(longlong *)(DAT_23eedbeb8 + 0x20);
        if (*(char *)(lVar13 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc080);
          if (plVar12 == (longlong *)0x0) goto LAB_23e8365c0;
          lVar13 = *plVar12;
LAB_23e8365aa:
          if (lVar13 == 0) goto LAB_23e8365c0;
        }
        else {
          iVar11 = *(int *)(lVar13 + 0xc);
          if (*(int *)(lVar13 + 0xc) == 0) {
            *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
            iVar11 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec15508 != iVar11) {
            _DAT_23ec15508 = iVar11;
            _DAT_23eede4f8 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc080,*(undefined8 *)(_DAT_23eedc080 + 0x18));
          }
          if (-1 < _DAT_23eede4f8) {
            lVar16 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
            if (*(longlong *)(lVar16 + 8 + _DAT_23eede4f8 * 0x10) != 0) goto LAB_23e835ecb;
            _DAT_23eede4f8 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc080,*(undefined8 *)(_DAT_23eedc080 + 0x18));
            if (-1 < _DAT_23eede4f8) {
              lVar13 = *(longlong *)(lVar16 + 8 + _DAT_23eede4f8 * 0x10);
              goto LAB_23e8365aa;
            }
          }
LAB_23e8365c0:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc080);
          if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eedc080);
            uVar15 = 0x87;
            plVar12 = plStack_58;
            uVar8 = uStack_68;
            uVar6 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
            goto joined_r0x00023e835c94;
          }
        }
LAB_23e835ecb:
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc088);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x87;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
        lVar13 = *(longlong *)(DAT_23eedbeb8 + 0x20);
        if (*(char *)(lVar13 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc090);
          if (plVar12 == (longlong *)0x0) goto LAB_23e836790;
          lVar13 = *plVar12;
LAB_23e836785:
          if (lVar13 == 0) goto LAB_23e836790;
        }
        else {
          iVar11 = *(int *)(lVar13 + 0xc);
          if (*(int *)(lVar13 + 0xc) == 0) {
            *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
            iVar11 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec1550c != iVar11) {
            _DAT_23ec1550c = iVar11;
            _DAT_23eede500 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc090,*(undefined8 *)(_DAT_23eedc090 + 0x18));
          }
          if (-1 < _DAT_23eede500) {
            lVar16 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
            if (*(longlong *)(lVar16 + 8 + _DAT_23eede500 * 0x10) != 0) goto LAB_23e835f53;
            _DAT_23eede500 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc090,*(undefined8 *)(_DAT_23eedc090 + 0x18));
            if (-1 < _DAT_23eede500) {
              lVar13 = *(longlong *)(lVar16 + 8 + _DAT_23eede500 * 0x10);
              goto LAB_23e836785;
            }
          }
LAB_23e836790:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc090);
          if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eedc090);
            uVar15 = 0x88;
            plVar12 = plStack_58;
            uVar8 = uStack_68;
            uVar6 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
            goto joined_r0x00023e835c94;
          }
        }
LAB_23e835f53:
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc098);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x88;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
        lVar13 = *(longlong *)(DAT_23eedbeb8 + 0x20);
        if (*(char *)(lVar13 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc0a0);
          if (plVar12 == (longlong *)0x0) goto LAB_23e8368cd;
          lVar13 = *plVar12;
LAB_23e8368c4:
          if (lVar13 == 0) goto LAB_23e8368cd;
        }
        else {
          iVar11 = *(int *)(lVar13 + 0xc);
          if (*(int *)(lVar13 + 0xc) == 0) {
            *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
            iVar11 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec15510 != iVar11) {
            _DAT_23ec15510 = iVar11;
            _DAT_23eede508 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0a0,*(undefined8 *)(_DAT_23eedc0a0 + 0x18));
          }
          if (-1 < _DAT_23eede508) {
            lVar16 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
            if (*(longlong *)(lVar16 + 8 + _DAT_23eede508 * 0x10) != 0) goto LAB_23e835fdb;
            _DAT_23eede508 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0a0,*(undefined8 *)(_DAT_23eedc0a0 + 0x18));
            if (-1 < _DAT_23eede508) {
              lVar13 = *(longlong *)(lVar16 + 8 + _DAT_23eede508 * 0x10);
              goto LAB_23e8368c4;
            }
          }
LAB_23e8368cd:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc0a0);
          if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eedc0a0);
            uVar15 = 0x89;
            plVar12 = plStack_58;
            uVar8 = uStack_68;
            uVar6 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
            goto joined_r0x00023e835c94;
          }
        }
LAB_23e835fdb:
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc0a8);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x89;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc0b0,DAT_23ed6cd28);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x8a;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
      }
      else {
        if (*(char *)(lVar13 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc0b8);
          if (plVar12 == (longlong *)0x0) goto LAB_23e836060;
          lVar13 = *plVar12;
LAB_23e836054:
          if (lVar13 == 0) goto LAB_23e836060;
        }
        else {
          iVar11 = *(int *)(lVar13 + 0xc);
          if (*(int *)(lVar13 + 0xc) == 0) {
            *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
            iVar11 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec15500 != iVar11) {
            _DAT_23ec15500 = iVar11;
            _DAT_23eede4e8 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0b8,*(undefined8 *)(_DAT_23eedc0b8 + 0x18));
          }
          if (-1 < _DAT_23eede4e8) {
            lVar16 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
            if (*(longlong *)(lVar16 + 8 + _DAT_23eede4e8 * 0x10) != 0) goto LAB_23e835581;
            _DAT_23eede4e8 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0b8,*(undefined8 *)(_DAT_23eedc0b8 + 0x18));
            if (-1 < _DAT_23eede4e8) {
              lVar13 = *(longlong *)(lVar16 + 8 + _DAT_23eede4e8 * 0x10);
              goto LAB_23e836054;
            }
          }
LAB_23e836060:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc0b8);
          if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eedc0b8);
            uVar15 = 0x8c;
            plVar12 = plStack_58;
            uVar8 = uStack_68;
            uVar6 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
            goto joined_r0x00023e835c94;
          }
        }
LAB_23e835581:
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc068);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x8c;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
        lVar13 = *(longlong *)(DAT_23eedbeb8 + 0x20);
        if (*(char *)(lVar13 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc0c0);
          if (plVar12 == (longlong *)0x0) goto LAB_23e836170;
          lVar13 = *plVar12;
LAB_23e836164:
          if (lVar13 == 0) goto LAB_23e836170;
        }
        else {
          iVar11 = *(int *)(lVar13 + 0xc);
          if (*(int *)(lVar13 + 0xc) == 0) {
            *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
            iVar11 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec15514 != iVar11) {
            _DAT_23ec15514 = iVar11;
            _DAT_23eede510 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0c0,*(undefined8 *)(_DAT_23eedc0c0 + 0x18));
          }
          if (-1 < _DAT_23eede510) {
            lVar16 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
            if (*(longlong *)(lVar16 + 8 + _DAT_23eede510 * 0x10) != 0) goto LAB_23e835609;
            _DAT_23eede510 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0c0,*(undefined8 *)(_DAT_23eedc0c0 + 0x18));
            if (-1 < _DAT_23eede510) {
              lVar13 = *(longlong *)(lVar16 + 8 + _DAT_23eede510 * 0x10);
              goto LAB_23e836164;
            }
          }
LAB_23e836170:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc0c0);
          if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eedc0c0);
            uVar15 = 0x8d;
            plVar12 = plStack_58;
            uVar8 = uStack_68;
            uVar6 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
            goto joined_r0x00023e835c94;
          }
        }
LAB_23e835609:
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc078);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x8d;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
        lVar13 = *(longlong *)(DAT_23eedbeb8 + 0x20);
        if (*(char *)(lVar13 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc0c8);
          if (plVar12 == (longlong *)0x0) goto LAB_23e836360;
          lVar13 = *plVar12;
LAB_23e836352:
          if (lVar13 == 0) goto LAB_23e836360;
        }
        else {
          iVar11 = *(int *)(lVar13 + 0xc);
          if (*(int *)(lVar13 + 0xc) == 0) {
            *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
            iVar11 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec15518 != iVar11) {
            _DAT_23ec15518 = iVar11;
            _DAT_23eede518 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0c8,*(undefined8 *)(_DAT_23eedc0c8 + 0x18));
          }
          if (-1 < _DAT_23eede518) {
            lVar16 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
            if (*(longlong *)(lVar16 + 8 + _DAT_23eede518 * 0x10) != 0) goto LAB_23e835691;
            _DAT_23eede518 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0c8,*(undefined8 *)(_DAT_23eedc0c8 + 0x18));
            if (-1 < _DAT_23eede518) {
              lVar13 = *(longlong *)(lVar16 + 8 + _DAT_23eede518 * 0x10);
              goto LAB_23e836352;
            }
          }
LAB_23e836360:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc0c8);
          if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eedc0c8);
            uVar15 = 0x8e;
            plVar12 = plStack_58;
            uVar8 = uStack_68;
            uVar6 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
            goto joined_r0x00023e835c94;
          }
        }
LAB_23e835691:
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc088);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x8e;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
        lVar13 = *(longlong *)(DAT_23eedbeb8 + 0x20);
        if (*(char *)(lVar13 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc0d0);
          if (plVar12 == (longlong *)0x0) goto LAB_23e8364f0;
          lVar13 = *plVar12;
LAB_23e8364da:
          if (lVar13 == 0) goto LAB_23e8364f0;
        }
        else {
          iVar11 = *(int *)(lVar13 + 0xc);
          if (*(int *)(lVar13 + 0xc) == 0) {
            *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
            iVar11 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec1551c != iVar11) {
            _DAT_23ec1551c = iVar11;
            _DAT_23eede520 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0d0,*(undefined8 *)(_DAT_23eedc0d0 + 0x18));
          }
          if (-1 < _DAT_23eede520) {
            lVar16 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
            if (*(longlong *)(lVar16 + 8 + _DAT_23eede520 * 0x10) != 0) goto LAB_23e835719;
            _DAT_23eede520 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0d0,*(undefined8 *)(_DAT_23eedc0d0 + 0x18));
            if (-1 < _DAT_23eede520) {
              lVar13 = *(longlong *)(lVar16 + 8 + _DAT_23eede520 * 0x10);
              goto LAB_23e8364da;
            }
          }
LAB_23e8364f0:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc0d0);
          if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eedc0d0);
            uVar15 = 0x8f;
            plVar12 = plStack_58;
            uVar8 = uStack_68;
            uVar6 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
            goto joined_r0x00023e835c94;
          }
        }
LAB_23e835719:
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc098);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x8f;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
        lVar13 = *(longlong *)(DAT_23eedbeb8 + 0x20);
        if (*(char *)(lVar13 + 10) == '\0') {
          plVar12 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc0d8);
          if (plVar12 == (longlong *)0x0) goto LAB_23e836690;
          lVar13 = *plVar12;
LAB_23e83667a:
          if (lVar13 == 0) goto LAB_23e836690;
        }
        else {
          iVar11 = *(int *)(lVar13 + 0xc);
          if (*(int *)(lVar13 + 0xc) == 0) {
            *(int *)(lVar13 + 0xc) = DAT_23ec1552c;
            iVar11 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec15520 != iVar11) {
            _DAT_23ec15520 = iVar11;
            _DAT_23eede528 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0d8,*(undefined8 *)(_DAT_23eedc0d8 + 0x18));
          }
          if (-1 < _DAT_23eede528) {
            lVar16 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
            if (*(longlong *)(lVar16 + 8 + _DAT_23eede528 * 0x10) != 0) goto LAB_23e8357a1;
            _DAT_23eede528 =
                 FUN_23e8cbd60(lVar13,_DAT_23eedc0d8,*(undefined8 *)(_DAT_23eedc0d8 + 0x18));
            if (-1 < _DAT_23eede528) {
              lVar13 = *(longlong *)(lVar16 + 8 + _DAT_23eede528 * 0x10);
              goto LAB_23e83667a;
            }
          }
LAB_23e836690:
          plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc0d8);
          if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
            FUN_23e915740(param_1,&uStack_68,_DAT_23eedc0d8);
            uVar15 = 0x90;
            plVar12 = plStack_58;
            uVar8 = uStack_68;
            uVar6 = uStack_60;
            plVar14 = DAT_23ed6a4f8;
            goto joined_r0x00023e835c94;
          }
        }
LAB_23e8357a1:
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc0a8);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x90;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc0b0,_DAT_23eedc0e0);
        if (cVar10 == '\0') {
          uVar8 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = 0x91;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = DAT_23ed6a4f8;
          goto joined_r0x00023e835c94;
        }
      }
      *(undefined4 *)(plVar5 + 5) = 0x94;
      plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar2,_DAT_23eedc0e8);
      if (plVar12 != (longlong *)0x0) {
        cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc0f0,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (cVar10 != '\0') {
          cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc0f8,DAT_23ed6ccf0);
          if (cVar10 == '\0') {
            uVar8 = *(undefined8 *)(param_1 + 0x60);
            uVar15 = 0x97;
            plVar12 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar6 = *(undefined8 *)(param_1 + 0x68);
            plVar14 = DAT_23ed6a4f8;
          }
          else {
            lVar13 = FUN_23e8db3c0();
            if (lVar13 == 0) {
              FUN_23e915740(param_1,&uStack_68,_DAT_23eedc100);
              uVar15 = 0x98;
              plVar12 = plStack_58;
              uVar8 = uStack_68;
              uVar6 = uStack_60;
              plVar14 = DAT_23ed6a4f8;
            }
            else {
              *(undefined4 *)(plVar5 + 5) = 0x98;
              plVar12 = (longlong *)FUN_23e91bfe0(param_1,lVar13);
              if (plVar12 != (longlong *)0x0) {
                cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc108,plVar12);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if (cVar10 != '\0') {
                  cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc110,DAT_23ed6ccf0);
                  lVar13 = DAT_23ed6cce8;
                  if (cVar10 == '\0') {
                    uVar8 = *(undefined8 *)(param_1 + 0x60);
                    uVar15 = 0x99;
                    plVar12 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar6 = *(undefined8 *)(param_1 + 0x68);
                    plVar14 = DAT_23ed6a4f8;
                  }
                  else {
                    lVar16 = *(longlong *)(param_1 + 0x10);
                    plVar12 = *(longlong **)(DAT_23ed6cce8 + 0x20);
                    iVar11 = *(int *)(lVar16 + 0x1410);
                    *plVar12 = *plVar12 + 1;
                    if (iVar11 == 0) {
                      plVar14 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
                      plVar12 = *(longlong **)(lVar13 + 0x20);
                    }
                    else {
                      iVar11 = iVar11 + -1;
                      *(int *)(lVar16 + 0x1410) = iVar11;
                      plVar14 = *(longlong **)(lVar16 + 0x1190 + (longlong)iVar11 * 8);
                      *plVar14 = 1;
                    }
                    lVar13 = *(longlong *)(lVar13 + 0x28);
                    plVar14[2] = 0;
                    plVar14[3] = 1;
                    plVar14[4] = (longlong)plVar12;
                    plVar14[5] = lVar13;
                    cVar10 = FUN_23e8d9ac0(plVar2,_DAT_23eedc118,plVar14);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if (cVar10 != '\0') {
                      lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                      plVar12 = *(longlong **)(lVar13 + 0x28);
                      plVar5 = (longlong *)plVar12[2];
                      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                           *(undefined8 *)(lVar13 + 0x30);
                      *(undefined4 *)(plVar12 + 8) = 0xffffffff;
                      if (plVar5 != (longlong *)0x0) {
                        plVar12[2] = 0;
                        *plVar5 = *plVar5 + -1;
                        if (*plVar5 == 0) {
                          (**(code **)(plVar5[1] + 0x30))();
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
                        (**(code **)(plVar2[1] + 0x30))(plVar2);
                      }
                      *plVar3 = *plVar3 + -1;
                      if (*plVar3 == 0) {
                        (**(code **)(plVar3[1] + 0x30))(plVar3);
                      }
                      *plVar4 = *plVar4 + -1;
                      if (*plVar4 != 0) {
                        return pcVar9;
                      }
                      (**(code **)(plVar4[1] + 0x30))(plVar4);
                      return pcVar9;
                    }
                    uVar8 = *(undefined8 *)(param_1 + 0x60);
                    uVar15 = 0x9c;
                    plVar12 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar6 = *(undefined8 *)(param_1 + 0x68);
                    plVar14 = DAT_23ed6a4f8;
                  }
                  goto joined_r0x00023e835c94;
                }
              }
              uVar8 = *(undefined8 *)(param_1 + 0x60);
              uVar15 = 0x98;
              plVar12 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar6 = *(undefined8 *)(param_1 + 0x68);
              plVar14 = DAT_23ed6a4f8;
            }
          }
          goto joined_r0x00023e835c94;
        }
      }
      uVar8 = *(undefined8 *)(param_1 + 0x60);
      uVar15 = 0x94;
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar6 = *(undefined8 *)(param_1 + 0x68);
      plVar14 = DAT_23ed6a4f8;
      goto joined_r0x00023e835c94;
    }
  }
  plVar12 = *(longlong **)(param_1 + 0x70);
  uVar8 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar15 = 0x81;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar6 = *(undefined8 *)(param_1 + 0x68);
  plVar14 = DAT_23ed6a4f8;
joined_r0x00023e835c94:
  DAT_23ed6a4f8 = plVar14;
  if (plVar12 == (longlong *)0x0) {
    if (plVar14 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar14;
      *plVar14 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar13 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar15;
    lVar13 = *(longlong *)(lVar13 + 0x10);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(lVar13 + 0x2e8);
    lVar16 = plVar14[-1];
    puVar7 = *(undefined8 **)(lVar13 + 8);
    *puVar7 = plVar14 + -2;
    plVar14[-2] = lVar13;
    plVar14[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar7;
    *(longlong **)(lVar13 + 8) = plVar14 + -2;
    plVar17 = plVar14;
  }
  else {
    plVar17 = plVar12;
    if ((longlong *)plVar12[3] != plVar5) {
      if (plVar14 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar14;
        *plVar14 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar14[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      *(undefined4 *)((longlong)plVar14 + 0x24) = uVar15;
      pcVar9 = _PyRuntime_exref;
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar13 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar9 + 0x1f8) + 0x10) + 0x2e8);
      lVar16 = plVar14[-1];
      puVar7 = *(undefined8 **)(lVar13 + 8);
      *puVar7 = plVar14 + -2;
      plVar14[-2] = lVar13;
      plVar14[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar7;
      lVar16 = *plVar12;
      *(longlong **)(lVar13 + 8) = plVar14 + -2;
      plVar14[2] = (longlong)plVar12;
      plVar17 = plVar14;
      if (lVar16 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5e2be,plVar2,plVar3,plVar4);
  if (_DAT_23eede538 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eede538 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar13 + 0x28);
  plVar5 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar12[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
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
  FUN_23a33aa70(param_1,uVar8,uVar6,plVar17);
  return (code *)0x0;
}
